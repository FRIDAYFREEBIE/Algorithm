#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  cin.ignore();

  for(int i = 0; i < n; i++){
    string str;
    getline(cin, str);

    str += ' ';

    stack<char> s;

    for(int j = 0; j < str.size(); j++){
      if(str[j] == ' '){
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }
        cout << ' ';
      }
      else{
        s.push(str[j]);
      }
    }

    cout << '\n';
  }

  return 0;
}