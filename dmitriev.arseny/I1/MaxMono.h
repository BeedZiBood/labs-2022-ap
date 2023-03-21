#ifndef MAXMONO_H
#define MAXMONO_H

struct MaxMono
{
  unsigned int getResult() const;

  void operator()(int current);
private:
  unsigned int k = 0;
  int previous = 0;
  unsigned int quantity = 0;
};

#endif
