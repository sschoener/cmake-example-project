#include <stdio.h>
#include <stdbool.h>
#include "minunit.h"

#include "library.h"

int tests_run = 0;

static char* all_tests() {
    mu_assert("TestFunction should return 0", TestFunction() == 0);
    return 0;
}

int main(/*int argc, char** argv*/)
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}