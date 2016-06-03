/*************************************************************************
     File Name: fp.c
     Author: Bo Yu
     Mail: tsu.yubo@gmail.com
     Created Time: 2016年06月02日 星期四 23时54分14秒
 ************************************************************************/

#include<stdio.h>

/*在函数中改变a，将不会带回主调函数（主调函数中仍是a的原值）*/
void fa(int a){
	a = 5;
	printf("在函数fa中：a = %d\n",a);
}
/*a 为指针类型，在函数中改变a的值，改变后的值将带回主调函数*/
void fb(int *a){
	*a = 5;
	printf("在函数fb中，*a = %d\n",*a);
}
int main()
{
	int n = 1;
	printf("在主程序中，调用函数fa之前:n = %d\n",n);
	fa(n);
	printf("在主程序中，调用函数fa之前、fb之前：n = %d\n",n);
	fb(&n);
	printf("在主程序中，调用函数fb之前：n = %d\n",n);
}


