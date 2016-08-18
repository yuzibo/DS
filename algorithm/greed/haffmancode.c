#include<stdio.h>
#include<stdlib.h>

#define MAXVALUE	10000 //define max value
#define MAXLEAF		100  // define max number of nodes
#define MAXNODE		MAXLEAF * 2 -1 // haffman tree
#define MAXBIT		10   //define max length of haffman coding

typedef struct {
	int weight;
	int parent,lchild,rchild;
}haffman_tree_node_type;
typedef struct {
	int bit[MAXBIT];
	int start;

}haffman_code_type;

void haffman_tree(haffman_tree_node_type haffnode[],int *frequent){
	int i,j,m1,m2,x1,x2,n;
	n = 4;
	for(i = 0; i < 2 * n - 1; i++){ // initialize haffnode[]
		haffnode[i].weight = 0;
		haffnode[i].parent = -1;
		haffnode[i].lchild = -1;
		haffnode[i].rchild = -1;
	}
	for(i = 0; i < n; i++){
		haffnode[i].weight = frequent[i];
	}
	for(i = 0; i < n - 1; i++){
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for(j = 0; j < n + i; j++){
			if(haffnode[j].weight < m1 && haffnode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = haffnode[j].weight;
				x1 = j;
			}
			else if(haffnode[j].weight < m2 && haffnode[j].parent == -1){
				m2 = haffnode[j].weight;
				x2 = j;
			}
		}
			// two sub-tree merge into a tree
			haffnode[x1].parent = n + i;
			haffnode[x2].parent = n + i;
			haffnode[n + i].weight= haffnode[x1].weight + haffnode[x2].weight;
			printf("haffnode' lch is %d,rch is %d,parent = %d,weight=%d \n",frequent[x1],frequent[x2],n + i,haffnode[n + i].weight);
			haffnode[n + i].lchild = x1;
			haffnode[n + i].rchild = x2;
	}


}

void haffman_code(int *frequent){  // generate haffman code
	haffman_tree_node_type	haffnode[MAXNODE];
	haffman_code_type	haffcode[MAXLEAF],cd;
	int i,j,c,p,n = 4;
	haffman_tree(haffnode,frequent); // bulid haffman tree
	for(i = 0; i < n; i++){
		cd.start = n - 1;
		c = i;
		p = haffnode[c].parent;
		while(p != -1){
			if(haffnode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = haffnode[c].parent;
		}
		for(j = cd.start + 1;j < n; j++){
			haffcode[i].bit[j] = cd.bit[j];
			haffcode[i].start = cd.start;
		}
	}
	for(i = 0; i < n; i++){
		for(j = haffcode[i].start+1; j < n; j++)
			printf("%ld",haffcode[i].bit[j]);
		printf("\n");
	}

}
int main()
{
	int frequent[10] = {1,3,5,7};
	haffman_code(frequent);

}

