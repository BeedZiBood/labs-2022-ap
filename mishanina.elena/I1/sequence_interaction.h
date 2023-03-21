#ifndef SEQUENCE_INTERACTION_H
#define SEQUENCE_INTERACTION_H

class Suitable_seq
{
public:
  Suitable_seq();
  void operator()(int num);
  int get_count_of_elements() const;
private:
  int num;
  int previous_num;
  int current_num;
  int next_num;
  int count_of_elements;
};

#endif
