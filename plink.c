/*************************************************************************
     File Name: plink.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月12日 星期二 19时33分57秒
 ************************************************************************/
/* Return linklist with pointer
 *
 */

#include<stdio.h>


#include<stdlib.h>
#include<stdio.h>

#define Head_Node_Insert 1

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

/*struct of storage*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/*Initialize : return pointer to list*/
LinkList  InitList( ){
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(OVERFLOW);
	(L)->next = NULL;
	return L;
}
int DestoryList(LinkList L)
{
	LinkList p = L->next;
	while(p){
		p = p->next;
		free(p);

	}
	return OK;

}
LinkList InserNode(LinkList L,int x)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if(p == NULL){
		printf("No memory\n");
		exit(1);
	}
	else{
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;



}
void PrintList(LinkList L)
{
	LinkList p = L->next;
	while(p){
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("\n");

}
int main(int argc,char **argv)
{
	LinkList L;
	int n,x,i;
	int flag = 0;
	/*
	 *initialize
	 * */
	L = InitList();
	/*
	 * end
	 */
	printf("Please input the number of insertion and insert num:\n");
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d",&x);
		L = InserNode(L,x);
	}

	PrintList(L);

	flag = DestoryList(L);
	if(flag)
		printf("destory success\n ");
	else
		printf("Destory wrong\n");



}
