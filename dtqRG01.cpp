#include <stdio.h>

int he(int n,int a[100])
{
	int i,j,sum=a[0],max=0;
	for (i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			sum=sum+a[j];
			if (max<sum)
			{
				max=sum;
			}
		}
		sum=a[0];
	}

	;
	for (i=0;i<n;i++)
	{
		if (a[i]>=0)
		{
			break;
		}
		else max=0;
	}

	return max;
}


int main()
{
	int n,i,a[100],k,x,y,max;
	printf("数组元素个数：");
	scanf("%d",&n);
	k=n;
	printf("-----------------------------------------------------------\n");
	for (i=0;i<k;i++)
	{
		printf("请输入一个整数：");
		scanf("%d",&a[i]);
	}
	printf("-----------------------------------------------------------\n");


	max=he(n,a);
	printf("-----------------------------------------------------------\n");
	printf("最大子段和：%d",max);
	return 0;
}