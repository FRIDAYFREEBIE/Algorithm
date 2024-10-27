#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int precedence(char c);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  queue<char> printQueue;
  stack<char> operatorStack;

  string infixString;
  cin >> infixString;

  for(int i = 0; i < infixString.length(); i++){
    char current = infixString[i];

    if(isalnum(current)){
      printQueue.push(current);
    }
    else if(current == '('){
      operatorStack.push(current);
    }
    else if(current == ')'){
      while (!operatorStack.empty() && operatorStack.top() != '('){
        printQueue.push(operatorStack.top());
        operatorStack.pop();
      }

      operatorStack.pop();
    }
    else{
      while(!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(current)){
        printQueue.push(operatorStack.top());
        operatorStack.pop();
      }

      operatorStack.push(current);
    }
  }

  while(!operatorStack.empty()){
    printQueue.push(operatorStack.top());
    operatorStack.pop();
  }

  while(!printQueue.empty()){
    cout << printQueue.front();
    printQueue.pop();
  }

  return 0;
}

int precedence(char c){
  if(c == '+' || c == '-'){
    return 1;
  }
  else if(c == '*' || c == '/'){
    return 2;
  }
  
  return 0;
}