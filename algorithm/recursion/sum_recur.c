#include<stdio.h>

int sum(int arr[], int size){
	if (size == 0)
		return 0;
	else{
		/*递归调用*/
		int small_result = sum (arr,  size - 1);
		return small_result + arr[size - 1];
	}
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7};
	int b = sum(a, 7);
	printf("sum = %d\n", b);
}