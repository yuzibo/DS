/*************************************************************************
     File Name: dijkstra.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年03月04日 星期五 01时34分07秒
input: n

代表着每条的权值，源点是v1,最后打印代表着从v1到n的最短路径。
感觉还是有毛病的。
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*定义的最大值，当然，这里指的是相对*/
#define MAX_NUM 1000000;
#define true 1;
#define false 0;
/*存储矩阵*/
int a[10][10];
/*每一次另外集合T里集合s最近的点的距离*/
int dist[10];

int prev[10];
int n ;
/* source node */
int v,w;

void short_test_path(int n,int v1)
{
	int k;
	if(v1 < 1 || v1 > n)
		return ;
	int  s[10] ;
	int i,j;
	for (i = 1; i <= n; i++){
		dist[i] = a[v1][i];
		s[i] = 0;
		if( dist[i] == 1000000 )
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = v1;
		}

	}//首先设定源点
	dist[v1] = 0;
	s[v1] = true;
	for( i = 1; i <= n; i++){
		int temp = MAX_NUM;
		int u = v1;
		for(j = 1; j <= n ;j++){
			if((!s[j]) && dist[j] < temp){
				u = j;
				temp = dist[j];

			}

		}
		s[u] = true;
		for(j = 1; j <= n; j++){
			if((!s[j]) && a[u][j] < temp){
				int newdist = dist[u] + a[u][j];
				if (newdist < dist[j]){
					dist[j] = newdist;
					prev[j] = v;
				}
			}

		}

	}

	k = n;
	printf("the node is %d:\n",k);
	while(k != v1){
		printf("%d",prev[k]);
		k = prev[k];
	}
}
void initialize(int n){
	int i,j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			a[i][j] = 1000000;
}
int main()
{
	int i,j,v1 = 1;
	freopen("dijkstra.in","r",stdin);
	scanf("%d",&n);

	initialize(n);
	for(i = 1; i <= n; i ++){
		for(j = 1; j <= n; j++){
			scanf("%d",&a[i][j]);
		}
	}

	short_test_path(n,v1);

	for(i = 1; i <= n; i ++){
		printf("\n");
		for(j = 1; j <= n; j++){
			printf("%d\t",a[i][j]);
		}
	}
	printf("shortest_dist_is %d: \n",dist[n]);

}
