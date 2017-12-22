#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

struct node
{
  int key;
  struct node* next;
};


/* initialze  node */
node* init_node(int key)
{ 
  /* allocate node in heap memory*/
  struct node* new_node = (struct node*) malloc(sizeof(struct node));

  /*set node vaules */
  new_node->key = key;
  new_node->next = NULL;

  /*return node */
  return new_node;
}


/*
  intput-vaule : linked list head 
  fucntionalty: check if list is empty or not 
  output : return true or flase 
*/
bool is_empty(struct node* head)
{
  /*head elemet is empty, cheak if the value in  (*head_ref) which the the first node in list  */
  if (head == NULL){
    return true;
  }else{
    return false;
  }
}



/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: insert pointer to  node to a linked list  
  output : return 0 vaule if the function excuted well
*/
int insert(struct node** head_ref,
	         node* new_node)
{
  /*set the node the to head */
    new_node->next = (*head_ref);
  /* move head to node , new_new node beacome the head node */  
    (*head_ref)    = new_node;
    return 0;
}


/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: insert pointer to  node to a linked list after a cuertun value  
  output : return 0 vaule if the function excuted well
*/
int insert_after(struct node** head_ref,
	               struct node* new_node, 
				         int key)
{

	bool key_found = false;
	struct node* current = *head_ref;
	while(current != NULL){
		if(current->key == key){
			key_found = true;
			break;
		}
		current = current->next;
	}
	if (key_found == true){
		new_node->next = current->next;
	    current->next = new_node;
	    return 0;
	}
		return insert(head_ref,
			            new_node);
}

/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: delelte pointer to  node from  a linked list  
  output : return 0 vaule if the function excuted well
*/
int delete_node(struct node** head_ref ,
                struct node* node_to_delete)
{
  struct node* current = (*head_ref);
  while(current->next!=node_to_delete){
    current = current->next;
  }
  struct node* temp = current->next;
  current->next =  node_to_delete->next;
  free(temp);
  return 0;
}


/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: delelte pointer to  node from  end oflinked list  
  output : return 0 vaule if the function excuted well
