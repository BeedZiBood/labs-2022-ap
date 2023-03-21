#include "sequence.h"

void CounterPythagoreanTriplets::operator()(int currval) {
  if (currval) {
    if ((predpredval * predpredval + predval * predval) == currval * currval) {
      count += 1;
    }
    predpredval = predval;
    predval = currval;
  }
}

void CounterSignChange::operator()(int currval){
  if (currval) {
    if ((predval < 0 ) && (currval > 0)) {
      count += 1;
    } else if ((predval > 0) && (currval < 0)) {
      count += 1;
    }
    predval = currval;
  }
}

