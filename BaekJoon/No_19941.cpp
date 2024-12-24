#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  string str;

  cin >> n >> k >> str;

  int ans = 0;
  for(int i = 0; i < n; i++){
    if(str[i] != 'P') continue;

    bool isFind = false;
    for(int len = k; len >= 1; --len){
      if(i - len < 0) continue;

      if(str[i - len] == 'H'){
        ans++;
        isFind = true;
        str[i - len] = '.';
        break;
      }
    }

    if(!isFind){
      for(int len = 1; len <= k; len++){
        if(i + len >= n) continue;

        if(str[i + len] == 'H'){
          ans++;
          str[i + len] = '.';
          break;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}