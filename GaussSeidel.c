#include <stdio.h>
int main(){
    int i,j,k,n,Msize,Rc;
    double x[10];
    double y[10];
    double z[10];
    int a[10][10];
    int b[10];
    double ans;
    int flag=0;
    FILE *gp;//グラフの型
    
    //行列を入力----------------------------------------------------------------
    printf("Matrix size:"); 
    scanf("%d",&Msize);//行列サイズの入力
    printf("Please enter matrix a11-ann\n");
    printf("example\n a11 a12 a13 | b1\n a21 a22 a23 | b2\n a31 a32 a33 | b3\n");  
    for(j=1;j<=Msize;j++){
        for(k=1;k<=Msize;k++){
            printf("a%d%d:",j,k);
            scanf("%d",&a[j][k]);
        }
    }  
    printf("Please enter b1-bn\n"); 
    for(j=1;j<=Msize;j++){
        printf("b%d:",j);
        scanf("%d",&b[j]);
    }
    
    //入力した行列を表示-------------------------------------------------------------  
    for(j=1;j<=Msize;j++){
        for(k=1;k<=Msize;k++){
            printf("%d ",a[j][k]);
            if(k==Msize){
                printf("|%d\n",b[j]);
            }
    	}   
    }  
    
    //--------------------------------------------------------------------------- 
    printf("First value(x1,x2...xn):");
    scanf("%lf",&x[1]);//初期値の入力   
	for(j=1;j<=10;j++) x[j]=x[1];	 
    printf("Repeat count:");
    scanf("%d",&Rc);//繰り返し回数入力  
    printf("\nround 0	");//0回目の結果（初期値の表示）
    for(n=1;n<=Msize;n++) printf("  x%d:%.10f,",n,x[n]);
  
    //グラフセット--------------------------------------------------------------------
    gp = popen("gnuplot -persist","w");
    fprintf(gp, "set xrange [-i:i]\n");
    fprintf(gp, "plot '-' with lines lw 2, '-' with points lw 2\n");
    fprintf(gp, "0\t%lf\n",x[1]);
    
    //計算部分-----------------------------------------------------------------------
    for(i=1;i<=Rc;i++){
    	for(j=1;j<=Msize;j++){
     		ans=0;
        	for(k=1;k<=Msize;k++){
            	if(j!=k) ans +=x[k]*a[j][k];      
         	}        
        x[j]=(b[j]-ans)/a[j][j];
        
       	 if(i==Rc-1) {//最後の値と最後から二番目の値を各配列に代入
			y[j]=x[j];
		}else if(i==Rc) {
       		z[j]=x[j];		
       	}
       fprintf(gp, "%d\t%lf\n",i,x[1]);	      
     	}  
     	
   //結果表示--------------------------------------------------------------------------  
		printf("\n");
    	printf("round %d   ",i);   
    	for(n=1;n<=Msize;n++){
    		printf("  x%d:%.10f,",n,x[n]); //ｎ回目の結果表示   	
    	}    
	}
		
	for(n=1;n<=Msize;n++){//収束判定
		if(-00.1 <= z[n]-y[n] && z[n]-y[n] <=0.01){
		flag=1;
		}else{
		flag=0;
		break;
		}
	}
	
	if(flag==1) printf("\n収束しました\n");//結果表示
	else if(flag==0) printf("\n収束してません\n");
	//------------------------------------------------------------------------------ 
	fprintf(gp,"e\n");
    pclose(gp); 
}
