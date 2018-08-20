#include "include/minunit.h"

int foo = 6;
int bar = 4;

char* test_foo()
{
    mu_assert("foo != 6", foo == 6);
    return 0;
}

char* test_bat()
{
    mu_assert("bar != 5", bar == 5);
    return 0;
}


int main()
{
    mu_add_test(test_foo);
    mu_add_test(test_bat);
    const char *p = mu_run();
    if(p)
        puts(p);
}