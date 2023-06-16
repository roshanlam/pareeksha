#include "pareeksha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TESTS 100
#define MAX_TEST_NAME_LENGTH 100
#define MAX_ERROR_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_TEST_NAME_LENGTH];
    test_func function;
    setup_func setup;
    teardown_func teardown;
} Test;

Test tests[MAX_TESTS];
int test_count = 0;

void add_test(const char* name, test_func function, setup_func setup, teardown_func teardown) {
    if (test_count < MAX_TESTS) {
        Test test;
        snprintf(test.name, MAX_TEST_NAME_LENGTH, "%s", name);
        test.function = function;
        test.setup = setup;
        test.teardown = teardown;
        tests[test_count++] = test;
    }
}

void print_test_result(const char* test_name, bool success, const char* error_message) {
    printf("[%s] %s\n", success ? "PASS" : "FAIL", test_name);
    if (!success) {
        printf("  %s\n", error_message);
    }
}

int run_tests() {
    int failures = 0;

    for (int i = 0; i < test_count; i++) {
        Test test = tests[i];
        bool success = true;
        char error_message[MAX_ERROR_MESSAGE_LENGTH] = {0};

        if (test.setup) {
            test.setup();
        }

        test.function();

        if (test.teardown) {
            test.teardown();
        }

        print_test_result(test.name, success, error_message);

        if (!success) {
            failures++;
        }
    }

    return failures;
}

void expect(bool condition, const char* file, int line, const char* message) {
    if (!condition) {
        char error_message[MAX_ERROR_MESSAGE_LENGTH];
        snprintf(error_message, MAX_ERROR_MESSAGE_LENGTH, "Assertion failed: %s (File: %s, Line: %d)", message, file, line);
        printf("%s\n", error_message);
    }
}

