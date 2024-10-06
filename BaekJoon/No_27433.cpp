#include <iostream>

using namespace std;

long long int func(int n) {
  if (n <= 1) return 1;
  return n * func(n - 1);
}

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  cout << func(n) << "\n";
  return 0;
}