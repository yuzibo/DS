#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status ;
typedef int Boolean;
typedef int ElemType;


struct list_node{
	ElemType data;
	struct list_node *next;

};
typedef struct list_node *LinkList;
/*
*  01
*/
Status init_list(LinkList *L)
{
	*L = malloc(sizeof (LinkList));
	if(*L == NULL){
		printf("Fail to malloc memory\n");
		exit(1);
	}
	(*L)->next = NULL;
	return OK;
}
/*
*	condition: list exist
*	return length of list
*/
int list_length(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}



/*
 * condition: list exist, insert value into list
*/

Status list_insert(LinkList L, int loc, ElemType value)
{
	int j = 0;
	LinkList p = L, s;
	while(p && j < loc -1){
		j++;
		p = p->next;
	}
	s = malloc(sizeof(LinkList));
	s->data = value;
	s->next = p->next;
	p->next = s;

}
/* is ready for list_equ_elem*/
Status compare(ElemType e1, ElemType e2)
{	
	if(e1 == e2)
		return OK;
	else
		return FALSE;


}
/**
 look for equie value of location to call compare func
**/
 int list_equ_elem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
 {	
 	int i = 0;
 	LinkList p = L->next;
 	while(p){
 		i++;
 		if(compare(p->data, e))
 			return i;
 		p = p->next;
 	}
 	return 0;
 }
/*
* enable list empty (destory)
*
This is my first version delist
void list_destory(LinkList *L)
{
	while((*L)->next){

		free(*L);
		(*L) = (*L)-> next;
	}
}
*/
Status list_clear(LinkList L)
{
	LinkList p,q;
	p = L->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
/*
* 	condition: list exist
*          result:     delete a elem in list via equie  e0
* 	@: list @: j location of elem deleted @e0 return
*/
Status list_del_elem(LinkList L,int loc, ElemType *e )
{
	LinkList p = L->next, q;
	int i = 1;
	while(p && i < loc -1 ){ /* point to prior elem*/
		p = p->next;
		i++;
	}
	if(!p->next && i >= loc -1) /* location error */
		return FALSE;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
/* 
* destory list
*/
void list_destory(LinkList *L)
{
	LinkList p;
	while(*L){
		p = (*L)->next;
		(*L) = p;
		free(p);
	}
}
/*
*   	 condition:list exist
*    	return next elem of cur_e
*/
int list_next_elem(LinkList L, ElemType *next_e, ElemType cur_e)
{
	LinkList p = L->next, q;
	while(p&&p->next->next){
		if(p->next->data == cur_e){
			*next_e = p->next->next->data;
			return OK;
		}
		p = p->next;

	}
	return FALSE;
}
/*
  condition: list exist
  return priorelem, if cur_e is not first elem ,it can use pre_e return prior elem;
  if is first elem, fail to return it;
*/
  Status list_prior_elem(LinkList L, ElemType *pre_e, ElemType cur_e)
{
	LinkList p = L->next, q;
	while(p->next){ /* p point to node that has next*/
		q = p->next;
		if(q->data == cur_e){
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return FALSE;


}
/**
 	condition: list exists,
	result: get i-th location's value
**/
int list_get_elem(LinkList L, int loc, ElemType *e)
{
	LinkList p = L->next;
	int i = 1;
	while(p && i < loc ){
		p = p->next;
		i++;
	}
	/* my code 
 	*e = p->data;
	if (i > loc)
		printf("There is no\n");
	*/
	if(!p || i > loc)
		return ERROR;
	*e = p -> data;
		return OK;
}
/*
* to judge list empty
*/
Status list_empty(LinkList L)
{
	if(L->next == NULL)
		return OK;
	else
		return FALSE;
	
}
/*
    visit func is ready for next 
*/
void visit(ElemType c)
{
	printf("%d\n", c);
}
/*
	vi0106¥73010¡­3s formal parameter is elemtype, and is different from sq_list
	condition: list exist
	result: to call vi func for each element
*/
Status list_traverse(LinkList L, void(*vi)(ElemType))
{
	LinkList p = L -> next;
	while(p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;

}
int main()
 {
 	LinkList  L;
 	ElemType e,e0;
 	Status i;
 	init_list(&L);
 	int j;
 	for( j = 0; j < 5; j++)
 		list_insert(L, 1, j);
 	list_traverse(L, visit);
 	i = list_empty(L);
 	printf("list is empty? (1 is OK or 0 is NO)%d\n", i);
 	list_clear(L);
 	i = list_empty(L);
 	printf("list is empty? (1 is OK or 0 is NO)%d\n", i);
	for( j = 1; j <= 10; j++)
	list_insert(L, j,j);
	printf("After insert 1~10,The list is \n");
	list_traverse(L, visit); 	
	list_get_elem(L, 5, &e);
	printf("The 5-th elem is %d\n",e);
	for(j = 0; j <= 1; j++)
	{
		int k = list_equ_elem(L, j, compare);
		if(k)
			printf("the location is %d of elem %d\n",k,j);
		else
			printf("The list is none  %d\n",j);
	}
	for (j = 1; j <= 2; j++) /* test first two elem*/
	{
		list_get_elem(L, j, &e0); /* put j-th elem into e0*/
		i = list_prior_elem(L, &e, e0);
		if( i )
			printf("elem %d has prior elem %d\n",e0,e);
		else
			printf("elem %d NOT has prior elem \n",e0);
	}
	for (j = list_length(L)-1; j <= list_length(L); j++) /* test last two elem for next elem*/
	{	
		list_get_elem(L, j,&e0);
		i = list_next_elem(L, &e, e0);
		if(i)
			printf("The elem %d has next elem %d\n",e0, e);
		else
			printf("The elem %d NOT has next elem\n", e0);

	}
	int k = list_length(L);

	for(j = k + 1; j >= k; j--)
	{
		i = list_del_elem(L, j, &e0);
		if (i)
			printf("delete %d-th elem is %d\n",j, e0);
		else
			printf("There is %d-th elem NOT in list\n", j);
	}
	list_destory(&L);
	printf("The length of list is %d\n", list_length(L));
 }
