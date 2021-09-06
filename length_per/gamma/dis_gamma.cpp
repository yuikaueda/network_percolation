#include<random>
#include<fstream>
#include<iostream>
#include<iomanip>

#define sigma 0.1
#define k 4.0
#define ex_n 5.0

double round_n(double number, double e_n){
  number = number*pow(10,e_n-1);
  number = round(number);
  number /= pow(10, e_n-1);
  return number;
}

int main()
{
  FILE* fp0;
  char filename[256];
  sprintf(filename,"len_gamma_k%.1f_sig%.1f.dat",k,sigma);
  if((fp0 = fopen(filename,"w")) == NULL){printf("FAILED TO OPEN FILE.\n"); exit(1);};

  std::random_device rd;
  std::default_random_engine engine(rd());

  std::gamma_distribution<> dist(k, sigma);
  double L_total = 0.0;
  int N = 0;
  while(L_total < 40.0){
    N += 1;
    double result = dist(engine);
    double round_result = round_n(result,ex_n);

    while(round_result > 0.60 || round_result <= 0.0){
      double result2 = dist(engine);
      round_result = round_n(result2,ex_n);
    }
    L_total += round_result;
    fprintf(fp0,"%f\n",round_result);
    //printf("%f\n",round_result);
  }
  fclose(fp0);

  printf("N=%d\n",N);
  return 0;
}
