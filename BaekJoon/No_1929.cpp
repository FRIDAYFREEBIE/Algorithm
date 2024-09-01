#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);

  int m, n;
  bool isDecimal;

  cin >> m >> n;

  for(int i = m; i <= n; i++){
    isDecimal = true;

    for(int j = 2; j < i; j++){
      if(i % j == 0)
        isDecimal = false;
    }

    if(isDecimal)
      cout << i << "\n";
  }

  return 0;
}