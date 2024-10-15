#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str = " ";

  while (true) {
    getline(cin, str);
    
    if (str == ".") break;

    stack<char> s;
    bool isBalanced = true;

    for (int i = 0; i < str.size(); i++) {
      char ch = str[i];

      if (ch == '(' || ch == '[') {
        s.push(ch);
      }
      else if (ch == ')') {
        if (s.empty() || s.top() != '(') {
          isBalanced = false;
          break;
        }

        s.pop();
      }
      else if (ch == ']') {
        if (s.empty() || s.top() != '[') {
          isBalanced = false;
          break;
        }

        s.pop();
      }
    }

    if (!s.empty()) {
      isBalanced = false;
    }

    if (isBalanced) {
      cout << "yes" << "\n";
    }
    else {
      cout << "no" << "\n";
    }
  }

  return 0;
}
