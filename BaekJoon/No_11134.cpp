#include <iostream>

using namespace std;

int main(void){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n, c, t;
  cin >> t;
  
  while (t--){
    cin >> n >> c;
    if (n%c == 0) cout << n / c << '\n';
    else cout << n / c + 1 << '\n';
  }

  return 0;
}