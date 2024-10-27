#include <iostream>

using namespace std;

int divisor(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int x, y;

  x = (a * d) + (c * b);
  y = b * d;

  int gcd = divisor(x, y);
  x /= gcd;
  y /= gcd;

  cout << x << " " << y << "\n";

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