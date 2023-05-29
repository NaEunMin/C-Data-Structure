/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
array[n-1] = 0; 맨 뒤에 있었던 요소 앞으로 한칸씩 이동해서 사라질 것이다.
*/

#include <stdio.h>

void insert(int array[], int loc){
    for(int i=loc; i<n; i++){
        array[i] = array[i+1];
    }
    array[n-1] = 0;
    items--;
}
int main()
{
    
    

    return 0;
}
