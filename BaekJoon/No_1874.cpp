#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  stack<int> stack;
  stack.push(0);

  int index = 1;
  bool isVaild = true;

  vector<char> vector;
  
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;

    while(stack.top() < num){
      stack.push(index);

      index++;

      vector.push_back('+');
    }

    if(stack.top() == num){
      stack.pop();

      vector.push_back('-');
    }
    else{
      isVaild = false;
    }
  }

  if(isVaild){
    for(auto c : vector){
      cout << c << "\n";
    }
  }
  else{
    cout << "NO" << "\n";
  }

  return 0;
}