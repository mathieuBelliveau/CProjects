#include <stdio.h>
#include <stdlib.h>


void pointerArithmetic(int * p1, int * p2);
int main()
{
    char * pp;
    int b = 99;
    pp = (char)&b;
    int a[] = {1,2,3,4,5,6,7,8,9,0,pp};


    int int1 = a[0];
    int int2 = a[10];
    int* answ = &int1;
    pointerArithmetic(&int1, &int2);
    printf("Answer says: %d", *answ);
    return 0;
}

void pointerArithmetic(int * p1, int* p2){
    *p1 = *p1 + *p2;
    //printf("Method: %d",  )
}
