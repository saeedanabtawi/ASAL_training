#include <stdio.h>
#include <stdlib.h>


#define SIZE 100

/*
    String methods 
*/

/*
 A fucntoin to print a string 
*/
void print(char *t) {
   if (*t == '\0')
      return;
   printf("%c", *t);
   print(++t);
}

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



/*

  hash table  data 

*/
struct DataItem {
   char* data;   // number  
   char* key;    // name
   struct DataItem* next; 
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;


  /*
     String hashin algrothim  
     input : string a  key ;
     return : hash index , int 
  */


int hashCode(char* key) {
  int sum = 0 ;  
  for (int i = 0; key[i]!='\0'; ++i)
      sum +=  key[i];
  return sum % SIZE;
}


/*

  Delete item form node

*/

struct DataItem *delete_hash(struct DataItem* item) {
  char* key = item->key;
  struct DataItem* current = hashArray[hashCode(key)];
  while(current != item){
    current =current->next;
  } 
  current = dummyItem; 
  return current;      
}

/*
  sreah for node , with same key 
  intput  : string key  
  output  : return DataItem  node
*/


struct DataItem *search(char* key) {
  struct DataItem* current =  hashArray[hashCode(key)];
  while(current->key != key){
    current =current->next;
  }
  return current;
}

/*
  
  A isert function to hash table 
  input key , data  

*/

void insert(char* key,char* data) {
   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   if (hashArray[hashCode(key)] == NULL) 
      hashArray[hashCode(key)] = item;

   struct DataItem* current = hashArray[hashCode(key)]; 
   while (current != NULL)
   {
     current = current->next;
   }

   current = item;
   return;  

}

void display() {
   int i = 0;
  
   for(i = 0; i<SIZE; i++) {
  
      if(hashArray[i] != NULL)
      {
        printf(" (");
        print(hashArray[i]->key);
        printf(",");
        print(hashArray[i]->data);
        printf(") ");
      }
      else
         printf(" ~ ");
   }
  
   printf("\n");
}




int main()
{
    insert("sameer anabtawi","0132018038");
    insert("ahamad anabtawi","9018390123");

    printf("\n");
    struct DataItem* search_result =  search("sameer anabtawi");
    if(search_result){
      print(search_result->data);
    }else{
      print("not found");
    }

    //display();

    return 0;         
}