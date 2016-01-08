#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int binary(int[],int);

int main(int argc, char *argv[])
{

	int a[7]={3,5,9,11,12,14,16};

	int return_number,i;
	int search_key=9;

	return_number = binary(a,search_key);
	
	printf("a[]=");
	for(i=0;i<=6;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\nSearch No: %d\nkey:%d\n",a[return_number],return_number);

	system("PAUSE");	
	return 0;
	}


int binary(int a[],int search_key)
{
    int start = 0;
    int end = sizeof(a);

    int middle;
    while(start <= end)
    {   
        middle =(start + end)/2 ;
        if(search_key == a[middle])  
        {
           return middle ;
           break;
        }
        else
        {
         if(search_key < a[middle])
            start = middle + 1;
         else
            end = middle - 1;  
       }     
    }
    return -1;
}
