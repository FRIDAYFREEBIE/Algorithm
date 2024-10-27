#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  getline(cin, str);

  for(int i = 0; i < str.length(); i++){
    char temp = str[i];

    if(temp >= 'a' && temp <= 'z'){
      if(temp - 'a' < 13){
        temp += 13;
      }
      else{
        temp -= 13;
      }
    }
    else if(temp >= 'A' && temp <= 'Z'){
      if(temp - 'A' < 13){
        temp += 13;
      }
      else {
        temp -= 13;
      }
    }

      str[i] = temp;
    }
    
    cout << str << "\n";

  return 0;
}