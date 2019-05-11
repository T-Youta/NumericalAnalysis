#include <stdio.h>
#include <math.h>
FILE *gp;

int main(){
	int x = 0;
	double y=0;
	gp = popen("gnuplot -persist","w");
    fprintf(gp, "plot '-' with lines lw 2, '-' with points lw 2\n");
    
    while(x<10){
    x+=1;
    y+=5;
    printf( "x=%d, y=%f\n",x,y);
	fprintf(gp, "%d\t%lf\n",x,y);
	
	
	}

pclose(gp);
return 0;
}

