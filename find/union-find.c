/*
 *     File Name: union-find.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年09月08日 星期四 22时21分12秒
 *     使用路径压缩和按权合并的并查集算法
 */
#include<stdio.h>
#include<stdlib.h>

 /* 图的便边*/
 struct Edge {
 	int src, dest;
 };

 /* 一个图结构，V：顶点数E:边数*/

 struct Graph
 {	
 	int V, E;
 	struct Edge* edge; //边的结构
 };

struct subset
{
	int parent;
	int rank;
	
};
/*创建一个图结构*/
struct Graph* create_graph(int v, int e)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = v;
	graph->E = e;
	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
	return graph;	
};
/*路径压缩*/

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
/* 按权值合并*/

void union_sub(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

/* 检查*/
int is_cysle(struct Graph* graph)
{
	int V = graph->V;
	int E = graph->E;
	/*分配*/
	struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
	int i;
	for(i = 0; i < V; i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	/*判断是否一个环*/
	for(i = 0; i < E; i++)
	{
		int x = find(subsets, graph->edge[i].src);
		int y = find(subsets, graph->edge[i].dest);
		if (x == y)
			return 1;
		union_sub(subsets, x, y);
	}
	return 0;

}
/*
*   0
*   | \
*   |   \
*   1----2
*/
int main(int argc, char const *argv[])
{
	int V = 3, E = 3;
	struct Graph* graph = create_graph(V, E);
	// add 0 - 1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	// add 0 - 2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;

	// add 1 -2

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	if(is_cysle(graph))
		printf("THe graph contain cycle\n");
	else
		printf("Graph does't contain cycle");

	
	return 0;
}