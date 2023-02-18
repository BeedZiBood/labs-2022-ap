#ifndef LONGEST_DESC_SEQ_H
#define LONGEST_DESC_SEQ_H

struct LongestDescSequence
{
  int longest_length = 0;
  int current_length = 0;
  int max_value = 0;

  void operator()(int value);
};

#endif
