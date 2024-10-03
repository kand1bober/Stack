
#ifdef DEBUG_STACK_FUNCS
    /******** macro definition of additional fields(in structure and other) ********/
    #define ON_DEBUG(...) __VA_ARGS__


    //=============== macro's of definition and prototype ===============
    #define STACK_CTOR(expr1, expr2)  StackCtor(expr1, expr2, const char* file, const char* func, const int line)
    #define STACK_DTOR(expr)          StackDtor(expr, const char* file, const char* func, const int line)
    #define STACK_PUSH(expr1, expr2)  StackPush(expr1, expr2, const char* file, const char* func, const int line)
    #define STACK_POP(expr)           StackPop(expr, const char* file, const char* func, const int line)

    #define STACK_RESIZE_UP(expr)     StackResizeUp(expr, const char* file, const char* func, const int line)
    #define STACK_RESIZE_DOWN(expr)   Stack_Resize_Down(expr, const char* file, const char* func, const int line)
    //====================================================


    /******** macro's of calling's of function's********/
    #define STACK_CTOR_CALL(expr1, expr2)  StackCtor(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_DTOR_CALL(expr)          StackDtor(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_PUSH_CALL(expr1, expr2)  StackPush(expr1, expr2, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_POP_CALL(expr)           StackPop(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)

    #define STACK_RESIZE_UP_CALL(expr)     StackResizeUp(expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)
    #define STACK_RESIZE_DOWN_CALL(expr)   Stack_Resize_Down(expr,  __FILE__, __PRETTY_FUNCTION__, __LINE__)
    //===================================================


    //==========================================
    #define CHECK_VALIDITY                     \
    if (!StackValidity(stk, file, func, line)) \
    {                                          \
        StackDump(stk, file, func, line);      \
    }                                          \
    else;
    //==========================================

#else
    //======== macro definition of additional fields(in structure and other)
    #define ON_DEBUG(...)

    //======== macro's of definition and prototype===========
    #define STACK_CTOR(expr1, expr2)  StackCtor(expr1, expr2)
    #define STACK_DTOR(expr)          StackDtor(expr)
    #define STACK_PUSH(expr1, expr2)  StackPush(expr1, expr2)
    #define STACK_POP(expr)           StackPop(expr)

    #define STACK_RESIZE_UP(expr)     StackResizeUp(expr)
    #define STACK_RESIZE_DOWN(expr)   Stack_Resize_Down(expr)
    //=======================================================


    //======= macro's of calling's of function's========
    #define STACK_CTOR_CALL(expr1, expr2)  StackCtor(expr1, expr2)
    #define STACK_DTOR_CALL(expr)          StackDtor(expr)
    #define STACK_PUSH_CALL(expr1, expr2)  StackPush(expr1, expr2)
    #define STACK_POP_CALL(expr)           StackPop(expr)

    #define STACK_RESIZE_UP_CALL(expr)     StackResizeUp(expr)
    #define STACK_RESIZE_DOWN_CALL(expr)   Stack_Resize_Down(expr)
    //=====================================================


    //==========================================
    #define CHECK_VALIDITY
    //==========================================

#endif
