#ifndef LOCAL_MAX
#define LOCAL_MAX

struct LocalMax {
  void operator()(unsigned int currentValue);

    unsigned int previousValue;
    unsigned int beforePreviousValue;

    unsigned int count;
    unsigned int countV;
};

#endif
