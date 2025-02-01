#include <iostream>

using namespace std;

int n;
long long x[100000],y[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

  x[n] = x[0];
  y[n] = y[0];

  double result = 0;
  for(int i = 0; i <= n; i++) result += ((x[i] * y[i + 1]) - (x[i + 1] * y[i]));

  cout << fixed;
  cout.precision(1);
  cout << abs(result) / 2.0 <<endl;

  return 0;
}