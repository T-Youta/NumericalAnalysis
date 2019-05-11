#include <stdio.h>

int main()
{
int i,j,k,n;
double x1, x2, x3;

int a[3][3];
int b[3];
double get_x1;
double get_x2;
double get_x3;

printf("行列の値を入力\n");
for(j=1;j<=3;j++){
	for(k=1;k<=3;k++){
		printf("a%d%d:",j,k);
		scanf("%d",&a[j][k]);
	}
}

for(j=1;j<=3;j++){
		printf("b%d:",j);
		scanf("%d",&b[j]);	
}

printf("初期値:");
scanf("%lf",&x1);
x2=x1,x3=x1;

printf("繰り返し:");
scanf("%d",&n);

printf("\nround 0, x1:%12.10f,x2:%12.10f,x3:%12.10f\n",x1,x2,x3);


for(i=1;i<n;i++)
{
get_x1=((b[1] -x2*a[1][2] -x3*a[1][3])/a[1][1]);

get_x2=((b[2] -x1*a[2][1] -x3*a[2][3])/a[2][2]);

get_x3=((b[3] -x1*a[3][1] -x2*a[3][2])/a[3][3]);

printf("round %d, x1:%12.10f,x2:%12.10f,x3:%12.10f\n",i,x1,x2,x3);

x1=get_x1,x2=get_x2,x3=get_x3;
}
}
