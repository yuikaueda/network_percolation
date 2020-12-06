#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N 150
#define L 2e-1
#define b_max M_PI/2
#define RAN 100
#define t_max 100
#define step 100
#define k_on 0.3
#define k_off 0.7


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
/*
int show(S_DIS mat[N], const int col, const int row){
  int i, j;
  for(i=0;i<col;i++){
    printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%d",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
    printf("\n");
  }
printf("\n");
return 0;
}
*/

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

  srand((unsigned)time(NULL));

  S_DIS mat[N];
  int col = N;
  int row = 5;
  double b;
  int M = 1;
  double P_a[t_max];
  double P_b[t_max];
  double p_a;
  double p_b;
  int check[N];


  FILE* fp0;
  fp0 = fopen("petern_ab03.dat" , "w");
  if(fp0==NULL){
	  printf("File open faild.");
  }

  
  for(int i=0; i<t_max; i++){
		  	P_a[i] = 0;
			P_b[i] = 0;
  }


  for(int step_n = 0; step_n < step; step_n++){

	for(int i = 0; i < 10; i++){
	      mat[i].conect = 1;
      	      mat[i].x1 = 0.5;
	      mat[i].y1 = 0;
              	      
    	      b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    	      mat[i].x2 = mat[i].x1 + L*sin(b);
    	      mat[i].y2 = mat[i].y1 + L*cos(b);
        }


	for(int i = 10; i < 20; i++){
	      mat[i].conect = 0;
      	      mat[i].x2 = 0.5;
	      mat[i].y2 = 1;
              	      
    	      b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    	      mat[i].x1 = mat[i].x2 + L*sin(b);
    	      mat[i].y1 = mat[i].y2 - L*cos(b);
        }

	for(int i = 20; i < 30; i++){
	      mat[i].conect = 0;
      	      mat[i].x1 = 1;
	      mat[i].y1 = 0.3;
              	      
    	      b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    	      mat[i].x2 = mat[i].x1 - L*cos(b);
    	      mat[i].y2 = mat[i].y1 + L*sin(b);
        }

  	for(int i = 30; i < N; i++){

   	    	mat[i].conect = 0;
		mat[i].x1 = (double)rand()/RAND_MAX;
		mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

	        //fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
	        //printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	}

	      // printf("\n");

  	for(int t_run = 0; t_run < t_max; t_run++){

  			/*
 			for(int i = 0; i < N; i++){
	 			if(mat[i].y1 <= 0.2){
		 		mat[i].conect = 1;
	 			}
 			}
			*/
  			//qsort(mat, col, sizeof(mat[0]), cmp);
			
			for(int i = 10; i < N; i++){
				mat[i].conect = 0;
			}
			
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

  		for(int i = 10; i < 20; i++){
	  		if(mat[i].conect == 1){
	  	  		P_a[t_run] += 1;
				break;	
			}	
  		}

  		for(int i = 20; i < 30; i++){
	  		if(mat[i].conect == 1){
	  	  		P_b[t_run] += 1;
				break;	
			}	
  		}
  		for(int i = 30; i < N; i++){
			mat[i].conect = 0;
			check[i] == 0;
			for(int j = 0; j < N; j++){
				if(i != j){
					 check[i] = intersection(mat, i, j);
						if(check[i] == 1){
							break;	
						}
				}
			}
			if(check[i] == 0){

					mat[i].x1 = (double)rand()/RAND_MAX;
					mat[i].y1 = (double)rand()/RAND_MAX;
    
    					b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    					mat[i].x2 = mat[i].x1 + L*sin(b);
    					mat[i].y2 = mat[i].y1 + L*cos(b);
                                	//printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
			}

			if(check[i] == 1){

					double value = Uniform();
					//printf("%f\n",value);
					if(value < k_off / (k_on + k_off)){
						mat[i].x1 = (double)rand()/RAND_MAX;
						mat[i].y1 = (double)rand()/RAND_MAX;
    
    						b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    						mat[i].x2 = mat[i].x1 + L*sin(b);
    						mat[i].y2 = mat[i].y1 + L*cos(b);
						break;
				  	}
	        
				// fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
			}
		}
  	}
/*
  	for(int i = 0; i < N; i++){
  	fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	//printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	}
*/
  }


  for(int i = 0; i < t_max; i++){
	  p_a = (double)P_a[i]/(double)step;
	  p_b = (double)P_b[i]/(double)step;
	  fprintf(fp0, "%d\t%f\t%f\n",i,p_a,p_b);
	  printf("t=%d\tP_a=%f\tP_b=%f\n",i,p_a,p_b);

  }

  fclose(fp0);
  return 0;

}
