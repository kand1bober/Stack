#ifdef ASSERTION
#define ASSERT(expr) \
        ((bool)expr) \
        ? 0          \
        : 1          \

#else
    #define ASSERT(expr)

#endif


#ifdef DEBUG_STACK_FUNCS
    /******** macro definition of additional fields(in structure and other) ********/
    #define ON_DEBUG(expr) expr

    /******** macro's of definition and prototype********/
    #define STACK_CTOR(expr1, expr2)  StackCtor(expr1, expr2, const char* file, const char* func, const int line)
    #define STACK_DTOR(expr)          StackDtor(expr, const char* file, const char* func, const int line)
    #define STACK_PUSH(expr1, expr2)  StackPush(expr1, expr2, const char* file, const char* func, const int line)
    #define STACK_POP(expr)           StackPop(expr, const char* file, const char* func, const int line)

    // #define STACK_VALIDITY(expr)      StackValidity(expr)

    /******** macro's of calling's of function's********/
    #define STACK_CTOR_CALL(expr1, expr2)  StackCtor(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_DTOR_CALL(expr)          StackDtor(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_PUSH_CALL(expr1, expr2)  StackPush(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_POP_CALL(expr)           StackPop(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)

    // #define STACK_VALIDITY_CALL(expr1, expr2, expr3, expr4)      StackValidity(expr1, expr2, expr3, expr4)

#else
    /******** macro definition of additional fields(in structure and other) ********/
    #define ON_DEBUG(expr) expr

    /******** macro's of definition and prototype********/
    #define STACK_CTOR(expr1, expr2)  StackCtor(expr1, expr2)
    #define STACK_DTOR(expr)          StackDtor(expr)
    #define STACK_PUSH(expr1, expr2)  StackPush(expr1, expr2)
    #define STACK_POP(expr)           StackPop(expr)

    // #define STACK_VALIDITY(expr)

    /******** macro's of calling's of function's********/
    #define STACK_CTOR_CALL(expr1, expr2)  StackCtor(expr1, expr2)
    #define STACK_DTOR_CALL(expr)          StackDtor(expr)
    #define STACK_PUSH_CALL(expr1, expr2)  StackPush(expr1, expr2)
    #define STACK_POP_CALL(expr)           StackPop(expr)

    // #define STACK_VALIDITY_CALL(expr1, expr2, expr3, expr4)

#endif
