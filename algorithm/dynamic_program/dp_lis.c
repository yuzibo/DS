/*
 *     File Name: dp_lis.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年08月18日 星期四 02时52分56秒
 */
/*
 *     关于动态规划的入门题
 *     求一个数列的最大上升子序列
 状态方程：
 *L(i) = { 1 + Max ( L(j) ) } where j < i and arr[j] < arr[i] and if there is no such j then L(i) = 1

 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LS[100];
int LIS(int a[], int n)
{

	int ans = 1, m, i, j;
	LS[1] = 1;
	for(i = 1; i < n; i++){

		m = LS[i];

		for( j = i - 1; j >= 0; j --)
			if(a[j] < a[i] && LS[j] > m)
				m = LS[j];
		
	LS[i] = m + 1;
		
	if (LS[i] > ans)
		ans = LS[i];

	}
	return ans;
}
int main()
{
	int a[10] = {10, 22, 9, 33, 21, 50, 41, 60, 80};

	/*int a[20] = {5,7,6,1,3,9,5,3,4,1,4,5,6,7,8};*/
	memset(LS, 0, sizeof(LS));
	int k = LIS(a, 15);
	printf("THE LIS is %d\n", k);


}

