#include "damm.h"

#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double diff(double start, double end) {
  double temp;
  if ((end - start) < 0) {
  	return 1000000000 + end - start;
  } else {
		return end - start;
  }
  return temp;
}

int _dammDigit(const char* data) {
	return digit(data, strlen(data));
}

int main() {
	printf("\nRunning unit tests\n");

	// expectations

	if (_dammDigit("") != 0) {
		return 1;
	}
	if (_dammDigit("00123014764700968325") != 0) {
		return 1;
	}

	if (_dammDigit("1234567812345678") != 5) {
		return 1;
	}

	if (_dammDigit("ZZZZ") != -1) {
		return 1;
	}

	printf("passed");

	// micro benchmark

	int i;
	unsigned int times = 20000000;//-1u;

	printf("\n\nRunning benchmark %lu times \n", (unsigned long) times);

	double total_time = 0;
	double clock_cost = 0;

	struct timespec t1;
	struct timespec t2;

	for (i = 0; i < times; ++i) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		clock_cost += diff(t1.tv_nsec, t2.tv_nsec);

		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		_dammDigit("1234567812345678");
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		total_time += diff(t1.tv_nsec, t2.tv_nsec);
	}

	printf("median: %f ns/op\n\n", ((total_time-clock_cost)/times));

	return 0;
}