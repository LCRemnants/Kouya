#include<stdio.h>
int n;
int r[600]= {0};
int count(n) {
	int i;
	for(i=0; i<600; i++)
		r[i]*=n;
	for(i=599; i>0; i--) {
		r[i-1]=r[i-1]+r[i]/10;
		r[i]=r[i]%10;
	}
}

int main() {
	int i;
	int reach=0;
	r[599]=1;
	printf("请输入一个数字（小于298，大于等于0）：");
back:	
	scanf("%d",&n);
	if(n>297||n<0){
		printf("对不起，您的输入不对！\n请重新输入：");
		goto back; 
	} 
	for(i=1; i<=n; i++)
		count(i);
	printf("%d的阶乘为",n);
	for(i=0; i<600; i++) {
		if(r[i]) reach=1;
		if(r[i]||reach) printf("%d",r[i]);
	}
	getchar();
	getchar();
}
