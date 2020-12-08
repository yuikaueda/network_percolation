#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N 100
#define L 5e-1
//#define b_max M_PI/2
#define RAN 100

typedef struct{

  double x1;
  double x2;
  double y1;
  double y2;
  int    conect;
}S_DIS;

int cmp(const void *a, const void *b){
 // return *(int*)b - *(int*)a;
 //const double *x, *y;

 //x = (double*) a;
 //y = (double*) b;
 if(((S_DIS *)a)->y1 > ((S_DIS *)b)->y1) {return 1;}
 if(((S_DIS *)a)->y1 < ((S_DIS *)b)->y1) {return -1;}
 else return 0;
}

int show(S_DIS mat[N], const int col, const int row){
  int i, j;
  for(i=0;i<col;i++){
    printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%d",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
    printf("\n");
  }
printf("\n");
return 0;
}

int intersection(S_DIS mat[N], int i, int j)
{
/*	
  if(mat[i].x1 >= mat[i].x2){
  	if((mat[i].x1 < mat[j].x1 && mat[i].x1 < mat[j].x2) || (mat[i].x2 > mat[j].x1 && mat[i].x2 > mat[j].x2)){
        return 0;
	}
	else if((mat[i].x2 < mat[j].x1 && mat[i].x2 < mat[j].x2) || (mat[i].x1 > mat[j].x1 && mat[i].x1 > mat[j].x2)){
	return 0;
	}	
  }  

  
  if(mat[i].y1 >= mat[i].y2){
  	if((mat[i].y1 < mat[j].y1 && mat[i].y1 < mat[j].y2) || (mat[i].y2 > mat[j].y1 && mat[i].y2 > mat[j].y2)){
        	return 0;
	}
	else if((mat[i].y2 < mat[j].y1 && mat[i].y2 < mat[j].y2) || (mat[i].y1 > mat[j].y1 && mat[i].y1 > mat[j].y2)){
		return 0;
	}	
  }
*/
  if(((mat[i].x1 - mat[i].x2)*(mat[j].y1 - mat[i].y1) + (mat[i].y1 - mat[i].y2)*(mat[i].x1 - mat[j].x1))*((mat[i].x1 - mat[i].x2)*(mat[j].y2 - mat[i].y1) + (mat[i].y1 - mat[i].y2)*(mat[i].x1 - mat[j].x2)) > 0){
	  return 0;
  }


  if(((mat[j].x1 - mat[j].x2)*(mat[i].y1 - mat[j].y1) + (mat[j].y1 - mat[j].y2)*(mat[j].x1 - mat[i].x1))*((mat[j].x1 - mat[j].x2)*(mat[i].y2 - mat[j].y1) + (mat[j].y1 - mat[j].y2)*(mat[j].x1 - mat[i].x2)) > 0){
	  return 0;
  }
 
 return 1;
 

}


int main(void){

 /* srand((unsigned)time(NULL));
*/
  S_DIS mat[N];
  int col = N;
  int row = 5;
  double b;
  int p;
  int M = 1000;
  double P;
  double b_max;

  p = 0;
  b_max = M_PI/18;

  FILE* fp0;
  fp0 = fopen("pp_05.dat" , "w");
  if(fp0==NULL){
	  printf("File open faild.");
  }

  for(int b_run = 1; b_run < 18; b_run++){
	  for(int k = 0; k < M; k++){
  		for(int i = 0; i < N; i++){

   	    		mat[i].conect = 0;
	    		mat[i].x1 = (double)rand()/RAND_MAX;
	    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    			b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    			mat[i].x2 = mat[i].x1 + L*sin(b);
    			mat[i].y2 = mat[i].y1 + L*cos(b);

  		}

/*
 mat[0].x1 = 0;
 mat[0].x2 = 0.5;
 mat[0].y1 = 0;
 mat[0].y2 = 0.5;
 mat[0].conect = 0;
 mat[1].x1 = 0.4;
 mat[1].x2 = 0.4;
 mat[1].y1 = 0.4;
 mat[1].y2 = 1;
 mat[1].conect = 0;
*/
  
 	for(int i = 0; i < N; i++){
	 	if(mat[i].y1 <= 0.2){
		 	mat[i].conect = 1;
	 	}
 	}


  //show(mat, col, row);
  	qsort(mat, col, sizeof(mat[0]), cmp);
  //show(mat, col, row);

  	for(int k = 0; k < RAN; k++){
  		for(int i = 0; i < N; i++){
		  	if(mat[i].conect == 1){
		  	//mat[i].conect = 1;
		  	//int j = i + 1;
			  	for(int j = 0; j < N; j++){
				  	if(mat[j].conect == 0){
			  		mat[j].conect = intersection(mat, i, j);
			  		}
			 	// else break;
	          		}
	  		}
  		}
  	}
  	//show(mat, col, row);

  	for(int i = 0; i < N; i++){
	  	if(mat[i].conect == 1)
	  	  	p += 1;  	  	
  	}
  
	}
	double MN = (double)M*(double)N;
  	P =(double)p / (double)MN;
  	printf("P=%f\nb=%f\n",P,b_max);

	fprintf(fp0, "%f\t%f\n",b_max,P);

	p = 0;
	b_max += M_PI/36;

  }
  fclose(fp0);
  return 0;

}
