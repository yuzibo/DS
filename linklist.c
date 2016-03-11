/*************************************************************************
     File Name: linklist.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2015年11月27日 星期五 00时38分08秒
 ************************************************************************/
/*
 * 这里我使用的是全局变量的方法
 * 返回函数指针的在这一版本中没有实现
 * */

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

/*function of operation based*/
Status InitList(LinkList *L){

	*L = (LinkList)malloc(sizeof(LNode));
	if(!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}
Status DestoryList(LinkList *L){
/*return 1 after destory success*/
	LinkList q;
	while(*L){
		q = (*L) -> next;
		free(*L);
		*L = q; // There is wrong? or drop list?
	}
	return OK;
}
Status ListInsert(LinkList L, int i,ElemType e){
	/*Insert elem e at ith locate in list with head node
	 * */
	int j = 0;
	LinkList p = L,s;
	while(p && j < i -1){ /*seek i-1 th node*/
		p = p -> next;
		j ++;

	}
	if(!p || j > i-1)/* i < 1 or i biger than length of list */
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p -> next;
	p->next = s;
	return OK;
}
void CreateList(LinkList L,int x){
	LinkList p;
	p =(LinkList)malloc(sizeof(LNode));
	if(p == NULL){
		printf("No memory\n");
		exit(1);
	}
	else{
		printf("This %d\t",x);
		p->data = x;
	/*	p = L->next;
		L = p;
	*
	*   This is my frist code,should:
	*/
		p->next = L->next;
		L->next = p;

	}
}
/*
 * length of list
 * */
int ListLength(LinkList L){
	int i = 0;
	/*This is wrong? Value returned default is 0 ?*/
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;

}
/*
 * get elem
 */
void ListPlay(LinkList L){
	int i = 0;
	LinkList p = L->next;/*point the first node */
	while(p){
		printf("%d--->",p->data);
		p = p->next;

	}
	printf("\n");

}
/*
 * del value digui
 * 这个方法好像有问题,把删去的结点用0给填充了.
 * @2:这样的删除是有问题的,在链表中,删除一个链表节点
 * 正规思路是找到前一个节点.
 * */
void Del_X_1(LinkList L,ElemType x){
	LinkList p, q;
	q = L->next;
	if(q == NULL)
		return ;
	if(q->data == x){
		p = (q);
		(q) = (q)->next;
		free(p);
		Del_X_1((q),x);
	}
	else
		Del_X_1((L)->next,x);
}


int main()
{
	LinkList L;
	ElemType e,e0;
	Status i;
	int j,len,x,n;
	int value;
	/**
	 * initlize
	 */
	i = InitList(&L);
	if(i)
		printf("success\n");
	len = ListLength(L);
	printf("The Length of List is %d\n",len);
	/*
	 * 两种不同的插入方式
	 * */
	printf("Please choose auto(0) or hand_insert(1)\n");
	scanf("%d",&value);
	if(value == 0)
	{
	printf("Please input the number of insert\n");
	scanf("%d",&n);
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&x);
			i = ListInsert(L,1,x);
		}
	}
	else
	{
	printf("Please input the number of insert\n");
	scanf("%d",&n);
		for(j = 1; j <= n; j++){
			scanf("%d",&x);
			CreateList(L,x);
		}
	}
	/*
	 * Two ways to insert list
	 */


	printf("After inserting 1~%d:\n",n);

	ListPlay(L);
	len = ListLength(L);
	printf("The Length of List is %d\n",len);

//	Del_X_1(L,3);

	ListPlay(L);
	len = ListLength(L);


	i = DestoryList(&L);
	if(!i)//
		printf("No destory\n");
	else
		printf("Success Destory\n");

}
