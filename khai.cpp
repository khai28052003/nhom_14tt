#include<stdio.h>
#include<stdlib.h>

void hoanDoi( int &a, int &b)
{
	int k=a;
	a=b;
	b=k;
}

void sapXepTang(int x[], int n)
{
	for(int i=0; i<n; i++)
	{
		//2 7 9 3 5
		//int min= i;//i=2
		for(int j=i+1; j<n; j++)//j=3
		{	if(x[j]<x[i])//7<2 9<7 sai, 3<9 dung
			{
				//min = j;// min=3(3)
				hoanDoi(x[i], x[j]);
				
			}
				
				
		}
	}
}

void sapXepGiam(int x[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(x[j]>x[i])
			{
				hoanDoi(x[i], x[j]);
			}
				
		}
	}
}

void xuatMang(int x[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf(" %d", x[i]);
	}
}

int main()
{
	int a[100];
	int n;
	FILE *f;
	
	//mo file va viet ra file text3.txt
	f= fopen("D:\\code\\bt_tuan4\\text3.txt", "wb");
	if(f == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("Nhap vao so luong phan tu cua n: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
	printf("\nSap xep giam: ");
	sapXepGiam(a, n);
	xuatMang(a, n);	
	printf("\nSap xep tang: ");
	sapXepTang(a, n);
	xuatMang(a, n);	
	for(int i=0; i<n; i++)
	{
		fwrite(&a[i], sizeof(int), 1, f);
	}
	fclose(f);
	
	//doc file nhi phan sap xep tang
	f= fopen("D:\\code\\bt_tuan4\\text3.txt", "rb");
	if(f == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("\nDoc file nhi phan sap xep tang: ");
	for(int i=0; i<n; i++)
	{
		fread(&a[i], sizeof(int), 1, f);
		printf("%d\t", a[i]);
	}
	fclose(f);
	
	//mo file va viet ra file text3.txt
	f= fopen("D:\\code\\bt_tuan4\\text3.txt", "wb");
	if(f == NULL)
	{
		printf("Error!");
		exit(1);
	}
	sapXepGiam(a, n);
	for(int i=0; i<n; i++)
	{
		fwrite(&a[i], sizeof(int), 1, f);
	}
	fclose(f);
	
	//doc file nhi phan sap xep giam
	f= fopen("D:\\code\\bt_tuan4\\text3.txt", "rb");
	if(f == NULL)
	{
		printf("Error!");
		exit(1);
	}

	printf("\nDoc file nhi phan sap xep giam: ");
	
	for(int i=0; i<n; i++)
	{
		fread(&a[i], sizeof(int), 1, f);
		
		printf("%d\t", a[i]);
	}
	fclose(f);
}
