#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);

  int n;
  long long result = 0;

  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    // (n / i): i가 약수로 몇 번 들어가는가
    // * i: 들어간 횟수 * i
    result += (n / i) * i;
  }

  cout << result << "\n";

  return 0;
}