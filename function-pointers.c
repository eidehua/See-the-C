/*
 Function Pointers
 Pointers to a function!
 Based off: http://www.geeksforgeeks.org/function-pointer-in-c/
*/
#include <stdio.h>

void fun(int a)
{
    printf("Value of a is %d\n", a);
}
void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}

int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = &fun; //we can remove the & here if we want ( A function’s name can also be used to get functions’ address)
    
    //Equivalent pointer to a variable:
    //int val = 10;
    //int *int_ptr = &val;
    
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
    //int *int_ptr;
    //int_ptr = &val;
 
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10); //and we can remove the * here if we want too ( A function’s name can also be used to get functions’ address)
 
   //example 2 -------------------------------------
   // fun_ptr_arr is an array of function pointers 
   //note they need same parameters
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;
 
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n");
    scanf("%d", &ch);
 
    if (ch > 2) return 0;
 
    (*fun_ptr_arr[ch])(a, b); //*fun_ptr_arr[2](a,b) = multiply(a,b)
    //dont need the * here???
    
    return 0;
}

