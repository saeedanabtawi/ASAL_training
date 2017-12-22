#include <stdio.h>
#include <stdlib.h>





/*
  intput-vaule :index of number in fibi sequnce , int n
  fucntionalty: find number with same index in fibi seq
  output : return number , int n
*/
int fibi_itrative(int n)
{
  if (n == 0  || n == 1)
  {
    return 1;
  }

  int prev = 1;
  int current = 1;
  int next;

  for (int i = 2; i <= n; ++i)
   {
     
     next = current + prev;
     prev = current;
     current = next;
     //printf("%d\n", current );
   } 
   return next;
}


/*
  intput-vaule :index of number in fibi sequnce , int n
  fucntionalty: it build an array , sorte the frist and second emelent , then gernrate the seqence in the arrry
  output : return number , int n
*/
int fibi_dp(int n)
{

  if (n == 0  || n == 1)
  {
    return 1;
  }

  int len = n+1;
  int * arr = new int[len];
  arr[0] = 1;
  arr[1] = 1;

  for (int i = 2; i <= len; ++i)
   {
     arr[i] = arr[i-1] + arr[i-2];
   } 
   return arr[n];
}



int main()
{
  printf("%d\n",fibi_dp(100) );
  return 0;
}