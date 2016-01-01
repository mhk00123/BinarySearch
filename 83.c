#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort_by_ID(int b[][4]);
void sort_by_score(int b[][4]);
void print(int b[][4]);
int search(int[], int ,int);

int main(void)
{
    srand(time(NULL));
    
    int a[8][3]; //original data
    int b[8][4]; //sort data
    int c[8]; //save No.
    int i,j,user_type,user_type_No;

    int s_re;
    

    int c_av=0,m_av=0;  //av=average , c_av=Computer Concept average, m_av=Maths average

    /* random No. ComConcept Maths score */
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=2;j++)
            {
                a[i][j] = (rand()%101); //random scope: 0 to 100
                b[i][j] = a[i][j];
            }
        c_av = c_av + a[i][1];
        m_av = m_av + a[i][2];
        b[i][3] = i+1;
        
    }

    /*-------------------------------*/
    
    /* print original array*/
    printf(" ---------------------------------------------------------------\n");
    printf("|          \t|\tComC\t|\tMaths\t|\tAv\t|\n");
    for(i=0;i<=7;i++)
    {
            printf(" ---------------------------------------------------------------\n");
            printf("|     No.%-3d\t|\t%-3d\t|\t%-3d\t|\t%-4.1f\t|\n",a[i][0],a[i][1],a[i][2],(a[i][1]+a[i][2])/2.0);
    }
    printf(" ---------------------------------------------------------------\n");
    printf("|     AllAv\t|\t%.2f\t|\t%.2f\t|\t\t|\n",c_av/8.0,m_av/8.0);
   printf(" ---------------------------------------------------------------\n");
    /*-------------------------------*/

    do{
    printf("Function:  (1)Sort_by_Score (2)Sort_by_ID (3)Search (4)End\n");
    printf("Function(1,2,3,4): ");
    scanf("%d",&user_type);
    switch(user_type)
    {
        case 1: 
                sort_by_score(b);
                printf("Sort Finished \n \n");
                printf("     \t\t|\t\t\tBy Score\t\t|\t\t\n");
                print(b);
                break;

        case 2: 
                sort_by_ID(b);
                printf("Sort Finished \n \n");
                printf("     \t\t|\t\t\tBy ID\t\t\t|\t\t\n");
                print(b);
                break;

        case 3: 
                printf("No.");
                scanf("%d",&user_type_No);
                sort_by_ID(b);
                for(i=0;i<=7;i++)
                    { 
                        c[i] = b[i][0]; 
                    }

                s_re = search(c,user_type_No,8);

                if(s_re==-1)
                {
                    printf("Search Erorr!!\n");
                }
                else
                {
                 printf(" ------------------------------------------------------------------------------\n");
                 printf("|          \t|\tComC\t|\tMaths\t|\tAv\t|\tRank\t|\n");
                 printf(" ------------------------------------------------------------------------------\n");
                 printf("|     No.%-3d\t|\t%-3d\t|\t%-3d\t|\t%-4.1f\t|\t%d\t|\n",b[s_re][0],b[s_re][1],b[s_re][2],(b[s_re][1]+b[s_re][2])/2.0,b[s_re][3]);
                 printf(" ------------------------------------------------------------------------------\n");
                }
                    
                break;

        case 4:
                printf("Done!");
                exit(1);
        default: 
                printf("Type error!\n");
                break;
    }
    }while(1);


    system("PAUSE");
    return 0;

}

int search(int c[],int user_type_No, int index)
{
    int low = 0;
    int upper = 8;
    int middle;
    while(low <= upper)
    {   
        middle =(low+upper)/2 ;
       //printf("%d \t %d\n",c[low],c[middle]);      
        if(user_type_No == c[middle])  
        {
           return middle ;
           break;
        }
        else
        {
         if(user_type_No < c[middle])
            low = middle + 1;
         else
            upper = middle - 1;  
       }     
    }
    return -1;
}


void sort_by_score(int b[][4])
{
    int i, j;
    int temp_no,temp_c,temp_m;
    for(i=0;i<=7;i++)
    {
        b[i][3] = i+1;
    }
    
    for (i = 7; i > 0; i--)
    {
        for (j = 0; j <= i-1; j++)
        {
            if ((b[j][1]+b[j][2])/2.0 < (b[j+1][1]+b[j+1][2])/2.0)
            {
               temp_no = b[j][0];
               b[j][0] = b[j+1][0];
               b[j+1][0] = temp_no;

               temp_c = b[j][1];
               b[j][1] = b[j+1][1];
               b[j+1][1] = temp_c;

               temp_m = b[j][2];
               b[j][2] = b[j+1][2];
               b[j+1][2] = temp_m;
            }
        }
    }
}

void sort_by_ID(int b[][4])
{
    int i, j;
    int temp_no,temp_c,temp_m,temp_rank;
    for (i = 7; i > 0; i--)
    {
        for (j = 0; j <= i-1; j++)
        {
            if (b[j][0] < b[j+1][0])
            {
               temp_no = b[j][0];
               b[j][0] = b[j+1][0];
               b[j+1][0] = temp_no;

               temp_c = b[j][1];
               b[j][1] = b[j+1][1];
               b[j+1][1] = temp_c;

               temp_m = b[j][2];
               b[j][2] = b[j+1][2];
               b[j+1][2] = temp_m;

               temp_rank = b[j][3];
               b[j][3] = b[j+1][3];
               b[j+1][3] = temp_rank;
            }
        }
    }
}

void print(int b[][4])
{   
    int i;
    printf(" -------------------------------------------------------------------------------\n");
    printf("|          \t|\tComC\t|\tMaths\t|\tAv\t|\tRank\t|\n");
    for(i=0;i<=7;i++)
    {
            printf(" -------------------------------------------------------------------------------\n");
            printf("|     No.%-3d\t|\t%-3d\t|\t%-3d\t|\t%-4.1f\t|\t%d\t|\n",b[i][0],b[i][1],b[i][2],(b[i][1]+b[i][2])/2.0,b[i][3]);
    }
    printf(" -------------------------------------------------------------------------------\n");
    
}

