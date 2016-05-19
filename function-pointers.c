/*
 Function Pointers
 Pointers to a function!
 Based off: http://www.geeksforgeeks.org/function-pointer-in-c/
*/
void fun(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = &fun;
    
    //Equivalent pointer to a variable:
    //int val = 10;
    //void *int_ptr = &val;
    
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
    //void *int_ptr;
    //int_ptr = &val;
 
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
 
    return 0;
}
