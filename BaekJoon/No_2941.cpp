#include <iostream>

using namespace std;

string str;
int cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str;

  int length = str.size();
  for(int i = 0; i < length; i++){
    switch(str[i]){
    case 'd':
      if(str[i + 1] == 'z' && str[i + 1] == '='){
        cnt ++;
        i += 2;
        break;
      }
    
    default:
      cnt++;
      break;
    }
  }

  cout << cnt << "\n";

  return 0;
}