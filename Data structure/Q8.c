#include <stdio.h>
#include <stdlib.h>



/*
  intput-vaule : pointer to array  , size of array 
  fucntionalty:  funtion to find the second largest element
  output : return the second largest element in  they array 
*/
int second_largest(int* arry, int size)
{
	int largest;
	int sec_largest;
	/*if array is null exit the program*/
	if(arry == NULL){
		return 1;
	}
	/* set largest and second largest intial value */
	if(arry[0] > arry[1])
	{
		largest = arry[0];
		sec_largest = arry[1];
	}
	else{
		largest = arry[0];
		sec_largest = arry[1];

	}
	/* update the value of largest and second largest*/
	for (int i = 2; i < size; ++i)
	{
		if (largest < arry[i])
		{
			sec_largest = largest;
			largest =  arry[i];
		}else{
			sec_largest = arry[i];
		}
	}

	return sec_largest;
}

/* 
  intput-vaule : pointer to address pointer to address
  fucntionalty:  swap two varibles in array , using there address
  output : return 0 if the function excuted well
*/
int swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    
    return 0;
}

/* 
  intput-vaule :pointer to int , size of the int
  fucntionalty: sort an array 
  output : return 0 if the function excuted well
*/
int Sort(int *arr, int size)
{
   for (int i = 0; i < size-1; i++)      
       // Last i elements are already in place   
       for (int j = 0; j < size-i-1; j++) 
       	/* sorting array in Dec order*/
           if (arr[j] < arr[j+1])
           	/* swap elements*/
              swap(&arr[j], &arr[j+1]);
   return 0;
}


/* 
  intput-vaule :pointer to int , size of the int
  fucntionalty:  find kth largest element in the array
  output :  return kth largest element in the arra
*/
int kth_largest(int *arr , int size, int k)
{
  /*sort the array*/
  Sort(arr,size);

  /*return k elements*/
  return arr[k-1];
}

/* 
  intput-vaule :pointer to int , size of the int
  fucntionalty: print array
*/
void printArray(int *arr, int size)
{
	printf("\n");
    for (int i =0; i < size; i ++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	/* init an array*/
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    /*find the size of array*/
    int size = sizeof(arr)/sizeof(arr[0]);

    /* print the array*/
    printArray(arr, size);

    /*test second largest function */
    printf("\n %d \n",second_largest(arr,size));

    /*test kth largest function*/
    printf("\n %d \n",kth_largest(arr,size,3));
    return 0;
}