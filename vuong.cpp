#include<stdio.h>
#define MAX 100

void Nhapn(int &n){
	printf("Nhap n: ");
	scanf("%d",&n);
}

void NhapDS(int a[][MAX], int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}

void XuatDS(int a[][MAX], int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}

void Xuat3(int a[][MAX], int n){
	printf("\nCac pt tren dcc: ");
	for (int i=0;i<n;i++)
		printf("%4d",a[i][i]);
	printf("\nCac pt tren dcp: ");
	for (int j=0;j<n;j++)
		printf("%4d",a[n-1-j][j]);
}

int main(){
	int a[MAX][MAX], n;
	Nhapn(n);
	NhapDS(a,n);
	XuatDS(a,n);
	Xuat3(a,n);
	return 0;
}
