#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int NUM;
int INV(int N);
int main()
{
   printf("Digite um numero:");
   scanf("%d",&NUM);
   INV(NUM);
   return 0;
}
int INV(int N)
{
    if(N==0)
      return N;
     else
    {
     printf("%d", N % 10);
     N=N / 10;
     return INV(N);
    }
    return 0;
}    
