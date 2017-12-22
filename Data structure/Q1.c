#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key;
  struct node* next;
};

/* init node */
node* init_node(int key)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->key = key;
  return new_node;
}

/* To check if the link-list is empty or not. */
bool is_empty(struct node* head)
{
  if (head == NULL){
    return true;
  }else{
    return false;
  }
}


int pop(struct node** head_ref,
        int& val)
{
    struct node *last = *head_ref;
    if (*head_ref == NULL){
        return 1;
    }
    while (last->next->next!= NULL)
    {
        last = last->next;
    }
    struct node* temp = last;
    free(last->next->next);
    temp->next = NULL;
    return 0;
}

/*insert a node to the end of the list*/
int push(struct node** head_ref, 
         node* new_node)
{
  struct node *last = *head_ref;
  new_node->next = NULL;
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return 0;
  }
  while (last->next != NULL){
    last = last->next;
  }
  last->next = new_node;
  return 0;
}

/* To display linked list contant*/ 
int display(struct node *node)
{
  printf("\n");
  while (node != NULL)
  {
     printf(" %d \n", node->key);
     node = node->next;
  }
  printf("\n");
  return 0;
}

int main()
{
    struct node* stack = NULL;
    int retval = 0; 
    printf("\n empty flag %d \n" ,is_empty(stack));             
    push(&stack,init_node(1));
    display(stack);
    push(&stack,init_node(2));
    display(stack);
    pop(&stack,retval);
    display(stack);
    push(&stack,init_node(3));
    display(stack);
    return 0;         
}