#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, b;
  cin >> n >> b;

  string result = "";
  while(n > 0){
    int temp = n % b;

    if(temp < 10){ // 수 -> 문자
      result = char(temp + '0') + result;
    }
    else{
      result = char(temp - 10 + 'A') + result;
    }

    n /= b;
  }

  cout << result << "\n";

  return 0;
}