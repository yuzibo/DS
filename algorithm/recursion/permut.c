/* 给定一个字符串，打印出他的全排列
*  比如：
*    ABC ACB BAC BCA CBA CAB
*
*   主题： 全排列的应用
*/

#include <stdio.h>
#include <string.h>

/*使用两个指针交换字符*/
void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
/*打印全排列使用三个参数：
* 1: String
* 2. 字符串开始的索引
* 3. 字符串结束的索引
*/
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			/* 测试用的
			printf("此时的l等于%d， i为%d：\n", l, i);
			printf("此时的a[%d]=%c,a[%d]=%c\n",l, a[l], i, a[i]);
			*/
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i)); /*回溯*/
		}
	}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n - 1);
	return 0;
}
