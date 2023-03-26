#include "processInput.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include "compositeshape.hpp"
#include "concave.hpp"
#include "complexquad.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

struct StringSplitter {
  explicit StringSplitter(const std::string& str):
    str_(str)
  {}

  StringSplitter& operator>>(std::string& ostr)
  {
    if (str_.empty()) {
      throw std::runtime_error("Read error");
    }
    size_t spaceIndex = str_.find_first_of(' ');

    ostr = str_.substr(0, spaceIndex);
    if (spaceIndex == str_.npos) {
      str_.clear();
    } else {
      str_ = str_.substr(spaceIndex + 1);
    }
    return *this;
  }
  StringSplitter& operator>>(double& d)
  {
    std::string dstr = "";
    *this >> dstr;
    d = std::stod(dstr);
    return *this;
  }
  StringSplitter& operator>>(odintsov::point_t& p)
  {
    return *this >> p.x >> p.y;
  }

  private:
    std::string str_;
};

struct CommandProcessor {
  std::ostream& out;
  std::ostream& errstream;
  odintsov::CompositeShape& composite;

  void operator()(const std::string& commandLine)
  {
    StringSplitter in(commandLine);
    std::string command = "";
    in >> command;
    odintsov::Shape* shp = nullptr;
    try {
      if (command == "CONCAVE") {
        shp = readConcave(in);
      } else if (command == "COMPLEXQUAD") {
        shp = readComplexQuad(in);
      } else if (command == "RECTANGLE") {
        shp = readRectangle(in);
      }
    } catch (const std::exception& err) {
      delete shp;
      errstream << "Non-fatal error: " << err.what() << '\n';
      return;
    }
    if (shp != nullptr) {
      try {
        composite.push_back(shp);
        return;
      } catch (...) {
        delete shp;
        throw;
      }
    }
    if (command == "SCALE") {
      odintsov::point_t anchor;
      in >> anchor;
      double k = 1.0;
      in >> k;
      if (composite.size() == 0) {
        throw std::logic_error("no shapes to scale");
      }
      odintsov::outputCompositeShape(out, composite) << '\n';
      for (size_t i = 0; i < composite.size(); i++) {
        isoScale(composite[i], anchor, k);
      }
      odintsov::outputCompositeShape(out, composite) << '\n';
      scaled_ = true;
    } else {
      errstream << "Not a known command\n";
    }
  }
  CommandProcessor(std::ostream& out, std::ostream& errstream, odintsov::CompositeShape& composite):
    out(out),
    errstream(errstream),
    composite(composite),
    scaled_(false)
  {}

  bool hasScaled() {
    return scaled_;
  }

  private:
    bool scaled_;

    odintsov::Rectangle* readRectangle(StringSplitter& in)
    {
      odintsov::point_t p1, p2;
      in >> p1 >> p2;
      return new odintsov::Rectangle(p1, p2);
    }
    odintsov::ComplexQuad* readComplexQuad(StringSplitter& in)
    {
      odintsov::point_t p1, p2, p3, p4;
      in >> p1 >> p2 >> p3 >> p4;
      return new odintsov::ComplexQuad(p1, p2, p3, p4);
    }
    odintsov::Concave* readConcave(StringSplitter& in)
    {
      odintsov::point_t p1, p2, p3, p4;
      in >> p1 >> p2 >> p3 >> p4;
      return new odintsov::Concave(p1, p2, p3, p4);
    }
};

std::istream& odintsov::processInput(std::istream& in, std::ostream& out, CompositeShape& composite)
{
  CommandProcessor processCommand(out, std::cerr, composite);
  do {
    std::string commandLine = "";
    std::getline(in, commandLine);
    if (in.eof()) {
      break;
    }
    if (commandLine == "") {
      continue;
    }
    processCommand(commandLine);
  } while (!in.eof());
  if (!processCommand.hasScaled()) {
    throw std::runtime_error("no scaling occured");
  }
  return in;
}
