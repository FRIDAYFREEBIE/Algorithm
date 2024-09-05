#include <iostream>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int  n; 

  cin >> n;

  if(n == 0){
    cout << 1 << "\n";
    return 0;
  }

  int result = 1;

  for(int i = 1; i <= n; i++){
    result *= i;
  }
  
  cout << result << "\n";

  return 0;
}