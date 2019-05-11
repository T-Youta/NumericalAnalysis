#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define NMAX 10000
#define alfa 0.1
FILE *gp;
double f( double x);
double df( double x);

int main(){
	double x, y=x+10000, delta,min,max,m;
	int i,a;
	int n=0;
	
	printf("範囲を入力\n最小値:");
	scanf("%lf",&min);
	printf("\n最大値:");
	scanf("%lf",&max);
	gp = popen("gnuplot -persist","w");
    fprintf(gp, "plot '-' with points lw 2\n");
	
	while(min<=max){
		x=min;
	do {
		delta = -f(x) / df(x);	
		x += delta;		
		n++;							
	}while(fabs(delta) > EPS && n<= NMAX);

		if ( n==NMAX ) {
			printf("error");
		}else {
				if(fabs(x-y)>0.01) printf("X0:%.2f ~	x=%f\n",min,x);//解表示
		 	y=x;//前の値を保存
		 	fprintf(gp, "%lf\t%lf\n",min,x);
		}		
	min+=alfa;//次の初期値へ
	}
	pclose(gp);
	return 0;
}
double f( double x){
return (x*x*x -2*x*x -x +2);
}

double df( double x){
return (3*x*x -4*x -1);
}

