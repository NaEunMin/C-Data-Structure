/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
strcpy()함수 사용 시 --> #include <string.h>
free(), exit()함수 사용 시--> #include<stdlib.h>
*** exit() *** 
--exit(0) : 성공적으로 프로그램이 종료됨(EXIT_SUCCESS)
--exit(1):  성공적으로 프로그램이 종료되지않음(EXIT_FAILURE)
현재의 C프로그램 자체를 완전종료하는 기능.
"모든 열려진 파일" 자동으로 닫음.
출력 버퍼속에 데이터가 있으면 그것을 쓰기 완료시킴.
즉, "모든 것을 정리 후 프로그램을 종료함"

#include <stdlib.h>를 작성하지않으면 결과가 제대로 출력되지 않음
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    char ch[20];
} Test;

int main()
{
    Test *t;
    t = (Test*)malloc(sizeof(Test));
    
    if(t==NULL)exit(1);
    t->num = 100;
    strcpy(t->ch, "Just testing");
  	printf("%d\n", t->num);
	  printf("%s", t->num);
	  free(t);
    

    return 0;
}
