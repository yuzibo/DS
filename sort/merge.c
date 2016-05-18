/*
 *     File Name: merge.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Wednesday, May 18, 2016 AM09:41:31 HKT
 */

/*
 * 在一个数组内，人为的划分为两个有序子数组；
 * 还可以实现在两个数组内的话
 *
 */
#include<stdio.h>
#include<stdlib.h>
int A[10] = {8, 9, 11, 21,30,13,18,25};
/*
 * 排序算法，A[p]到A[q]有序，A[q+1]到A[r]有序
 * 这就是参数的意义
 */
void merge(int a[],int p,int q, int r){
	int bp[r - p + 1];
	int i,j,k;
	i = p; j = q + 1; k = 0;
	while(i <= q && j <= r){ // 逐一判断两子数组的元素
		if(a[i] <= a[j])
			bp[k++] = a[i++];
		else
			bp[k++] = a[j++];
	}
	if(i == q + 1 ){     // 针对两种情况分析，前一个子数组比较完成
		for (;j <= r; j++)
			bp[k++] = a[j];
	}
	else{		//后一个子数组比较完成
		for(; i <= j; i++)
		bp[k++] = a[i];
	}
	for(i = 0; i <= k; i++){
		A[i] = bp[i];
	}


}
int main(){
	int p = 0,q = 4, r = 7;
	merge(A,p,q,r);
	int i;
	for (i = 0; i <= r; i++)
		printf(" %d\t",A[i]);

}


