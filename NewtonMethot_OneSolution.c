#include <stdio.h>
#include <math.h>
#define EPS 0.0001
#define NMAX 100
FILE *gp;

double f( double x);
double df( double x);

int main(){
	int n = 0;
	double x, delta;
		
	printf("input initial:");
	scanf("%lf",&x);
	
	gp = popen("gnuplot -persist","w");
    fprintf(gp, "plot '-' with lines lw 2, '-' with points lw 2\n");
    fprintf(gp, "0\t%lf\n",x);
	
	do {
		delta = -f(x) / df(x);	
		x += delta;
		n++;
		printf( "n=%d, x=%f\n",n,x);
		fprintf(gp, "%d\t%lf\n",n,x);
		
	}while(fabs(delta) > EPS && n<= NMAX);
	
	if ( n==NMAX ) printf("error");
	else printf("x = %f\n",x);
	
	pclose(gp);
	return 0;
	}
	
	
double f( double x){
return (x*x+3*x+8);
}

double df( double x){
return (2*x+3);
}
