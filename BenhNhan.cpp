#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct benhnhan{
	int ma;
	char hoten[31];
	int tuoi;
}BN;

typedef struct node
{
	BN info;
	struct node* next;
}Node;

typedef struct QUEUE
{
	Node* pHead;
	Node* pTail;
}Q;

void init(Q &DS){
	DS.pHead=DS.pTail=NULL;
}

int isEmpty(Q DS){
	return (DS.pHead==NULL);
}

void Nhap1BN(BN &x){
	printf("\nNhap ma: ");
	scanf("%d",&x.ma);
	printf("Nhap ten: ");
	fflush(stdin);
	scanf("%s",&x.hoten);
	printf("Nhap tuoi: ");
	scanf("%d",&x.tuoi);
}

void ShowNode(Node* x){
	printf("%d\t%s\t%d",x->info.ma,x->info.hoten,x->info.tuoi);
}

Node* CreateNode(BN x){
	Node* p=new Node;
	p->info=x;
	p->next=NULL;
	return p;
}

void Insert(Q &DS, BN x){
	Node* p=CreateNode(x);
	if (isEmpty(DS)==1){
		DS.pHead=DS.pTail=p;
	}
	else{
		DS.pTail->next=p;
		DS.pTail=DS.pTail->next;
	}
}

int Remove(Q &DS, BN &x){
	if(isEmpty(DS)==1)
		return 0;
	Node* p=DS.pHead;
	x=p->info;
	DS.pHead=DS.pHead->next;
	delete p;
	return 1;
}

int Dem(Q DS){
	int d=0;
	for (Node* p=DS.pHead;p!=NULL;p=p->next)
		d++;
	return d;
}

void ShowList(Q DS){
	for (Node* p=DS.pHead;p!=NULL;p=p->next){
		printf("\n");
		ShowNode(p);
	}
}

int main(){
	int chon;
	Q ChuaKham,DaKham;
	init(ChuaKham);
	init(DaKham);
	do{
		printf("\n1) Thêm 1 b?nh nhân vào Queue.");
		printf("\n2) L?y b?nh nhân ti?p theo s? khám");
		printf("\n3) Cho bi?t s? lu?ng ngu?i dã khám");
		printf("\n4) Cho bi?t s? lu?ng ngu?i chua khám.");
		printf("\n4) Xu?t danh sách b?nh nhân còn trong hàng d?i ch? khám");
		printf("\nBan hay chon: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				BN x;
				Nhap1BN(x);
				Insert(ChuaKham,x);
			break;
			case 2:
				printf("\nBenh nhan se kham: ");
				ShowNode(ChuaKham.pHead);
				BN y;
				Remove(ChuaKham,y);
				Insert(DaKham,y);
			break;
			case 3:
				printf("\nSo luong da kham: %d",Dem(DaKham));
			break;
			case 4:
				printf("\nSo luong chua kham: %d",Dem(ChuaKham));
			break;
			case 5:
				printf("\nCac benh nhan cho kham: ");
				ShowList(ChuaKham);
			break;
			default: chon=0;
		}
	}while(chon!=0);
	return 0;
}
