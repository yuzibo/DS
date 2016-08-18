#include <stdio.h>
int sum(int arr[], int size){
	if (size == 0)
		return 0;
	else
		return sum(arr, size - 1 ) + arr[size - 1];
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7};
	int b = sum(a, 7);
	printf("the sum is %d\n",b );
}