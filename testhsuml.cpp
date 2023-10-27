#include <iostream>
using namespace std;

struct Number{
  float value;

    float sum(Number &){
      return value + value;
    }
};
 
int main(){
  Number H;
  Number L;
  H.value = 6;
  L.value = 9;

  cout<< H.sum(L) <<endl;
  system("pause");
}

// 