#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;

  stack<char> stick;
  int result = 0;

  for(int i = 0; i < str.size(); i++){
    if(str[i] == '(' && str[i + 1] == ')'){
      result += stick.size();
      i++;
    }
    else if(str[i] == '('){
      stick.push(str[i]);
    }
    else if(str[i] == ')'){
      result ++;
      stick.pop();
    }
  }

  cout << result << "\n";
  
  return 0;
}