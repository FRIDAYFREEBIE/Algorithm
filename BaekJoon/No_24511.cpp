#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> structureVector(n); // 0 큐 1 스택
  for(auto &i : structureVector){
    cin >> i;
  }

  deque<int> queueStack; // 큐스택
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    
    if(structureVector[i] == 0){
      queueStack.push_back(temp);
    }
  }

  int m;
  cin >> m;

  for(int i = 0; i < m; i++){
    int num;
    cin >> num;

    queueStack.push_front(num);
    cout << queueStack.back() << " ";
    queueStack.pop_back();
  }

  return 0;
} 