#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.0001 
#define NMAX 1000             
FILE *gp;
double f(double x);
void nibun(void); 

int main(){
	gp = popen("gnuplot -persist","w");
	fprintf(gp, "plot '-' with lines lw 2, '-' with points lw 2\n");	
       
        nibun();

        return 0;
}

void nibun(void){
        int n;
        double a,b,c;
        n=0;
        printf("範囲の左の値を入力.\n");
        scanf("%lf",&a);
        printf("範囲の右の値を入力.\n");
        scanf("%lf",&b);

        do {
                n++;
                c=(a+b)/2.0;
                if(f(c)*f(a)<0) b=c;
                else a=c;
                printf( "n=%d, x=%f\n",n,c);
				fprintf(gp, "%d\t%lf\n",n,c);

                if(n==NMAX) {
                        printf("error\n");
                        exit(1);
                }
        } while (fabs(a-b)>EPS);  
                  
        printf("解の値: %f	 回数:%d.",c,n);
}

double f(double x){
	return (x*x-2);
}
