/*
 *     File Name: quick_sort.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2017年12月07日 星期四 21时54分47秒
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define element_type int


int N,MAX_NUM;/* N 是要排序的数组个数，　MAX是这个数组的最大元素*/
/*
 * 自动化填充数据，你可以指定需要排序的数量N和最大的数字MAX_NUM
 * 接下来，该函数会调用随机化函数自动生成N个数据，而且这些数据皆
 * 小于MAX_NUM
 *
 * @retrun: 该函数返回一个整型数组，没有使用全局变量的方法
 *
 */
int *input_array()
{
	printf("请输入数组个数N及最大的数字MAX,中间以空格分开\n");
	scanf("%d %d", &N, &MAX_NUM);
	int i;
	srand(time(NULL));
	int *new_array = (int *)malloc(sizeof(int) * N + 1);
	if (new_array == NULL)
		return NULL;
	for(i = 0; i < N; i++)
	{

		new_array[i] = rand()%MAX_NUM;
	}
	return new_array;
}

/* 交换两个元素的值
 * 在c语言中的应用
 * */
void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

/**
 * 下面的函数是寻找一个枢点元素(pivot),这样可以把
 * 要排序的数组分成小于pivot和大于pivot  的两个子序列
 * 以最后一个元素为pivot.
 * 请注意，这个数组是从下标0开始计数的,返回值就是pivot
 * 最终在数组中的位置
 */
int spilt(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	for (j = low; j <= high - 1; j++){
		if (array[j] <= pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[high]);
	return i + 1;
}
/**
 * 利用分治法进行排序
 * 算法思想分别阐述
 * 在找出 pivot的情况下，分别递归调用quick_sort算法
 *
 */
void quick_sort(int *array, int low, int high)
{
 	if (low < high){
	int 	k = spilt(array, low, high);
		quick_sort(array, low, k-1);
		quick_sort(array, k+1, high);

	}
}

/*
 * 将打印函数格式化输出，方便调用
 *
 */
void output_array(int *arr, int start, int end)
{
	int j;
	for(j = start; j < end; j++)
		printf(" %d ", arr[j]);
	printf("\n");
}
int main()
{
	/* 声明一个int *的整型变量，来接受input_array函数产生的数组*/
	int *array;
	array = input_array();

	printf("排序前的数组:\n");
	output_array(array, 0, N);

	quick_sort(array, 0, N - 1);

	printf("排序后的数组:\n");
	output_array(array, 0, N);
}
