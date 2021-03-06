int damm_digit(const char* data);
int damm_valid(const char* data);

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double diff(double start, double end) {
  if ((end - start) < 0) {
    return 1000000000 + end - start;
  } else {
  return end - start;
  }
  return 0;
}

void expectValid(char* a) {
  if (!damm_valid(a)) {
    printf("`%s` expected to be valid\n\n", a);
    exit(EXIT_FAILURE);
  }
}

void expectDigit(char* a, int digit) {
  int d = damm_digit(a);

  if (d != digit) {
    printf("`%s` expected digit %d but got %d instead\n\n", a, digit, d);
    exit(EXIT_FAILURE);
  }
}

int main() {
  // expectations
  expectDigit("", 0);
  expectDigit("00123014764700968325", 0);
  expectDigit("1234567812345678", 5);
  expectDigit("ZZZ", -1);

  expectValid("00123014764700968325");

  // micro benchmark
  int i;
  unsigned int times = 50000000;

  double total_time = 0;
  double clock_cost = 0;

  struct timespec t1;
  struct timespec t2;

  char* string = "00123014764700968325";

  clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
  for (i = 0; i < times; ++i) damm_digit(string);
  clock_gettime(CLOCK_MONOTONIC_RAW, &t2);

  printf("%d ps/op\n", (int)(1000*diff(t1.tv_nsec, t2.tv_nsec)/times));

  return 0;
}
