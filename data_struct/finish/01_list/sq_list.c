/*ZHS16GBK 缂栫爜闂*/
/** 你说它怎么就这么烦人腁*/
/*你这是想要做什么*/
/* 瀛楃鐨勯棶棰樼湡鏄剚浜猴紝from here, you must use English */
/**这是为啥呀**/
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

/* 线性表的动态分配顺序存储结构*/
#define LIST_INIT_SIZE 10   /* list initial malloc size */
#define LISTINCREMENT 2 /* malloc increment size */
typedef struct {
	ElemType *elem; /* base address of store */
	int length; /* now the length of list*/
	int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位)*/
}SqList;


typedef SqList sq_list;
/* create a  empty list */
Status InitList(SqList *L)
{
	(*L).elem = (ElemType * )malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!(*L).elem)
		exit(1);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}

Status destory_list(sq_list *l)
{
	free((*l).elem);
	(*l).elem = NULL;
	(*l).length = 0;
	(*l).listsize = 0;
	return OK;
}
/* condition: sort_list have been exist,
 * result: reset L be NULL
 *
 */
Status clear_list(sq_list *l)
{
	(*l).length = 0;
	return OK;
}
/*
*  condition: sq_list exits, 
*  result:	if L == NULL,  
*             	return TRUE ;if not, return false
*/
 Status list_empty(sq_list l)
 {
 	if(l.length == 0)
 		return OK;
 	else 
 		return FALSE;
 }
 /*
 * condition: sq_list exists, 
    return : the length of list
 *
 */
 Status list_length(sq_list l)
 {
 	return l.length;
 }
 /*
 * condition: exist
 * result:  return i-th value with e
 */
 Status get_elem(sq_list l, int i, ElemType *e)
 {
 	if(i < 1 || i > l.length)
 		exit(1);
 	*e = *(l.elem + i -1);
 	return *e;
 	
 };

 /*
	 compare elem,if == return 1
 */
Status comp(ElemType c1, ElemType c2)
{
	if (c1 == c2)
		return OK;
	else
		return FALSE;
}
/* 	condition: list exist, compare() to judge .
	retrun location of 1-th equie to e
*/
 Status list_local_elem(sq_list la, ElemType e,Status(*compare)(ElemType, ElemType))
 {
 	ElemType *p;
 	int i = 1;  /* the locaton of 1-th elem*/
 	p = la.elem; /*p is the location of 1-th elem*/
 	while(i < la.length && !compare(*p++, e))
 		++i;
 	if(i <= la.length)
 		return i;
 	return 0;

 }
 /*
 *  condition: list exist
 *  result: insert valued e into i-th location, length + 1
 */
 Status list_insert(sq_list *l, int i, ElemType e)
 {
 	ElemType *newbase, *q, *p;
 	if (i < 1 || i > (*l).length + 1)
 		return ERROR;
 	if((*l).length >= (*l).listsize) /* now the space is full, need to increase space*/
	{
		newbase = (ElemType *)realloc((*l).elem,((*l).listsize + LISTINCREMENT) * sizeof(ElemType));
		if(!newbase)
			exit(1); /* fail to malloc */
			(*l).elem = newbase; /* new base*/
			(*l).listsize += LISTINCREMENT; /* increment for capitly*/	
	
	} 
	q = (*l).elem + i - 1; /* q is insert location*/
	for(p = (*l).elem + (*l).length - 1; p >= q; --p)
	*(p + 1) = *p;
	*q = e;
	++(*l).length;
	return OK;	
 }
 /*
     condition: list exists
     result : clear list
 */
 Status list_clear(sq_list *l)
 {
 	(*l).length = 0;
 	return OK;
 }
 /*
 * conditon: list have been exist
 * result: if cur_e is elem,which in list,and is not the first,
 	  return it's prior value with pre_e
 */
 Status list_prior_elem(sq_list la, ElemType cur_e, ElemType *pre_e)
 {
 	int i = 2;
 	ElemType *p = la.elem + 1;
 	while(i <= la.length && *p != cur_e)
 	{
 		p++;
 		i++;
 	}
 	if (i > la.length)
 		return FALSE;
 	else{
 		*pre_e = *--p;
 		return OK;
 	}
 }
