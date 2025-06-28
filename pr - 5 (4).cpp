#include<stdio.h>
int main()
{
	int row,column;
	
	printf("Enter the array's row size:");
	scanf("%d",&row);
	
	printf("Enter the array's column size:");
	scanf("%d",&column);
	
	printf("Enter array's alements:\n");
	int a[row][column];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
   printf("output:\n");
   
   int row_number;
   printf("Enter row number:");
   scanf("%d",&row_number);
   printf("Elements of row %d:",row_number);
   
   int row_sum=0;
   for(int j=0;j<column;j++)
   {
   	printf("%d",a[row_number][j]);
   	row_sum+=a[row_number][j];
   }
   printf("\n the sum of row %d:%d\n",row_number,row_sum);
   
   int column_number;
   printf("Enter column number:");
   scanf("%d",&column_number);
   printf("Element of column %d:",column_number);
   
   int column_sum=0;
   for(int i=0;i<row;i++)
   {
   	printf("%d",a[i][column_number]);
   	column_sum+=a[i][column_number];
   }
   
   printf("\n the sum of column %d:%d\n",column_number,column_sum);
}