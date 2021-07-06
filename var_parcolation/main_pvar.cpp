#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N 250
#define L 2e-1
#define L0 2e-1
#define b_max M_PI/2
#define b_min M_PI/6
#define RAN 100
#define t_max 1000
#define step 100
#define k0_on 0.35
#define kc_on 20
#define k0_off 0.2
#define f 1e-3
#define N_best 250
#define A 0.01
#define B 5
#define thea_max 0.8

double Uniform(){
	return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}


typedef struct{

  double x1;
  double x2;
  double y1;
  double y2;
  int    conect_a;
  int	   conect_b;
  int    conect_aa;
  int    conect_bb;

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
  int N_a;
  int N_b;
  double N_c[step][t_max];
  double N_cc[step][t_max];
  double n_c;
  double n_cc;
  double k_on;
  double k_off;
  double th_cos[N];

  int run_num = 1;

  FILE* fp0;
  fp0 = fopen("t1000_n250_a001_b5.dat" , "w");
  if(fp0==NULL){
	  printf("File open faild.");
  }

  
  for(int i=0; i<t_max; i++){
		  	P_a[i] = 0;
			  P_b[i] = 0;
  }

  
  printf("start");
  for(int step_n = 0; step_n < step; step_n++){
      run_num += 1;
      printf("%d\n",run_num);

	for(int i = 0; i < 10; i++){
	      mat[i].conect_a = 1;
        mat[i].conect_aa = 0;
	      mat[i].conect_b = 0;
        mat[i].conect_bb = 0;
      	mat[i].x1 = 0.5;
	      mat[i].y1 = 0;
              	      
    	  b = b_min*(-1 + 2*((double)rand()/RAND_MAX));
    
    	  mat[i].x2 = mat[i].x1 + L0*sin(b);
    	  mat[i].y2 = mat[i].y1 + L0*cos(b);
        th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
  }


	for(int i = 10; i < 20; i++){
	      mat[i].conect_a = 0;
        mat[i].conect_aa = 0;
	      mat[i].conect_b = 1;
        mat[i].conect_bb = 0;
      	mat[i].x2 = 0.5;
	      mat[i].y2 = 1.0;
              	      
    	  b = b_min*(-1 + 2*((double)rand()/RAND_MAX));
    
    	  mat[i].x1 = mat[i].x2 + L0*sin(b);
    	  mat[i].y1 = mat[i].y2 - L0*cos(b);
        th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
  }
/*
	for(int i = 10; i < 20; i++){
	      mat[i].conect_a = 0;
        mat[i].conect_b = 1;
      	mat[i].x1 = 1;
	      mat[i].y1 = 0.3;
              	      
    	  b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    	  mat[i].x2 = mat[i].x1 - L*cos(b);
    	  mat[i].y2 = mat[i].y1 + L*sin(b); 
  }
*/
  	for(int i = 20; i < N; i++){

   	    mat[i].conect_a = 0;
        mat[i].conect_aa = 0;
		    mat[i].conect_b = 0;
        mat[i].conect_bb = 0;
		    mat[i].x1 = (double)rand()/RAND_MAX;
		    mat[i].y1 = (double)rand()/RAND_MAX;
    
    		b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    		mat[i].x2 = mat[i].x1 + L*sin(b);
    		mat[i].y2 = mat[i].y1 + L*cos(b);

        th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
	        //fprintf(fp0, "%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
	        //printf("%f\t%f\t%f\t%f\t%d\n",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
  	}

	      // printf("\n");

  	for(int t_run = 0; t_run < t_max; t_run++){

      //N_c[t_run] = 0;
      //N_cc[t_run] = 0;
  			/*
 			for(int i = 0; i < N; i++){
	 			if(mat[i].y1 <= 0.2){
		 		mat[i].conect = 1;
	 			}
 			}
			*/
  			//qsort(mat, col, sizeof(mat[0]), cmp);
			
			for(int i = 0; i < 10; i++){
				mat[i].conect_b = 0;
        mat[i].conect_bb = 0;
			}

			for(int i = 10; i < 20; i++){
				mat[i].conect_a = 0;
        mat[i].conect_aa = 0;
			}

			for(int i = 20; i < N; i++){
				mat[i].conect_a = 0;
        mat[i].conect_aa = 0;
				mat[i].conect_b = 0;
        mat[i].conect_bb = 0;
        
        if(mat[i].x1 < 0 || mat[i].x2 < 0){
          mat[i].conect_aa = 1;
        }
        if(mat[i].x2 > 1 || mat[i].x1 > 1){
          mat[i].conect_bb = 1;
        }
			}
			
  			for(int k = 0; k < RAN; k++){
  				for(int i = 0; i < N; i++){
            if(th_cos[i] > thea_max){
		  			  if(mat[i].conect_a == 1){
			  			  for(int j = 0; j < N; j++){
				  			  if(th_cos[j] > thea_max && mat[j].conect_a == 0){
			  				    mat[j].conect_a = intersection(mat, i, j);
			  				  }
	          		}
	  				  }

					    if(mat[i].conect_b == 1){
			  			  for(int j = 0; j < N; j++){
				  			  if(th_cos[j] > thea_max && mat[j].conect_b == 0){
			  				    mat[j].conect_b = intersection(mat, i, j);  	
							    }
						    }
					    }
  				  }

		  		  if(mat[i].conect_aa == 1){
			  			for(int j = 0; j < N; j++){
				  			if(mat[j].conect_aa == 0){
			  				  mat[j].conect_aa = intersection(mat, i, j);
			  				}
			 			// else break;
	          	}
	  			  }

					  if(mat[i].conect_bb == 1){
			  			for(int j = 0; j < N; j++){
				  			if(mat[j].conect_bb == 0){
			  				  mat[j].conect_bb = intersection(mat, i, j);  	
						  	}
						  }
					  }

          }
  			}
  			//show(mat, col, row);

  		for(int i = 0; i < N; i++){
	  		if(mat[i].conect_a == 1 && mat[i].conect_b ==1){
	  	  		P_a[t_run] += 1;
				    break;	
			}	
  		}

  		for(int i = 0; i < N; i++){
	  		if(mat[i].conect_aa == 1 && mat[i].conect_bb ==1){
	  	  		P_b[t_run] += 1;
				    break;	
			  }	
  		}
/*
  		for(int i = 20; i < 30; i++){
	  		if(mat[i].conect == 1){
	  	  		P_b[t_run] += 1;
				break;	
			}	
  		}
*/
   
      for(int i = 0; i < N; i++){
        if(mat[i].conect_a == 1 && mat[i].conect_b == 1){
          N_c[step_n][t_run] += 1;
        }
      }
      for(int i = 0; i < N; i++){
        if(mat[i].conect_aa == 1 && mat[i].conect_bb == 1){
          N_cc[step_n][t_run] += 1;
        }
      }
      N_cc[step_n][t_run] -= N_c[step_n][t_run];

 /*
		N_a = 0;
		//N_b = 0;
		for(int i = 0; i < N; i++){
			if(mat[i].conect_a == 1){
				N_a += 1;
			}
      //if(mat[i].conect_b == 1){
         // N_b += 1;
			//}

		}
		//printf("N_a=%d\tN_b=%d\n",N_a,N_b);
*/
      double k_on_n = B*k0_on*exp(A*(N_best - N_c[step_n][t_run]));
      double k_off_n = k0_off*exp(A*(N_c[step_n][t_run] - N_best));
      //printf("n=%f\tkon=%f\tkoff=%f\n",N_best - N_c[step_n][t_run],k_on_n,k_off_n);
			for(int i = 20; i < N; i++){
				if(mat[i].conect_a == 1 && mat[i].conect_b == 1){
          k_on = k_on_n;
          k_off = k_off_n;
					double value = Uniform();
					if(value < k_off / (k_on + k_off)){
						mat[i].x1 = (double)rand()/RAND_MAX;
						mat[i].y1 = (double)rand()/RAND_MAX;
    
    				b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    				mat[i].x2 = mat[i].x1 + L*sin(b);
    				mat[i].y2 = mat[i].y1 + L*cos(b);
            th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
					}
        /*  
          else{
          
					k_on = k_on_n;
          k_off = k_off_n;
					double value = Uniform();
					if(value < k_off / (k_on + k_off)){
						mat[i].x1 = (double)rand()/RAND_MAX;
						mat[i].y1 = (double)rand()/RAND_MAX;
    
    						b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    						mat[i].x2 = mat[i].x1 + L*sin(b);
    						mat[i].y2 = mat[i].y1 + L*cos(b);
                th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
          }
         
      }
      */
          /*else{
            
    						b = b_min*(-1 + 2*((double)rand()/RAND_MAX));
    
    						mat[i].x2 = mat[i].x1 + L*sin(b);
    						mat[i].y2 = mat[i].y1 + L*cos(b);
                th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
          }
         */ 
			}else{
					k_on = k0_on;
          k_off = k0_off;
					double value = Uniform();	
					if(value < k_off / (k_on + k_off)){
						mat[i].x1 = (double)rand()/RAND_MAX;
						mat[i].y1 = (double)rand()/RAND_MAX;
    
    				b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    				mat[i].x2 = mat[i].x1 + L*sin(b);
    				mat[i].y2 = mat[i].y1 + L*cos(b);
            th_cos[i] = (mat[i].y2 - mat[i].y1)/L;
					}
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
/*
  for(int i = 0; i < N; i++){
     printf("cos=%f\n",th_cos[i]);
  }
*/

  
  for(int i = 0; i < t_max; i++){
    double Ncc = 0;
    double Nc = 0;
    for(int j = 0; j < step; j++){
      Ncc += N_cc[j][i];
      Nc += N_c[j][i];
    }
	  p_a = (double)P_a[i]/(double)step;
    n_cc = (double)Ncc/(double)step;
    n_c = (double)Nc/(double)step;
	  p_b = (double)P_b[i]/(double)step;
	  //fprintf(fp0, "%d\t%f\t%f\n",i,p_a,p_b);
	  //printf("t=%d\tP_a=%f\tP_b=%f\n",i,p_a,p_b);

	  fprintf(fp0, "%d\t%f\t%f\t%f\t%f\n",i,p_a,p_b,n_c,n_cc);
	  printf("t=%d\tP_a=%f\tP_b=%f\tnc=%f\tncc=%f\n",i,p_a,p_b,n_c,n_cc);
  }

  fclose(fp0);
  return 0;

}
