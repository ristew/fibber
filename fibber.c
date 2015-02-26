#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

#define ARRAY_LENGTH 500

typedef mpz_t arr_t;

/* prints all elements in array arr, of length len */
void printarr(arr_t *arr, int len);

/* calculates the Fibonacci sequence in array arr, to length len */
void fibber(arr_t *arr, int len);

int main() {
	int size;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	int t = ts.tv_nsec;
	arr_t *p;

	printf("Input length of sequence: ");
	scanf("%d", &size);
	
	if (!size) {
		/* default size of array */
		size = ARRAY_LENGTH;
	}
	p = (arr_t *) malloc(sizeof(arr_t) * (size_t) size);
	
	fibber(p, size);	
	
	clock_gettime(CLOCK_REALTIME, &ts);
	t = ts.tv_nsec - t;
	
	printarr(p, size);
	printf("\ntime elapsed: %dns\n", t);
	free(p);
	return 0;
}

void printarr(arr_t *arr, int len) {
	int i;
	for (i = 0; i < len; ++i) {
		gmp_printf("%Zd \n", arr[i]);
	}
	printf("\n");
}

void fibber(arr_t *arr, int len) {
	arr_t *r = arr;
	int i;
	for (i = 0; i < len; ++i, ++r) {
		mpz_init(*r);
		if (i > 1)
			mpz_add(*r, *(r - 1),  *(r - 2));
		else
			mpz_set_si(*r,  1);

	}
}
