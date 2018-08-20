#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
#define mu_add_test(func) _mu_add_test(__FILE__, #func, func)

typedef char* (*test_callback)(void);
void _mu_add_test(const char *file, const char *func_name, test_callback func);
const char *mu_run();
