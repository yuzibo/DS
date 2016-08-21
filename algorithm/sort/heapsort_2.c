/*
 *     File Name: heap.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年08月18日 星期四 23时20分37秒
 */
#include<stdio.h>
#include<stdlib.h>
//void  heap_down(int a[], int []);
//void  heap_sort(int* , int );
//void swap(int , int );
/*边写代码，边写注释*/
 /* 左右孩子都应该小于父节点*/
/**
*   	int a[10] = {3,1,5,8, 9, 4, 6};
*    从(n-1)/2【8】开始整理
*
*
*/
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/*这里写一个是错误的*/
void heap_down(int* a, int start,int end)
{	
	int cur = start;
	int left = start * 2 + 1;
	int right =  start * 2 + 2;

	for(; left < end; cur = left, left = cur * 2 + 1, right = cur * 2 + 2){
		if(left < end && a[left] < a[right]) /* 右孩子大*/
			swap(&a[left], &a[right]);
		if(a[left] < a[cur])
			break;
		else
			swap(&a[left], &a[cur]);
	}


}

void heap_sort(int* a, int size)
{
	int i ;
	for (i = (size - 1)  / 2; i >= 0; i--)
		heap_down(a, i, size);
	printf("MAX is %d\n", a[0]);
	
	for( i = size  ; i > 1; i--){
		swap(&a[0], &a[i]);
		heap_down(a, 0, i - 1);
	}
	

}


int main()
{
	int a[10] = {3,1,5,8, 9, 4, 6};
	heap_sort(a, 6 );
	int i;
	for( i = 0; i < 7; i++)
	 	printf("%d\t",a[i]);
	 printf("\n");
}


