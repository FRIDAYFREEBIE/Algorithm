#include <iostream>

using namespace std;

long long int divisor(long long int a, long long int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long int a, b;
  cin >> a >> b;

  cout << a * b / divisor(a, b);

  return 0;
}

long long int divisor(long long int a, long long int b){
  if(b == 0){
    return a;
  }
  else{
    return divisor(b, a % b);
  }
}