#include<stdlib.h>
#include<stdio.h>
#include<time.h>

double  randomm(int m, int M){
	return  m + (double)rand()/(double)(RAND_MAX/2); 
}

int main(int argc, char const *argv[]){
	if(argc==1){
	    printf("Enter number point\n");
	    return -1;
	}

	if(argc!=2){
	    printf("Argument is wrong\n");
	    return -1;
	}
	int N =atoi(argv[1]);
	double x= 0;
	double y= 0;
	int count;
	srand((int)time(NULL));
	for(int i = 0 ; i < N; i++){
		x = randomm(-1,1);
		y = randomm(-1,1);
		if(x*x+y*y<=1)count++;
	}
	double result =(double) 4.0*count/(double)N;
	printf("PI: %lf\n",result);

}