#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, j;
  cin >> n >> m >> j;

  int s = 0, e = 0, ans = 0;
  for(int i = 0; i < j; i++){
    int temp;
    cin >> temp;

    e = s + m;

    if(s < temp && temp <= e) continue;

    if(temp <= s){
      ans += s - temp + 1;
      s -= s - temp + 1;
    }
    else{
      ans += temp - e;
      s += temp - e;
    }
  }

  cout << ans << "\n";

  return 0;
}