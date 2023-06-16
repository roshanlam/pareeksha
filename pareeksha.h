#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdbool.h>

typedef void (*test_func)(void);
typedef void (*setup_func)(void);
typedef void (*teardown_func)(void);

void add_test(const char* name, test_func function, setup_func setup, teardown_func teardown);
int run_tests();

void expect(bool condition, const char* file, int line, const char* message);

#define EXPECT(condition, message) expect((condition), __FILE__, __LINE__, (message))
#define ASSERT(condition, message) expect((condition), __FILE__, __LINE__, (message))

#endif  // TEST_FRAMEWORK_H

