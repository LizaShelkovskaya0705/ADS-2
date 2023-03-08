// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  else {
    return value * pown(value, n-1);
  }
}

uint64_t fact(uint16_t n) {
  if ((n == 1) || (n == 0)) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }    
}

double calcItem(double x, uint16_t n) {
  return (pown(x,n) / fact(n));
}

double expn(double x, uint16_t count) {
  double summa1 = 1.0;
  for (count; count > 0; count--) {
    summa1 += calcItem(x,count);
  }
  return summa1
}

double sinn(double x, uint16_t count) {
  double summa2 = 0;
  for (count; count > 0; count--) {
    summa2 += pown(-1, count-1) * calcItem(x, 2*count-1);
  }
  return summa2;
}

double cosn(double x, uint16_t count) {
  double summa3 = 0;
  for (count; count > 0; count--) {
    summa3 += pown(-1, count-1) * calcItem(x, 2*count-2);
  }
  return summa3;
}
