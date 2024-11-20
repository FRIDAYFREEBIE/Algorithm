#include <iostream>
#include <string>

using namespace std;

int cnt = 0;
string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str;

  int length = str.size();
  for (int i = 0; i < length; i++){
    if (str[i] == 'd' && i + 2 < length && str[i + 1] == 'z' && str[i + 2] == '='){
      cnt++;
      i += 2;
    }
    else if (str[i] == 'd' && i + 1 < length && str[i + 1] == '-'){
      cnt++;
      i++;
    }
    else if (str[i] == 'c' && i + 1 < length && (str[i + 1] == '=' || str[i + 1] == '-')){
      cnt++;
      i++;
    }
    else if ((str[i] == 'l' || str[i] == 'n') && i + 1 < length && str[i + 1] == 'j'){
      cnt++;
      i++;
    }
    else if ((str[i] == 's' || str[i] == 'z') && i + 1 < length && str[i + 1] == '='){
      cnt++;
      i++;
    } 
    else 
      cnt++;
  }

  cout << cnt << "\n";

  return 0;
}
