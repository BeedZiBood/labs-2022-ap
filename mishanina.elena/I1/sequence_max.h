#ifndef SEQUENCE_MAX_H
#define SEQUENCE_MAX_H

class Seq_after_max
{
public:
  Seq_after_max();
  void operator()(int num);
  int get_count_after_max() const;
private:
  int num;
  int max_num;
  int count_after_max;
};

#endif
