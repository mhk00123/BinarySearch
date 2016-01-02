#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a[8][3];
	int i,j;
	int c_av = 0,m_av = 0;

	for(i=0;i<=7/*i<8*/;i++)
	{
		printf("-----------------------\n");
    	printf("Student %d \n",i+1);
    	printf("No.");
    	scanf("%d",&a[i][0]);
    	printf("ComC: ");
    	scanf("%d",&a[i][1]);
    	printf("Maths:");
    	scanf("%d",&a[i][2]);
	}

	for(i=0;i<=7;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf(" AV: %.1f",(a[i][1]+a[i][2])/2.0);
		c_av = c_av + a[i][1];
		m_av = m_av + a[i][2];
		printf("\n");
	}
	printf("ComC Av: %.2f \n",c_av/8.0);
	printf("ComC Av: %.2f \n",m_av/8.0);

	system("PAUSE");
	return 0;

}
