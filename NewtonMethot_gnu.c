#include <stdio.h>
#include <math.h>
#define ESP 0.0001
#define NMAX 10000
#define alfa 0.1
FILE *gp;
double f( double x);
double df( double x);

int main(){
	double x, y=500000, delta,min,max,m;
	int i,a;
	int n=0;
		
	printf("範囲を入力\n最小値:");
	scanf("%lf",&min);
	printf("\n最大値:");
	scanf("%lf",&max);
	gp = popen("gnuplot -persist","w");
    fprintf(gp, "plot '-' with lines, '-' with lines, '-' with lines\n");
	
	while(min<=max){
		n=0;
		x=min;
		fprintf(gp, "%d\t%lf\n",n,x);
		//printf("初期値%lf",min);
	do {
		delta = -f(x) / df(x);	
		x += delta;		
		n++;				
		//printf( "n=%d, x=%f\n",n,x);	
		fprintf(gp, "%d\t%lf\n",n,x);	
	}while(fabs(delta) > ESP && n<= NMAX);

	if ( n==NMAX ) {printf("eroooooooor");
	}else {
		 if(fabs(x-y)>0.01) {printf("'%.2f ~ ",min);printf(" %f\n",x);}
		 y=x;
		 //fprintf(gp, "%lf\t%lf\n",min,x);
	}		
	min+=alfa;	
	fprintf(gp, "e\n");
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
