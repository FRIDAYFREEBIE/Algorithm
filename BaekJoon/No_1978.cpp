#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);

  int n, cnt = 0;
  bool isDecimal = true;

  cin >> n;

  for(int i = 0; i < n; i++){
    isDecimal = true;
    
    int temp;

    cin >> temp;

    for(int j = 2; j < temp; j++)
    {
      // 소수가 아니라면 isDecimal = false
      if(temp % j == 0)
        isDecimal = false;
    }

    if(isDecimal && temp != 1)
      cnt++;
  }

  cout << cnt << "\n";

  return 0;
}