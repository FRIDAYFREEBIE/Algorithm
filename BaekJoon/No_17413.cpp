#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  getline(cin, str);

  stack<char> s;
  
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '<'){
      while(!s.empty()){
        cout << s.top();
       s.pop();
      }
      
      while(str[i] != '>'){
        cout << str[i];
        i++;
      }

      cout << ">";
    }
    else{
      if(str[i] != ' '){
        s.push(str[i]);
      }
      else{
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }

        cout << " ";
      }
    }
  }

  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }

  cout << "\n";
  
  return 0;
}