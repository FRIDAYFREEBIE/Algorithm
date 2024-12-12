#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;
  str += ' ';

  string result;
  int cnt = 0;
  for(int i = 0; i < str.size() - 1; i++){
    if(str[i] == 'X') cnt++;

    if(cnt == 2 && str[i + 1] != 'X'){
      result += "BB";
      cnt = 0;
    }

    if(cnt == 4){
      result += "AAAA";
      cnt = 0;
    }

    if(str[i] == '.'){
      if(cnt % 2 == 1){
        cout << -1 << "\n";
        return 0;
      }

      result += '.';
      cnt = 0;
    }
  }

  if(cnt != 0) cout << -1 << "\n";
  else cout << result << "\n";

  return 0;
}