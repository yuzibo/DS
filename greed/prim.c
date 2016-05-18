
/*
 * 默认的最大值是1000000
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define print_maritx_int(n,a)	\
	for (i = 0; i < n ;i++)	\
	{			\
		printf("\n");	\
		for (j = 0; j < n; j++) \
			printf("%d\t",a[i][j]); \
	}
/*
 * store global value .
 * */
int c[10][10];
/*
 * 我一直在想不用全局变量的方法
 * */
void initliaze(int n)
{
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j ++)
			c[i][j] = 1000000;
	}
}
void prim(int n)
{
/*
 * 参数说明: 采用全局变量的方式;
 * n 是n个节点。矩阵是代表权值。
 * !! 我一直不满意采用全局变量的方式，更希望采用传递指针的形式。
 * */
	int i ;
	int lowcost[n + 1];

	int closet[n + 1];
	int flags[n + 1];
/*
 * please see code
 * */
	flags[1] = 1;
	/*
	 * please test code
	 * */
	for(i = 2;i <= n; i++){
		lowcost[i]  = c[1][i];
		closet[i] = 1;
		flags[i] = 0;
	}
	for(i = 1; i < n; i++){
		int MAX_NUM = 1000000;
		int j = 1;
		int k;
		for(k = 2; k <= n; k++){
			/*
			 *  select elment from T - S,which value is minest
			 * */
			if((lowcost[k] < MAX_NUM) && (!flags[k])){
				j = k;
				MAX_NUM = lowcost[k];
			}
		}
			printf("%d\t ",j);
			flags[j] = 1;
			for(k = 2; k <= n; k++){
				/*
				 * here,search lowest value after updated.
				 * closet[j] is j conjcents S.
				 * */
				if((c[j][k] < lowcost[k]) && !flags[k]){
					lowcost[k] = c[j][k];
					closet[k] = j;
				}

			}
	}

}
int main()
{
	freopen("prim.in","r", stdin);
	int n;
	scanf("%d",&n);
	initliaze(n);
	int i,j;
	for(i  = 1; i <= n; i++)
		for(j = 1; j <= n; j++ )
			scanf("%d",&c[i][j]);

	print_maritx_int(n,c);
	prim(n);

}


