/**重新写haffmancode **/
#include <stdio.h>
#include <stdlib.h>

/* 树的深度*/
#define MAX_TREE_HT	100

/*huffman tree node */
struct min_heap_node {
	char data;   /* 输入的字符*/
	unsigned freq; /* 字符的频率*/
	struct min_heap_node *left, *right;
};
/* A min heap: */
struct min_heap{
	unsigned size; /*Current size of min heap*/
	unsigned capacity; /* capacity of min heap */
	struct min_heap_node **array; /*minheap node pointers */
};


int is_leaf(struct min_heap_node*);

/* 分配一个新的小堆节点，字符参数为's',和频率的条件下*/
struct min_heap_node* new_node(char data, unsigned freq)
{
	struct min_heap_node* temp =
		(struct min_heap_node *)malloc(sizeof(struct min_heap_node));
		temp->left = temp->right = NULL;
		temp->data = data;
		temp->freq = freq;
		return temp;
}
/* 创造小堆在给定容量的情况下*/
struct min_heap* create_min_heap(unsigned capacity)
{
	struct min_heap* create_heap =
		(struct min_heap*) malloc(sizeof(struct min_heap));
		create_heap->size = 0; /* current size is 0*/
		create_heap->capacity = capacity;
		create_heap->array =
			(struct min_heap_node**)malloc(create_heap->capacity * sizeof(struct min_heap_node*));
		return  create_heap;
}
void swap_min_heap_node(struct min_heap_node** a, struct min_heap_node** b)
{
	struct min_heap_node* t = *a;
	*a = *b;
	*b = t;
}
/* standard minheapify function or called heap_sort better */
/* 应该被称作为heap_sort,*/
/*参数为一个堆和一个起始点*/
void min_heap_modify(struct min_heap* heap , int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
/* 在范围内左孩子的频率小于当前的频率*/
	if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
		smallest = left;
/* 在范围内右孩子的频率小于当前的频率*/
	if (right < heap->size &&
		heap->array[right]->freq < heap->array[smallest]->freq)
		smallest = right;
/*当上面的两个条件之一发生时*/
	if (smallest != idx)
	{
		swap_min_heap_node(&heap->array[smallest], &heap->array[idx]);
		min_heap_modify(heap, smallest); /*怎么使用了递归*/

	}
}
/*检查堆的大小是否为1 */
int is_sizeone(struct min_heap* heap)
{
	return (heap->size == 1);
}
/*从一个堆中抽取最小的值*/
struct min_heap_node* extraact_min(struct min_heap* heap)
{
	/*关键这里设置了min_heap_node*让heap->array[0]指向*/
	/*把这个最小值取出后，用次小项去填充它，同时这个heap的size要减1*/
	struct min_heap_node* temp = heap->array[0];
	heap->array[0] = heap->array[heap->size - 1];
	--heap->size;
	/*再一次保持堆的特性*/
	min_heap_modify(heap, 0);
	return temp;
}
/*向一个堆中插入一个新的min heap， minHeapNode为新产生的节点，heap为存在的堆*/
void insert_min_heap(struct min_heap* heap, struct min_heap_node* minHeapNode)
{
	/*首先堆的大小加1 */
	++heap->size;
	int i = heap->size - 1;
	/*这个控制语句还是有些难度的，为什么会在这里进行比较呢*/
	while(i && minHeapNode->freq < heap->array[(i - 1)/2] -> freq){
		heap->array[i] = heap->array[(i - 1)/2];
		i = (i -1)/2;
	}
	heap->array[i] = minHeapNode;
}
/* build min heap,参数是已经初始化完成后的*/
/*这里就是使用的堆排序
* 请参考：https://github.com/yuzibo/DS/blob/master/sort/heapsort.c
* 个人觉得下面的min_heap_modify 修改为 heap_sort更为合适
*/
void build_min_heap(struct min_heap* heap){
	int n = heap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
			min_heap_modify(heap, i);
}

/* for语句是初始化的核心，隐约能感觉到为什么使用二级指针了*/
/* 每个 heap ->array[i]中存在huffman_tree的节点
* create_heap_and_build_heap 叫做初始化函数更合适
*/
struct min_heap* create_heap_and_build_heap(char data[], int freq[], int size)
{/* create_min_heap 更名为申请节点比较好*/
	struct min_heap* heap = create_min_heap(size);
	int i;
	for (i = 0; i < size; ++i)
		heap->array[i] = new_node(data[i], freq[i]);
	heap->size = size;
	/*初始化完成后,开始按照规则建树, create_min_heap
	修改成 <del>init_min_heap更好理解一些*/
	build_min_heap(heap);
	return heap;
}
/* build huffman */
struct min_heap_node* build_huffman_tree(char data[], int freq[], int size)
{
	struct min_heap_node *left, *right, *top;
	struct min_heap* minheap = create_heap_and_build_heap(data, freq, size);
	/*一个结束的标志*/
	while(!is_sizeone(minheap)){
		left = extraact_min(minheap);
		right = extraact_min(minheap);
		top = new_node('s', left->freq + right->freq);
		top->left = left;
		top->right = right;
		/*左节点和右节点结合产生的内部节点*/
		insert_min_heap(minheap, top);
	}
	return extraact_min(minheap);
}
/******
* 从这里开始，最优树已经完成了，接下来进行
* 编码的工作
****/
/* 打印其中一个元素的编码*/
void print_arr(int arr[], int n)
{
	int i;
	for( i = 0; i < n ; ++i)
		printf("%d ",arr[i] );
	printf("\n");
}
/*打印huffman编码，从root，使用arr[] to store codes*/
/*这里还是用了一个递归打印*/
/* 中序遍历*/
void print_code(struct min_heap_node* root, int arr[], int top)
{
	if  (root->left){
		arr[top] = 0;
		/* 为什么top加1 ？？*/
		print_code(root->left, arr, top + 1);
	}
	if (root->right){
		arr[top] = 1;
		print_code(root->right, arr, top + 1);
	}
	if(is_leaf(root)){
		printf("%c:",root->data );
		print_arr(arr, top);
	}

}


/* 检查是否为叶子结点*/
int is_leaf(struct min_heap_node* root)
{
	return !(root->left) && !(root->right);
}
void huffman_code(char data[], int freq[], int size)
{
	struct min_heap_node* root = build_huffman_tree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	print_code(root, arr, top);
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd','e','f','g','h'};
	int freq[] = {2, 3, 6,7,10,19,21,32};
	int size = sizeof(arr)/sizeof(arr[0]);
	huffman_code(arr, freq, size);
	return 0;
}
