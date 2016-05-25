/*
 *     File Name: insert_2.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Tuesday, May 24, 2016 AM11:00:46 HKT
 */
#include<stdio.h>
#include "test_data.h"
int A[10] = {3,1,5,7,2,4,9,6,8};
void insert(int a[],int n){
	int i,j;
	int tmp;//我没用哨兵，使用的是临时变量
	for (i = 1; i < n ;++i){ //..
		if(a[i] < a[i-1]){ //说明需要插入有序表
			tmp = a[i];
			a[i] = a[i-1];
			for(j = i - 1 ; a[j] > tmp; --j){ // 移动,
							//这里我把比较符号
							//搞反了。
				a[j+1] = a[j];
			}
			a[j + 1] = tmp;
		}

	}

}

int main(){
	int n = 9;
	print_one_array(A,n);
	insert(A,n);
	print_one_array(A,n);

}
