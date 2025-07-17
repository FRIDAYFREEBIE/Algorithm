#include <iostream>

using namespace std;

int main(){
  cout << "정수를 입력하시오: ";

  int n;
  cin >> n;

  long ans = 1;
  for(int i = 1; i <= n; i++){
    ans *= i;
  }

  cout << ans << "\n";  

  return 0;
}