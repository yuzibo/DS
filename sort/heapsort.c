/*
 *     File Name: heapsort.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Friday, May 27, 2016 AM11:09:46 HKT
 */
#include<stdio.h>
#include "test_data.h"

int A[10] = {3,1,2,5,9,6,7,4};

/*
 *	start: 相当于root,start对于数组的观点来说直观
 *		从srart到end选取最大的数
 *	root: 相对于tree来说直观
 *		为了方便数组下标从0开始，end应该为个数减1
 *		尤其注意这点
 */
void maxheap_down(int a[],int start,int end){
	int current = start;
	int left = start * 2 + 1;
	int tmp = a[current];   /*从根节点、左右子孩子中选择一个最大的*/
	for(; left < end; current = left, left = 2 * current + 1){
		if(left < end && a[left] < a[left + 1])
			left++;  //右孩子大
		if(a[left] <= tmp)
			break;   //这一句包含了两种情况
		else{		// 调整tmp与大的孩子的值
			a[current] = a[left];
			a[left] = tmp;
		}
	}
}
void heap_sort(int a[],int n){
	int i,temp;
	for(i = n / 2 - 1;i >= 0; i--){
		maxheap_down(a,i,n-1);//看你从主函数调用时传递的参数
	}
	printf("MAX is %d\n",a[0]);
	/*从最后一个元素开始，不断缩小范围直至最后一个元素*/
	for(i = n - 1;i >= 0; i--){
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		/*从堆头开始往下再次调整*/
		maxheap_down(a,0,i-1);

	}

}
int main(){
	print_one_array(A,8);
	heap_sort(A,8);
	print_one_array(A,8);

}
