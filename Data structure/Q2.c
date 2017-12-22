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

int  deQueue(struct node** head_ref, int val)
{
   if (*head_ref == NULL){
      return 1;
   }
   struct node* temp = *head_ref;
   *head_ref = temp->next;   
   free(temp);
   return 0;
}

/*insert a node to the end of the list*/
int enQueue(struct node** head_ref, 
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

int main() {
   struct node* queue = NULL;
   printf("%d\n",is_empty(queue));
   int retval = 0;
   enQueue(&queue,init_node(14));
   enQueue(&queue,init_node(22));
   enQueue(&queue,init_node(13));
   display(queue);
   deQueue(&queue,retval);
   deQueue(&queue,retval);
   display(queue);
   enQueue(&queue,init_node(14));
   display(queue);
}