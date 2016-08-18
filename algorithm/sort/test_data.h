/*
 *     File Name: test_data.h
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: Monday, May 23, 2016 PM02:12:47 HKT
 */
/*
 * 需要两个参数，数组名和数组元素的个数
 */
void print_one_array(int A[],int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t",A[i]);
	printf("\n");

}
