#ifndef CNT_PREV_DEVISOR_H
#define CNT_PREV_DEVISOR_H

struct CntDevPrev
{
  unsigned int cnt_dev;
  int dev_func_val;
  int dev_func_prev_val;

  void operator()(int value);
};
#endif
