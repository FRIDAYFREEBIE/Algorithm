#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  stack<int> currentStack; // 현재 줄
  stack<int> otherStack;   // 임시 줄
  int temp = 1; // 차례

  // 벡터 -> 줄 스택
  for(int i = n - 1; i >= 0; i--){
    currentStack.push(v[i]);
  }

  while(!currentStack.empty() || !otherStack.empty()){
    // 현재 줄에서 간식
    if (!currentStack.empty() && currentStack.top() == temp){
      currentStack.pop();
      temp++;
    }
    // 임시 줄에서 간식
    else if(!otherStack.empty() && otherStack.top() == temp){
      otherStack.pop();
      temp++;
    }
    // 간식을 줄 수 없다면 현재 줄 -> 임시 줄
    else if(!currentStack.empty()){
      otherStack.push(currentStack.top());
      currentStack.pop();
    }
    else{
      break;
    }
  }

  if(temp == n + 1){
    cout << "Nice" << "\n";
  }
  else{
    cout << "Sad" << "\n";
  }

  return 0;
}
