#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<int> minHeap; // 최대 힙

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    
    if(temp == 0){
      if(!minHeap.empty()){ // 최대 힙이 비어있지 않다면
        cout << minHeap.top() << "\n";
        minHeap.pop();
      }
      else{
        cout << 0 << "\n";
      }
    }
    else{
      minHeap.push(temp);
    }

  }

  return 0;
}
