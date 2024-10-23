#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  string postfixString;
  cin >> postfixString;

  vector<double> numVector(n);
  for (int i = 0; i < n; i++) {
    cin >> numVector[i];
  }

  stack<double> numStack;

  for (int i = 0; i < postfixString.length(); i++){
    char ch = postfixString[i];

    if (ch == '+'){
      double b = numStack.top(); numStack.pop();
      double a = numStack.top(); numStack.pop();
      numStack.push(a + b);
    } 
    else if (ch == '-'){
      double b = numStack.top(); numStack.pop();
      double a = numStack.top(); numStack.pop();
      numStack.push(a - b);
    } 
    else if (ch == '*'){
      double b = numStack.top(); numStack.pop();
      double a = numStack.top(); numStack.pop();
      numStack.push(a * b);
    } 
    else if (ch == '/'){
      double b = numStack.top(); numStack.pop();
      double a = numStack.top(); numStack.pop();
      numStack.push(a / b);
    } 
    else{
      int index = ch - 'A';
      numStack.push(numVector[index]);
    }
  }

    double result = numStack.top();
    printf("%.2f\n", result);

    return 0;
}
