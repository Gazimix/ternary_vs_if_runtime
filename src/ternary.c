#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define TYPE_TERNARY_STR	"ternary"
#define TYPE_IF_STR 		"if"
#define MODULUS_FACTOR		(10)
#define ADDITION_FACTOR		(1)

enum op_type {
	OP_TYPE_TERNARY,
	OP_TYPE_IF,
};


static inline int test_time_if(size_t number) {
	int i, test = 0;

	for (i = 0; i < number; ++i) {
		if (i % MODULUS_FACTOR == 0) continue;
		else test += ADDITION_FACTOR;
	}
	return test;
}


static inline int test_time_ternary(size_t number) {
	int i, test = 0;

	for (i = 0; i < number; ++i) {
		test += (i % MODULUS_FACTOR == 0) ? 0 : ADDITION_FACTOR;
	}
	return test;
}

int main(int argc, char *argv[]) {
	long double start = (long double)clock() / CLOCKS_PER_SEC, end;
	size_t number;
	int result;

	assert(argc == 3);

	number = strtol(argv[2], NULL, 10);
	printf("running program with op type: [%s] and number: %lu\n", argv[1], number);

	if (strcmp(TYPE_TERNARY_STR, argv[1]) == 0) {
		result = test_time_ternary(number);
	} else if (strcmp(TYPE_IF_STR, argv[1]) == 0) {
		result = test_time_if(number);
	} else {
		printf("entered an invalid operator type: %s, can only support %s or %s\n", argv[1], TYPE_TERNARY_STR, TYPE_IF_STR);
		return EXIT_FAILURE;
	}

	end = (long double)clock() / CLOCKS_PER_SEC;		

	printf("result was: %d, total time was: %Lf\n", result, end - start);

	return EXIT_SUCCESS;
}
