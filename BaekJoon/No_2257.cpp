#include <iostream>
#include <stack>
#include <string>

using namespace std;

// H = 1, C = 12, O = 16
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;

  stack<int> strStack; // 화학식 스택
  for(auto &c : str){
    // 숫자
    if (c >= '2' && c <= '9') {
      int temp = strStack.top();
      strStack.pop();
      strStack.push(temp * (c - '0'));
    }
    // 여는 괄호
    else if(c == '('){
      strStack.push(-1);
    }
    // 닫는 괄호
    else if(c == ')'){ 
      int temp = 0;

      while(strStack.top() != -1){
        temp += strStack.top();
        strStack.pop();
      }

      strStack.pop();
      strStack.push(temp);
    }
    // 화학식
    else{
      if(c == 'H'){
        strStack.push(1);
      }
      else if(c == 'C'){
        strStack.push(12);
      }
      else if(c == 'O'){
        strStack.push(16);
      }
    }
  }

  int result = 0;
  while(!strStack.empty()){
    result += strStack.top();
    strStack.pop();
  }

  cout << result << "\n";

  return 0;
}