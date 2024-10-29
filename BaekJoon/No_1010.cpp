#include <iostream>

using namespace std;

long long fac(int n, int m);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;

    cout << fac(n, m) << "\n";
  }

  return 0;
}

long long fac(int n, int m){
  long long result = 1;

  for(int i = 1; i <= n; i++){
    result *= m;
    result /= i;
    m--;
  }

  return result;
}