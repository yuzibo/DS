#include <stdio.h>

int sum( int arr[], int size){
	int result;
	if ( size == 0 )
		result = 0;
	else {

		int small_result = sum(arr, size - 1);
		result = small_result + arr[ size - 1 ];


	}
	return result;
}
int main()
{ 
	int a[10] = {1,2,3,4,5,6,7};
	int b = sum(a, 7);
	printf("the sum is %d\n", b);
}