/* 
*  conditions: list exist
*   result: if e0's next_elem exist, to send e
*
*/
Status list_next_elem(sq_list la, ElemType cur_e, ElemType *next_e)
{
	int i = 1;
	ElemType *p = la.elem;
	while(i < la.length && *p != cur_e)
	{
		i++;
		p++;

	}
	if(i == la.length)
		return FALSE;
	else
	{
		*next_e = *++p;
		return OK;
	}
}
/*
*  conditions: list exist
*    result : delete i-th elem in list, and return value with e, 
	    and la.length - 1 
*/
Status  list_del_elem(sq_list *la, int i, ElemType *e)
{
	ElemType *p, *q;
	if(i < 1 || i > (*la).length)
		return ERROR;
	p = (*la).elem + i - 1; /*p is location of elem deleted*/
	*e = *p; /* elem deleted is assigned to e*/
	q = (*la).elem +(*la).length - 1; /* location of list_rear*/
	for(++p; p <= q; ++p) /*after elem left shift*/
		*(p -1) = *p;
	(*la).length--;
	return OK;

}

/*  
*    destory list
*/
Status list_destory(sq_list *la)
{
	free((*la).elem);
	(*la).elem = NULL;
	(*la).length = 0;
	(*la).listsize = 0;
	return OK;
}
/*
* list_traverse() to call the func(above) (accroding to with type )
*/

 void visit(ElemType *c)
 {
 	printf("%d\t", *c);
 }

 /*
	condition: list exists
	result: call vi() [ any func is ok]to visit each elem.
	Note: formal parameter(xingcan) to use '&',
	        This is order to modify value via call vi
 */

 Status list_traverse(sq_list l, void(*vi)(ElemType *e))
 {	
 	ElemType *p;
	int i;
 	p = l.elem;
 	for(i = 0; i < l.length; i++)
 		vi(p++);
 	printf("\n");
 	return OK;
}
/*
* printf duble value of elem
*/
 void dbl(ElemType *c)
 {
 	printf("%d ", 2*(*c));
 }
 /*
	@: to display the information of list
 */
 void list_info(sq_list la)
 {
 	printf("la.elem = %p \tla.length = %d\tla.listsize = %d\n",&la.elem,la.length,la.listsize);
 }
int main()
{
	SqList La, Lb;
	Status i;
	int j;
	ElemType e;
	i = InitList(&La);
	if (i)
		printf("create empty list successfully\n");
	printf("After initial, the list is \n");
	list_info(La);
		printf("Now insert 5 value :\n");
	for(j = 1; j <= 5; j++)
		i = list_insert(&La, j,j);
	list_info(La);
	printf("insert 1~5 at i-th: *La.elem = \n");
	for( j = 1; j <= 5; j++)
		printf("%d ",*(La.elem + j - 1) );
	printf("\n");
	i = list_empty(La);
	printf("La is empty? i =%d (1: Yes 0: No)\n",i);
	i =list_clear(&La);
	printf("After list_clear, La is empty? i = %d (1: Yes 0: No)\n",i);
	printf("After l insert 1~10, *La.elem = \n");
	for(j = 1; j <= 10; j++)
		list_insert(&La, j,j);
	for( j = 1; j <= 10; j++)
		printf("%d\t", *(La.elem + j - 1));
	printf("\n");
	list_info(La);
	list_insert(&La, 1, 0);
	for( j = 1; j <= La.length; j++)
		printf("%d\t", *(La.elem + j - 1));
	list_info(La);
	printf("\nThe 5-th  value is %d\n", get_elem(La, 5, &e));
	for (j = 3; j <= 4; j++)
	{
		int k = list_local_elem(La,  j,comp);
		if(k)
			printf("%d-th elem is square %d\n", k,j);
		else
			printf("None value is %d'2 elem\n",j);
	}
	/* test for the head two case*/
	ElemType e0;
	for(j = 1; j <= 2; j++)	
	{
		get_elem(La, j, &e0); /* */
		i = list_prior_elem(La, e0, &e);
		if (i == 0)
			printf("elem %d not have prior elem\n",e0);
		else
			printf("elem %d prior elem is %d\n", e0,e);
	}
	/*test last two case*/
	for(j = list_length(La) - 1; j <= list_length(La); j++)
	{
		get_elem(La, j, &e0); /* i-th elem to give e0*/
		i = list_next_elem(La, e0, &e); /* e0' next elem is */
		if (i == 0)
			printf("elem %d not have next elem\n", e0);
		else
			printf("elem %d ' next elem is: %d\n", e0,e);

	}
	int k = list_length(La);
	for(j = k + 1; j >= k; j--)
	{
		i = list_del_elem(&La, j, &e); /*delete i-th elem*/
		if (i == ERROR)
			printf("fail to del %d-th elem\n", j);
		else
			printf("elem deleted is %d\n", e);
	}
	printf("each output elem is :\n");
	list_traverse(La, visit);
	printf("\ndouble print elem \n");
	list_traverse(La, dbl);
	list_destory(&La);
	printf("After destory list is : \n");
	list_info(La);
	printf("Bye-Bye\n");


}
