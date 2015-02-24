#include <stdio.h>
#include <time.h>
#include <gmp.h>

#define ARRAY_LENGTH 500

typedef mpz_t arr_t;

void printarr(arr_t *arr);

void fibber(arr_t *arr);

int main() {
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	int t = ts.tv_nsec;
	arr_t p [ARRAY_LENGTH];
	fibber(p);	
	clock_gettime(CLOCK_REALTIME, &ts);
	t = ts.tv_nsec - t;
	printarr(p);
	printf("\ntime elapsed: %dns\n", t);
	return 0;
}

void printarr(arr_t *arr) {
	int i;
	for (i = 0; i < ARRAY_LENGTH; ++i) {
		gmp_printf("%Zd \n", arr[i]);
	}
	printf("\n");
}

void fibber(arr_t *arr) {
	arr_t *r = arr;
	int i;	
	for (i = 0; i < ARRAY_LENGTH; ++i, ++r) {
		mpz_init(*r);
		if (i > 1)
			mpz_add(*r, *(r - 1),  *(r - 2));
		else
			mpz_set_si(*r,  1);

	}
}
