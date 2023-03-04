#ifndef LOCALMAX
#define LOCALMAX

struct LocalMax {
  void operator()(unsigned int currentValue);

    unsigned int previousValue;
    unsigned int beforePreviousValue;

    unsigned int count;
};

#endif
