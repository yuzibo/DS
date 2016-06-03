/*************************************************************************
     File Name: triplet.c
     Author: Bo Yu
     Mail: tsu.yubo@gmail.com
     Created Time: 2016年06月03日 星期五 01时18分02秒
 ************************************************************************/

#include<stdio.h>
#include "myselfdefine-1.h"
/*基本操作8个*/
Status init_triplet(triplet *T,element_type v1,element_type v2, element_type v3)
{
	*T = (element_type *) malloc (3 * sizeof(element_type));
	if(! *T)
		exit(OVERFLOW);
	(*T)[0] = v1,(*T)[1] = v2, (*T)[2] = v3;
	return OK;
}
Status destory_triplet(triplet *T)
{
	free(*T);
	*T = NULL;
	return OK;
}
/*用e返回T的第i元的值*/
Status get(triplet T,int i,element_type *e)
{
	if(i < 1 || i > 3)
		return ERROR;
	*e = T[i - 1];
	return OK;
}
Status put(triplet T,int i,element_type e)
{
	if(i<1 || i>3)
		return ERROR;
	T[i-1] = e;
	return OK;

}
/*判断是否升序,是返回1,否0*/
Status is_ascending(triplet T)
{
	return (T[0] <= T[1] && T[1] <= T[2]);
}
/*同上，降序*/
Status is_descending(triplet T)
{
	return (T[0]>=T[1] && T[1]>=T[2]);

}
/*用e返回T的三个元素最大值*/
Status is_max(triplet T,element_type *e)
{
	element_type max;
	max = T[0] >= T[1] ? T[0] : T[1];
	*e = T[2] >= max ? T[2] : max;
	return OK;
}
/*用e返回T的三个最小值*/
Status is_min(triplet T, element_type *e)
{
	element_type max;
	max = T[0] <= T[1] ? T[0] : T[1];
	*e = T[2] <= max ? T[2] : max;
	return OK;

}
int main()
{
	triplet T;
	element_type m;
	Status i;
	i = init_triplet(&T,5,7,9);
	printf("调用初始化函数后，i=%d(1:成功) T的三个值为：%d,%d,%d \n",i,
			T[0],T[1],T[2]);
	i = get(T,2,&m);
	if(i == OK)
		printf("T的第2个值为:%d\n",m);
	i = put(T,2,6);
	if(i == OK)
		printf("T的第2个参数改为6后，T 的三个值为：%d\t %d\t %d\t \n",T[0],T[1],T[2]);
	i = is_ascending(T);
	printf("调用测试升序的函数,i=%d0:否，1：是\n",i);
	i = is_descending(T);
	printf("i =%d: 1 yes,==0 not\n",i);

	if((i = is_max(T,&m) ) == OK)
		printf("T中最大的值为: %d\n",m);
	if((i = is_min(T,&m) ) == OK)
		printf("T中最小的值为:%d\n",m);
	destory_triplet(&T);
	printf("销毁Thou ,T=%u(NULL)\n",T);


}
