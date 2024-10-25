#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string n;
  int b;
  cin >> n >> b;

  int result = 0;
  for(int i = 0; i < n.length(); i++){
    if ('0' <= n[i] && n[i] <= '9'){ // 수
      result = result * b + (n[i] - '0');
    } 
    else{ // 문자열
      result = result * b + (n[i] - 'A' + 10);
    }
  }

  cout << result << "\n";

  return 0;
}