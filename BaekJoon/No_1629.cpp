#include <iostream>

using namespace std;

long long fun(long long a, long long b, long long c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  cout << fun(a, b, c) << "\n";

  return 0;
}

long long fun(long long a, long long b, long long c){
  if(b == 0){
    return 1;
  }

  long long temp = fun(a, b / 2, c);
  temp = (temp * temp) % c;

  if(b % 2 != 0){
    temp = (temp * a) % c;
  }

  return temp;
}