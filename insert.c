/*
 *     File Name: insert.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Monday, May 23, 2016 PM02:04:56 HKT
 */
#include<stdio.h>
#include "test_data.h"
/* my define header file */


int A[10] = {49,38,65,97,76,13,27};

void insert_sort(int a[],int n){
	int i,t;
	int tmp;
	for(i = 1; i < n; i++){ // 只需注意后一项比前一项大的即可
		if(a[i] < a[i-1]){
			t = i - 1;	// 先后移一个元素？这里快想透了
			tmp = a[i];
			a[i] = a[i-1];
			while(tmp < a[t]){ //寻找在有序表插入的位置

				a[t+1] = a[t];
				t--;
			}
			a[t+1] = tmp; //将哨兵元素放入其中
		}


	}



}

int main(){
	int n = 7;
	print_one_array(A,n);
	insert_sort(A,n);
	print_one_array(A,n);
}
