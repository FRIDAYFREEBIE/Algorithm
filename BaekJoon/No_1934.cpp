#include <iostream>

using namespace std;

int divisor(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, a, b;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a >> b;

    cout << a * b / divisor(a, b) << "\n";
  }

  return 0;
}

int divisor(int a, int b){
  if(b == 0){
    return a;
  }
  else{
    return divisor(b, a % b);
  }
}