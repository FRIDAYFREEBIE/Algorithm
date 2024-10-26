#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int result = 0, dot = 2;
  for(int i = 0; i < n; i++){
    dot = dot * 2 - 1;
    result = dot * dot;
  }

  cout << result << "\n";

  return 0;
}