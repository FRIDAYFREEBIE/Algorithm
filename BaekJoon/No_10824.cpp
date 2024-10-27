#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  string num1 = to_string(a) + to_string(b);
  string num2 = to_string(c) + to_string(d);
              
  long long result = stoll(num1)+stoll(num2);
  cout << result << "\n";

  return 0;
}