#include <stdio.h>
#include <stdlib.h>


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
    Tree methods 
*/

struct node
{
    char* number;
    char* name;
    struct node* left;
    struct node* right;
};



/*
     A  function to create a new BST node
*/
struct node *newNode(char* number, char* name)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->number = number;
    temp->name = name;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
  
/*
    A  function to do print the contant s of BST
*/
void printTree(struct node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("\n");
        print(root->number);
        printf(" ");
        print(root->name);
        printf("\n");
        printTree(root->right);
    }
}
  
/* 
    input:  pointer to node 
    A  function to insert a new node with given number in BST
    output: return node 
*/
struct node* insert(struct node* root, char* number,char* name)
{
    /* If the tree is empty, return a new node */
    if (root == NULL) return newNode(number,name);
 
    /* Otherwise, recur down the tree */
    if (strcmp(number,root->number) == -1)
        root->left  = insert(root->left, number,name);
    else if (strcmp(number,root->number) == 1)
        root->right = insert(root->right, number,name);   
 
    /* return the (unchanged) node pointer */
    return root;
}


/*  
    input :  pointer to node , number 
    A function to search a given number in a given BST
    ouput : return node 
*/
struct node* search(struct node* root, char* number)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcmp(root->number,number) == 0 )
       return root;
    
    // Key is greater than root's key
    if (strcmp(number , root->number) == 1)
       return search(root->right, number);
 
    // Key is smaller than root's key
    return search(root->left, number);
}


// print a all pobile number after firs squecnece as partions  
struct node* advanced_sreach(struct node* root , char* number)
{
    
}

  
// Driver Program to test above functions
int main()
{
    struct node *root = NULL;
    root = insert(root, "0598034909","saeed anabtawi");
    insert(root, "0592303003","kahled anabtawi");
    insert(root, "0346895002","fadei anabtawi");
    insert(root, "9805220160","samer anabtawi");
    insert(root, "6540650134","omar anabtawi");
    insert(root, "5341056103","mohhmmad anabtawi");
    insert(root, "0132018038","sameer anabtawi");

    // print  BST
    printTree(root);

    struct node* serach_result =  search(root,"9805220160");
    if(serach_result){
        print(serach_result->name);
    }else{
        print("Not found");
    }




  
    return 0;
}