#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N_max 300
//#define L 8e-1
#define b_max M_PI/18


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
 if(((S_DIS *)a)->y2 > ((S_DIS *)b)->y2) {return 1;}
 if(((S_DIS *)a)->y2 < ((S_DIS *)b)->y2) {return -1;}
 else return 0;
}

int show(S_DIS mat[N_max], int col, int row){
  int i, j;
  for(i=0;i<col;i++){
    printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%d",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
    printf("\n");
  }
printf("\n");
return 0;
}

int intersection(S_DIS mat[N_max], int i, int j)
{
  if(mat[i].x1 >= mat[i].x2){
  	if((mat[i].x1 < mat[j].x1 && mat[i].x2 < mat[j].x2) || (mat[i].x2 > mat[j].x1 && mat[i].x2 > mat[j].x2)){
        return 0;
	}
	else if((mat[i].x2 < mat[j].x1 && mat[i].x2 < mat[j].x2) || (mat[i].x1 > mat[j].x1 && mat[i].x1 > mat[j].x2)){
	return 0;
	}	
  }  

  
  if(mat[i].y1 >= mat[i].y2){
  	if((mat[i].y1 < mat[j].y1 && mat[i].y2 < mat[j].y2) || (mat[i].y2 > mat[j].y1 && mat[i].y2 > mat[j].y2)){
        	return 0;
	}
	else if((mat[i].y2 < mat[j].y1 && mat[i].y2 < mat[j].y2) || (mat[i].y1 > mat[j].y1 && mat[i].y1 > mat[j].y2)){
		return 0;
	}	
  }

  if(((mat[i].x1 - mat[i].x2)*(mat[j].y1 - mat[i].y1) + (mat[i].y1 - mat[i].y2)*(mat[i].x1 - mat[j].x1))*((mat[i].x1 - mat[i].x2)*(mat[j].y2 - mat[i].y1) + (mat[i].y1 - mat[i].y2)*(mat[i].x1 - mat[j].x2)) > 0){
	  return 0;
  }


  if(((mat[j].x1 - mat[j].x2)*(mat[i].y1 - mat[j].y1) + (mat[j].y1 - mat[j].y2)*(mat[j].x1 - mat[i].x1))*((mat[j].x1 - mat[j].x2)*(mat[i].y2 - mat[j].y1) + (mat[j].y1 - mat[j].y2)*(mat[j].x1 - mat[i].x2)) > 0){
	  return 0;
  }
 
 else return 1;
 

}


int main(void){

  srand((unsigned)time(NULL));

  int N;
  S_DIS mat[N_max];
  int col = N;
  int row = 5;
  double b;
  int p;
  int M = 1000;
  double P;
//  double L;
 

  p = 0;
//  L = 1e-1;

  FILE* fp0;
  fp0 = fopen("dis0_N160_10.dat", "w");
  if(fp0==NULL){
	  printf("File open faild");
  }

  N = 160;
  
 	 for(int i = 0; i < N/8; i++){
		
		double L = 0.1;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N/8; i < N/4; i++){
		
		double L = 0.2;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}
	
 	 for(int i = N/4; i < N*3/8; i++){
		
		double L = 0.3;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N*3/8; i < N/2; i++){
		
		double L = 0.4;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N/2; i < N*5/8; i++){
		
		double L = 0.5;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N*5/8; i < N*3/4; i++){
		
		double L = 0.6;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N*3/4; i < N*7/8; i++){
		
		double L = 0.7;
    		mat[i].conect = 0;
    		mat[i].x1 = (double)rand()/RAND_MAX;
    		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

  	}

 	 for(int i = N*7/8; i < N; i++){
		
		double L = 0.8;
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
	 	if(mat[i].y1 <= 0.3){
		 	mat[i].conect = 1;
	 	}
 	}


  	show(mat, N, row);
  	qsort(mat, col, sizeof(mat[0]), cmp);
  	show(mat, N, row);

  	for(int i = 0; i < N; i++){
	  	if(mat[i].conect == 1){
		  //mat[i].conect = 1;
		  	int j = i + 1;
		  	for(int k = j; j < N; j++){
			  	if(mat[j].conect == 0){
			  	mat[j].conect = intersection(mat, i, j);
			  	}
			 // else break;
	          	}
	  	}	
  	}

  //show(mat, col, row);

  
  	
 // P =(double)p / (double)M;
 // printf("P=%f\nn=%d\n",P,N);
  for(int i=0; i<N; i++){
  fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  }
  
 // p = 0;
 // L += 2.5e-2;
 


  fclose(fp0);

  return 0;
}
