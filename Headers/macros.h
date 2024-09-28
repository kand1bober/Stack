#ifdef ASSERTION
#define ASSERT(expr) \
        ((bool)expr) \
        ? printf("assertion passed\n")   \
        : printf("assertion failed file: %s, function: %s, file: %s", __FILE__, __LINE__, __PRETTY_FUNCTION__)  \

#else
    #define ASSERT(expr)

#endif


#ifdef DEBUG_STACK_FUNCS
    // #define ON_DEBUG_FUNCS(file, func, line) , file, func, line

    /******** macro's of definition and prototype********/
    #define STACK_CTOR(expr1, expr2) (StackCtor(expr1, expr2, const char* file, const char* func, const int line))
    #define STACK_DTOR(expr) (StackDtor(expr, const char* file, const char* func, const int line))
    #define STACK_PUSH(expr1, expr2) (StackPush(expr1, expr2, const char* file, const char* func, const int line))
    #define STACK_POP(expr)  (StackPop(expr, const char* file, const char* func, const int line))

    /******** macro's of calling's of function's********/
    #define STACK_CTOR_CALL(expr1, expr2) StackCtor(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_DTOR_CALL(expr) StackDtor(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_PUSH_CALL(expr1, expr2) StackPush(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_POP_CALL(expr) StackPop(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)

#else
    // #define ON_DEBUG_FUNCS(file, func, line)

    /******** macro's of definition and prototype********/
    #define STACK_CTOR(expr1, expr2) (StackCtor(expr1, expr2))
    #define STACK_DTOR(expr) (StackDtor(expr))
    #define STACK_PUSH(expr1, expr2) (StackPush(expr1, expr2))
    #define STACK_POP(expr)  (StackPop(expr))

    /******** macro's of calling's of function's********/
    #define STACK_CTOR_CALL(expr1, expr2) StackCtor(expr1, expr2)
    #define STACK_DTOR_CALL(expr) StackDtor(expr)
    #define STACK_PUSH_CALL(expr1, expr2) StackPush(expr1, expr2)
    #define STACK_POP_CALL(expr) StackPop(expr)

#endif
