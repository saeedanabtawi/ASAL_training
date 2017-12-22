#include <stdio.h>
#include <stdlib.h>



/*
    A function to compare two strings  , and return if euqal, greater ,or smaller .
*/
int strcmp(char* string , char* other_string)
{
  for (int i = 0; string[i]!='\0' && other_string[i]!='\0'; ++i){
    if (string[i] > other_string[i]){
      return 1;
    }else if(string[i] <  other_string[i]){
      return -1;
    }
  }
  if ( string[i]=='\0' && other_string[i]!='\0'){
    return -1;
  }else if(string[i] !='\0' && other_string[i]=='\0'){
    return 1;
  }
  return 0;
}



int main()
{
    printf(" test compare function :  %d\n",strcmp("saeed anabtawi","saeed anabtawi") );
    //display();

    return 0;         
}