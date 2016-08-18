/*
 *     File Name: shell.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Monday, May 23, 2016 PM04:13:35 HKT
 */
#include<stdio.h>
#include "test_data.h"
int A[10] = {3,2,7,5,6,1,8,9};
void shell_insert(int a[],int n,int dk){
	int i;
	for(i = dk; i < n; i++){
		if(a[i] < a[i-dk]){  //思路上是有些怪诞
			int j = i - dk;
			int x = a[i];
			a[i] = a[i-dk];
			while(x < a[j]){
				a[j+dk] = a[j];
				j -= dk;
			}
			a[j+dk] = x;
		}
	}

}
void shell_sort(int a[],int n){
	int dk = n/2;
	while(dk >= 1){
		shell_insert(a,n,dk);
		dk /=2;
	}
}
int main(){
	int n = 8;
	shell_sort(A,n);
		print_one_array(A,n);
}

