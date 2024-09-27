#ifdef ASSERTION
#define ASSERT(expr) \
        ((bool)expr) \
        ? printf("assertion passed\n")   \
        : printf("assertion failed file: %s, function: %s, file: %s", __FILE__, __LINE__, __PRETTY_FUNCTION__)  \

#else
    #define ASSERT(expr)

#endif

