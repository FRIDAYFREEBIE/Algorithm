#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  queue<int> numQueue;
  for(int i = 1; i <= n; i++){
    numQueue.push(i);
  }

  while(true){
    cout << numQueue.front() << " ";
    numQueue.pop();

    if(numQueue.empty()){
      break;
    }

    int temp = numQueue.front();
    numQueue.pop();
    numQueue.push(temp);
  }

  return 0;
}