/*
 *     File Name: sort.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Thursday, May 19, 2016 PM09:48:43 HKT
 */
#include<stdio.h>
int A[20 + 1] = { 7,5,4,6,3,2,1,1};
/*我的困难局限于标志变量的位置*/
void bubblesort(int a[],int n){
	int i,j,temp,sorted;
	i = sorted = 0;
	while( (i < n - 1) && (!sorted)){
		sorted = 1;
		for(j = n - 1; j > i; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				sorted = 0;
			}
		}

	}


}
int main(){
	int i,n = 8;

	for (i = 0; i < 8; i++)
		printf("%d\t",A[i]);
	printf("\n");
	bubblesort(A,8);
	for (i = 0; i < 8; i++)
		printf("%d\t",A[i]);
	printf("\n");

}
