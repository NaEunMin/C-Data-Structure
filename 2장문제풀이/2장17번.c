/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int bc(int n, int k) {
	if (k == 0 || k == n) return 1;
	else return bc(n - 1, k - 1) + bc(n - 1, k);
}
int main()
{
    int binomial = bc(5,2);
    printf("%d", binomial);

    return 0;
}
/*
bc(5,2) => bc(4,1)+bc(4,2); 4+bc(4,2);

bc(4,1) => bc(3,0)+bc(3,1);   1+bc(3,1);   1+bc(2,0)+bc(2,1); 2+bc(2,1); 2+bc(1,0)+(1,1); 4

bc(4,2) => bc(3,1)+bc(3,2); 3+bc(3,2); 3+3; 6;
bc(3,1) => bc(2,0)+bc(2,1); 1+bc(2,1); 1+bc(1,0)+bc(1,1); 3;
bc(3,2) => bc(2,1)+bc(2,2); bc(2,1)+1; bc(1,0)+bc(1,1)+1; 3;
*/