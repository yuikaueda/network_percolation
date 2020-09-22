#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<array>
#include<string>
#include<fstream>

#define N 5
#define L 5e-2
#define b_max M_PI/3


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

int show(S_DIS mat[5], const int col, const int row){
  int i, j;
  for(i=0;i<col;i++){
    printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%d",mat[i].x1,mat[i].x2,mat[i].y1,mat[i].y2,mat[i].conect);
    printf("\n");
  }
printf("\n");
return 0;
}


int main(void){

  srand((unsigned)time(NULL));

  S_DIS mat[5];
  int col = 5;
  int row = N;
  double b;

 /* for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
     mat[i][j] = 0;
    }
  }*/

  for(int i = 0; i < N; i++){

    mat[i].conect = 0;
    mat[i].x1 = (double)rand()/RAND_MAX;
    mat[i].y1 = (double)rand()/RAND_MAX;
    
    b = b_max*(-1 + 2*((double)rand()/RAND_MAX));
    
    mat[i].x2 = mat[i].x1 + L*sin(b);
    mat[i].y2 = mat[i].y1 + L*cos(b);

  }

  


  show(mat, col, row);
  qsort(mat, col, sizeof(mat[0]), cmp);
  show(mat, col, row);

  return 0;

}
