#ifndef MAX_SEQ_CNT_H
#define MAX_SEQ_CNT_H

struct MaxSeqRow
{
  unsigned int current_seq_row;
  unsigned int max_seq_row;
  int func_value;
  int func_previous_value;

  void operator()(int value);
};
#endif
