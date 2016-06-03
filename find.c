
#include<stdio.h>
int pre[1050];
int flags[1050];
int find(int x){
	/* you must don't forget */
	int r = x;
	while(r != pre[r]){
		r = pre[r];
	}

	int j = x, i;
	while(pre[j] != r){
		i = pre[j];
		pre[j] = r;
		j = i;
	}
	return r;

}

void mix(int a,int b){
	int root_a = find(a);
	int root_b = find(b);
	if(root_a != root_b)
		pre[a] = b;
}
int main()
{

	int n,m,a,b;
	int i,j;
	freopen("find.in","r",stdin);
	scanf("%d%d",&n,&m);

		for(i = 1; i <= n; i++){
			pre[i] = i;
			/*将自己本身设为自己的前导点*/
			flags[i] = 0;
		}
		for(j = 1; j <= m; j++){
			scanf("%d%d",&a,&b);
			mix(a,b);
		}

	for(i = 1; i <= n; i++){
		flags[find(i)] = 1;
	}
	int ans = 0;
	for(i = 1; i <= n; i++)
	{
		if(flags[i] == 1)
			ans++;
	}
	printf("total ans is %d\n",ans - 1);

}

