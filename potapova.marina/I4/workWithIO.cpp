#include "workWithIO.h"

void inputMatrix(size_t& count_rows,
                 size_t& count_cols,
                 std::int64_t*& matrix,
                 const char* const file_name)
{
  std::ifstream in(file_name);

  if (!in.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    std::exit(1);
  }

  if (!(in >> count_rows >> count_cols))
  {
    std::cerr << "Input error " << '\n';
    std::exit(1);
  }

  try
  {
    matrix = new std::int64_t[count_rows * count_cols];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation error " << e.what() << '\n';
    std::exit(1);
  }

	for (std::int64_t* cur_elem_ptr = matrix;
		cur_elem_ptr < matrix + count_rows * count_cols;
		++cur_elem_ptr)
	{
		if (!(in >> *cur_elem_ptr))
		{
			std::cerr << "Input error " << '\n';
    	std::exit(1);
		}
	}
}

void printCountOfSaddlePoints(size_t сount_of_saddle_points,
                              const char* file_name)
{
	std::ofstream out(file_name);

	if (!out.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    std::exit(1);
  }

	out << сount_of_saddle_points << '\n';
}
