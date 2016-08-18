/*
 *     File Name: select.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Monday, May 23, 2016 PM08:58:40 HKT
 */
#include<stdio.h>
#include "test_data.h"
int A[10] = { 3,1,5,7,2,4,9,6,8};
/*
 * 之所以传递给一个i，主要也是为了降低
 * 复杂度
 */
int select_min_key(int a[],int n,int i){
	int k = i;
	int j;
	for(j = i + 1; j < n; j++){
		if (a[k] > a[j]) k = j;
	}
	return k;

}
void select_sort(int a[], int n){
	int key,tmp;
	int i;
	for(i = 0; i < n; i++ ){
		key = select_min_key(a,n,i);
		if(key != i){
			tmp = a[i];
			a[i] = a[key];
			a[key] = tmp;
		}
	}
}
int main(){
	int n = 9;
	print_one_array(A,n);
	select_sort(A,n);
	print_one_array(A,n);

}
