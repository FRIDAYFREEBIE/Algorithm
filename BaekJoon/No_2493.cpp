#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;  
  cin >> n;

  vector<int> towerVector(n);
  for(int i = 0; i < n; i++){
    cin >> towerVector[i];
  }

  vector<int> printVector(n);
  stack<pair<int, int>> towerStack;
  
  for (int i = 0; i < n; i++){
    // 타워 스택의 맨 위가 현재 타워보다 높을 때 까지
    while(!towerStack.empty() && towerStack.top().first < towerVector[i]){
      towerStack.pop();
    }
    
    if(!towerStack.empty()){
      printVector[i] = towerStack.top().second + 1;
    }
    else{
      printVector[i] = 0;
    }

    // 현재 타워를 타워 스택에 삽입
    towerStack.push({towerVector[i], i});
  }

  for(auto &v : printVector){
    cout << v << " ";
  }

  cout << "\n";

  return 0;
}