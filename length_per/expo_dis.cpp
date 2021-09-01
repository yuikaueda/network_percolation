#include<random>
#include<fstream>

double round_n(double number, double e_n){
  number = number*pow(10,e_n-1);
  number = round(number);
  number /= pow(10, e_n-1);
  return number;
}

int main()
{
  std::random_device rd;
  std::default_random_engine engine(rd());

  std::exponential_distribution<> dist(2.0);

  for(std::size_t i = 0; i < 10; ++i){
    double result = dist(engine);
    double round_result = round_n(result,2.0);
    printf("%f\n",round_result);
  }

  return 0;
}
