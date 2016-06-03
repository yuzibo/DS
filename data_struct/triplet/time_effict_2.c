/*************************************************************************
     File Name: time_effict_2.c
     Author: Bo Yu
     Mail: tsu.yubo@gmail.com
     Created Time: 2016年06月03日 星期五 00时29分12秒
 ************************************************************************/

#include<stdio.h>
#include<sys/timeb.h>
int main()
{
	struct  timeb t1,t2;
	long t = 0;
	double x, sum1 = 1,sum = 1;
	int i,n;
	printf("请输入x,n:\n");
	scanf("%lf%d",&x,&n);
	ftime(&t1);
	for(i = 1; i <= n; i++){
		sum1 = (-sum1/x);
		sum += sum1;
	}
	ftime(&t2);
	/*计算时间差*/
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
	printf("sum = %lf 用时%ld毫秒\n",sum, t);

}
