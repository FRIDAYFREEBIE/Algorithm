#include <iostream>
#include <string>

using namespace std;

int n, m, cnt;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> s;


  for(int i = 0; i < m; i++){
    int length = 0;

    if(s[i] == 'O') continue;

    while(s[i + 1] == 'O' && s[i + 2] == 'I'){
      length++;

      if(length == n){
        length--;
        cnt++;
      }
      
      i+= 2;
    }

  }

  cout << cnt << "\n";

  return 0;
}
