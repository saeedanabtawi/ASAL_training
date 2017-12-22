#include <time.h>
#include <stdio.h>
#include <stdlib.h>


struct entry{
 time_t time;
 int value;
};

struct structure {
    entry   all;
    entry *array;
};

entry* create_entry(int new_value)
{
	struct entry* new_entry = (entry*) malloc(sizeof(entry));

	new_entry->value =  new_value;
	new_entry->time = time(NULL);

	return new_entry;
}

structure* create_structure(int size)
{
	struct structure*  new_structure  = (struct structure*) malloc(sizeof(struct structure));

	new_structure->all.value = 0; 
	new_structure->all.time = 0; 
	new_structure->array = (struct entry*) malloc(sizeof(entry)*size);

	return new_structure;
}

void set(struct structure* structure,struct entry* new_entry , int index)
{
	structure->array[index].value = new_entry->value;
	structure->array[index].time = new_entry->time;

}

entry get(struct structure* structure,int index)
{ 
  if (structure->all.time>structure->array[index].time)
  {
		return structure->all;
  }
  return  structure->array[index];
}

void setall(struct structure* structure,struct entry* new_all)
{
	structure->all.value = new_all->value;
	structure->all.time = new_all->time;
}


int main() 
{
   int size, ch ,index,value;
   printf("Enter the number of elements:");
   scanf("%d", &size);
   struct structure* nstructure = create_structure(size);
   struct entry* new_entry = NULL;
   struct entry* all_entry = NULL;
    while (1) 
    {

        printf("\n1. set an entry \t2. setall \n");
        printf("3. get an entry \t 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
	        case 1:{
	            printf("Enter the  value:");
	            scanf("%d",&value);
	            printf("Enter the  index:");
	            scanf("%d",&index);
	            new_entry = create_entry(value);
	   			set(nstructure, new_entry, index);
	            break;
	        }
	        case 2:{
	            printf("Enter the  value:");
	            scanf("%d",&value);
	            all_entry = create_entry(value);
	            setall(nstructure,all_entry);
	            break;
	        }
	        case 3:{
	            printf("Enter the index:");
	            scanf("%d",&index);
	            printf("\n  index %d : %d \n",1,get(nstructure,index).value);
	            break;
	        }
	        case 4:{
	            exit(0);
	        }
	        default:{
	            printf("You have entered a wrong option!!\n");
	            break;
	        }
    	}
	}
    return 0;
}