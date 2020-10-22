#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N 10
#define L 3e-1
#define b_max M_PI/2
#define RAN 100
#define t_max 1
#define step 1
#define k_on 0.7
#define k_off 0.3


double Uniform(){
	return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}


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
  int M = 1;
  double P[t_max];
  double p;
  int check;


  FILE* fp0;
  fp0 = fopen("test10.dat" , "w");
  if(fp0==NULL){
	  printf("File open faild.");
  }

  
  	for(int i=0; i<t_max; i++){
		  	P[i] = 0;
  	}


  for(int step_n = 0; step_n < step; step_n++){

  	for(int i = 0; i < N; i++){

   	    	mat[i].conect = 0;
		mat[i].x1 = (double)rand()/RAND_MAX;
		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

	       // fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
	       printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	}

	       printf("\n");

  	for(int t_run = 0; t_run < t_max; t_run++){

  
 			for(int i = 0; i < N; i++){
	 			if(mat[i].y1 <= 0.2){
		 		mat[i].conect = 1;
	 			}
 			}

  			qsort(mat, col, sizeof(mat[0]), cmp);

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

  		for(int i = N-1; i >= 0; i--){
	  		if(mat[i].conect == 1){
	  	  		P[t_run] += 1;
				break;	
			}	
  		}

  		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(i != j){
					 check = intersection(mat, i, j);
						if(check == 1){
							break;
				  		}
				}
			}
			if(check == 1){
				double value = Uniform();
				if(value < k_off / (k_on + k_off)){
			
   	    				mat[i].conect = 0;
					mat[i].x1 = 0;
					//mat[i].y1 = (double)rand()/RAND_MAX;
    
    					b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    					mat[i].x2 = mat[i].x1 + L*sin(b);
    					//mat[i].y2 = mat[i].y1 + L*cos(b);
                                	printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
			
				}
			}
			if(check == 0){

   	    				mat[i].conect = 0;
					mat[i].x1 = 0;
					//mat[i].y1 = (double)rand()/RAND_MAX;
    
    					b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    					mat[i].x2 = mat[i].x1 + L*sin(b);
    					//mat[i].y2 = mat[i].y1 + L*cos(b);
                                	printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
			}

	               // fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].y1,mat[i].x2,mat[i].y2,mat[i].conect);
		}
  	}

  	for(int i = 0; i < N; i++){
  	fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	//printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	}

  }


  for(int i = 0; i < t_max; i++){
	  p = P[i]/step;
	  //fprintf(fp0, "%d\t%f\n",i,P);
	 // printf("t=%d\tP=%f\n",i,P);

  }

  fclose(fp0);
  return 0;

}
