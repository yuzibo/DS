/*************************************************************************
     File Name: yubo.h
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年03月11日 星期五 03时09分48秒
 ************************************************************************/
#include<stdlib.h>
/*
 *
 * 使用方法，只需在主函数中声明i，j;
 * Right now, i don't have realize extern from "header.h",
 * Only to use "cat macro.h >> filename" ;
 * 2016-03-11
 *
 */
#define print_maritx_int(n,a)	\
	for (i = 0; i < n ;i++)	\
	{			\
		printf("\n");	\
		for (j = 0; j < n; j++) \
			printf("%d\t",a[i][j]); \
	}
