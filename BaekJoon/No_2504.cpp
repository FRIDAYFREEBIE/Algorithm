#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;

  int result = 0, temp = 1;
  stack<char> bracketStack;
  for(int i = 0; i < str.length(); i++){
    char current = str[i];

    if(current == '('){
      bracketStack.push(current);
      temp *= 2;
    }
    else if (current == '['){
      bracketStack.push(current);
      temp *= 3;  
    }
    else if (current == ')'){
      if (bracketStack.empty() || bracketStack.top() != '(') {
        result = 0;
        break;
      }

      if(str[i - 1] == '('){
        result += temp;
      }

      bracketStack.pop();
      temp /= 2;
    }
    else if (current == ']'){
      if (bracketStack.empty() || bracketStack.top() != '[') {
        result = 0;
        break;
      }

      if(str[i - 1] == '['){
        result += temp;
      }

      bracketStack.pop();
      temp /= 3;
    }
  }

  if(!bracketStack.empty()){
    result = 0;
  }

  cout << result << "\n";

  return 0;
}