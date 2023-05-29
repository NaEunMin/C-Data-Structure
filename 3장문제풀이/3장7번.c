/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
->연산자는 포인터를 통하여 구조체멤버에 접근할때 사용
포인터를 사용하지 않을때는 .연산자를 통해 접근한다.
*/

#include <stdio.h>

typedef struct{
    float real;
    float imaginary;
} complex;

complex complex_add(complex c1, complex c2){
    complex c3;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    return c3;
}
int main()
{
    complex c1 = {3, 3};
    complex c2 = {4, 4};
    complex c3 = complex_add(c1, c2);
    printf("%lf + %lf*i", c3.real, c3.imaginary);
    

    return 0;
}
