#include<stdio.h>
#include<stdlib.h>
#include"abhi.h"

int sum(int a, int b)
{
    return a+b;
}


int main()
{
    int a = 0, b = 0;
    printf("Enter any value ");
    scanf("%d",&a);
    printf("Enter another number ");
    scanf("%d",&b);
    printf("The sum of these numbers is: %d\n", sum(a,b));
    printf("The multiplication of these numbers is: %d", mul(a,b));
    
    return 0;
}