*/
int delete_at_last(struct node** head_ref)
{
	struct node *last = *head_ref;
	if (*head_ref == NULL)
  {
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


/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: delelte pointer to  node from  the begaining linked list  
  output : return 0 vaule if the function excuted well
*/
int  delete_at_first(struct node** head_ref)
{
   if (*head_ref == NULL){
      return 1;
   }
   struct node* temp = *head_ref;
   *head_ref = temp->next;   
   free(temp);

  	return 0;
}


/*
  intput-vaule : linked list head refernce  (pointer to pointer ) and pointer to node
  fucntionalty: insert pointer to  node to the end of linked list  
  output : return 0 vaule if the function excuted well
*/
int insert_to_last(struct node** head_ref, 
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

/*
  intput-vaule : linked list head refernce  (pointer to pointer )
  fucntionalty: reverse the linked list .
  output : return 0 vaule if the function excuted well
*/
static int reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return 0;
} 


/*
  intput-vaule : linked list head  pointer to node
  fucntionalty: print all keys in the list
  output : return 0 vaule if the function excuted well
*/
int printList(struct node *node)
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


/*
  intput-vaule : linked list head pointer to node
  fucntionalty: dettect if there is a loop in the list 
  output : return true or flase 
*/

bool is_loop_one(struct node *head)
{
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;
    while (slow_ptr && fast_ptr && fast_ptr->next )
    {
        slow_ptr = slow_ptr->next;
        fast_ptr  = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
           return true;
        }
    }
    return false;
}

/*
  intput-vaule : linked list head pointer to node
  fucntionalty: dettect if there is a loop in the list 
  output : return true or flase 
*/
bool is_loop_two(node* head)
{
  /*store the pointer to head node */
	struct node* remember = head;
  // reverse the linked list 
  reverse(&head);
  /* check of pointer head node is the same  after reverse list*/
  if(remember ==  head){
    	return true;
  }else{
    	return false;
  }
}

int find_list_len(struct node** head)
{
  int  length = 0;
  struct node* current = (*head);
  while(current->next != NULL)
  {
    current = current->next;
    length++;
  }
  return length;
}


/*
  intput-vaule : linked list head pointer to node
  fucntionalty: dettect if there is a loop in the list 
  output : return true or flase 
*/
bool is_Palindrome(struct node *head)
{ 
  //create new list
  struct node* new_head = NULL;
  struct node* current = head;
  struct node* next =  current->next;
  // copy list elemet;

  while(next != NULL)
  {
    printf("%d\n",insert(&new_head,current));
    current = next;
    next = next->next;
  }


  /*

  *
  
  //rever new list 
  reverse(&new_head);
  current = head;
  struct node* Other_current = new_head; 
  while(current != NULL and Other_current != NULL)
  {
    if(current->key != Other_current->key){
      return false;
    }
    current =   current->next;
    Other_current = Other_current->next;
  }
*/
  return true;
}


/*
  intput-vaule : linked list head ref
  fucntionalty: find the length of a linked list 
  output : return the lengnth of list
*/


bool is_Palindrome_two(struct node *head)
{ 


  int length = find_list_len(&head);
  struct node* node =  head;
  struct node* current = head;
  int *arr = new int[length];
  int i = 0 ;
  while (node != NULL)
  {
    arr[i] = node->key;
    node = node->next;
    i++;
  }
  for (int i = length; i >=0; i--)
  {
    if(current->key != arr[i]){
      return false;
    }
    current = current->next;
  }
  return true;
}




/*
  intput-vaule : linked list head pointer to node (first list ), linked list head pointer to node (second list)
  fucntionalty: dettect if there intersection in two lists
  output : return true or flase 
*/
bool is_intersection_one(struct node** head_ref,
                         struct node** other_head)
{
  struct node* current = (*head_ref);
  struct node* Other_current = (*other_head);
  while(current->next != NULL)
  {
    current = current->next;
  }
  while(Other_current->next != NULL)
  {
    Other_current = Other_current->next;
  }
  
  if( current == Other_current){
    return true;
  }
    return false;
}



/*
  intput-vaule : linked list head pointer to node (first list ), linked list head pointer to node (second list)
  fucntionalty: dettect if there intersection in two lists
  output : return true or flase 
*/
bool is_intersection_two(struct node** head_ref,
                         struct node** other_head)
{
  int  length = find_list_len(head_ref);
  int  Other_length = find_list_len(other_head);
  struct node* current = (*head_ref);
  struct node* Other_current = (*other_head);
  int differnace = abs(length - Other_length);

  if(length >  Other_length)
  {
    current = (*head_ref);
    Other_current = (*other_head);

    while(differnace > 0)
    {
      current = current->next;
      differnace--;
    }
  }else{
  while(differnace > 0)
    {
      Other_current = Other_current->next;
      differnace--;
    }
  }
  while(Other_current->next != NULL && current->next != NULL)
  {
    if (Other_current == current)
    {
      return true;
    }
    current = current->next;
    Other_current = Other_current->next;
  }
  return false; 
}


/*
  intput-vaule : linked list head pointer to node.
  fucntionalty: create a loop in list.
  output : return  0 , to indecate that the function excuted well.
*/
int Create_loop(struct node * head)
{
  head->next->next->next->next = head;
  return 0;
}


int main()
{
  //Linkedlist_Handler list = init_linked_list();
  /*
  struct node* head1 = NULL;
  //printf("%d\n",is_empty(head));
  insert(&head,init_node(10));
  insert(&head,init_node(12));
  insert(&head,init_node(13));
  insert(&head,init_node(18));
  insert_to_last(&head,init_node(4));
  insert_to_last(&head,init_node(6)); 
  printList(head);
  delete_at_first(&head);
  delete_at_last(&head);
  printList(head);
  reverse(&head);
  printList(head);
  /*
  /* Start with the empty list 
  struct node* head = NULL;
  insert(&head, init_node (20));
  insert(&head, init_node(4));
  insert(&head, init_node(15));
  insert(&head, init_node(10));
  /* Create a loop for testing 
  head->next->next->next->next = head;
  printf("%d\n", is_loop_two(head));
  */

 /*
  struct node* head1 = NULL;
  struct node* head2 = NULL;
  struct node* elemet1 = init_node(20);
  struct node* elemet2 = init_node(4);
  struct node* elemet3 = init_node(15);
  struct node* elemet4 = init_node(10);
  struct node* elemet5 = init_node(1);
  struct node* elemet6 = init_node(2);
  struct node* elemet7 = init_node(2);


  insert(&head1,elemet1);
  insert(&head1,elemet2);
  insert(&head1,elemet3);
  insert(&head1,elemet4);
  insert(&head2,elemet5);
  insert(&head2,elemet6);
  insert(&head2,elemet3);

  printf("\n %d \n", is_intersection_two(&head1,&head2));

  */

  struct node* head1 = NULL;
  struct node* elemet1 = init_node(1);
  struct node* elemet2 = init_node(2);
  struct node* elemet3 = init_node(3);
  struct node* elemet4 = init_node(3);
  struct node* elemet5 = init_node(2);
  struct node* elemet6 = init_node(3);
  insert(&head1,elemet1);
  insert(&head1,elemet2);
  insert(&head1,elemet3);
  insert(&head1,elemet4);
  insert(&head1,elemet5);
  insert(&head1,elemet6);
  printf("\n %d \n", is_Palindrome_two(head1));

  return 0;
} 