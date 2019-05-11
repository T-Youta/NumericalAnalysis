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

printf("a行列の値を入力\n");
printf(" a11 a12 a13 | b1\n a21 a22 a23 | b2\n a31 a32 a33 | b3\n");
for(j=1;j<4;j++){
	for(k=1;k<4;k++){
		printf("a%d%d:",j,k);
		scanf("%d",&a[j][k]);
	}
}

printf("b1-b3の値を入力\n");
printf(" a11 a12 a13 | b1\n a21 a22 a23 | b2\n a31 a32 a33 | b3\n");
for(j=1;j<4;j++){
		printf("b%d:",j);
		scanf("%d",&b[j]);	
}

for(j=1;j<4;j++){
printf("%d ",a[1][j]);
}
printf("|%d\n",b[1]);
for(j=1;j<4;j++){
printf("%d ",a[2][j]);}
printf("|%d\n",b[2]);
for(j=1;j<4;j++){
printf("%d ",a[3][j]);}
printf("|%d\n",b[3]);

printf("first value(x1,x2,x3):");
scanf("%lf",&x1);
x2=x1,x3=x1;

printf("kurikaesisuu:");
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
