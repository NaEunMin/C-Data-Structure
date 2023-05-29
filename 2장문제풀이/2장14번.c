/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

double div(int n) {
    if(n==1) return 1;
    else return div(n-1)+(double)1/n;
}

int main()
{
    double suum = div(5);
    printf("합은 %lf", suum);

    return 0;
}
/*
div(5) = div(4) + 1/5
div(4) = div(3) + 1/4
div(3) = div(2) + 1/3
div(2) = div(1) + 1/2
div(1) = 1
*/
