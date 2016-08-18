/*
 *     File Name: qsort.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Friday, May 27, 2016 PM09:35:32 HKT
 */
#include<stdio.h>
#include "test_data.h"
int A[10] = {3,1,2,5,9,6,7,4};
int partition(int a[],int low, int high){
	int pivot = a[low];
	while(low < high){
		while(low < high && a[high] >= pivot) --high;
			a[low] = a[high];
		while(low < high && a[low] <= pivot) ++low;
			a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void quick_sort(int a[],int low,int high){
	if(low < high){
		int pivotloc = partition(a,low,high);
		quick_sort(a,low,high-1);
		quick_sort(a,low+1, high);

	}

}
int main(){
	print_one_array(A,8);
	quick_sort(A,0,7);
	print_one_array(A,8);

}
