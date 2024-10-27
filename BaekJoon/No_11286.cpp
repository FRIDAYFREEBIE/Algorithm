#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct custom{
  bool operator()(int a, int b){
    if(abs(a) == abs(b)){ // 절댓값이 같다면
      return a > b; // 작은 거
    }
    else{ 
      return abs(a) > abs(b); // 절댓값이 작은거
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<int, vector<int>, custom> absoluteQueue;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    if(temp != 0){
      absoluteQueue.push(temp);
    }
    else{
      if(!absoluteQueue.empty()){
        cout << absoluteQueue.top() << "\n";
        absoluteQueue.pop();
      }
      else{
        cout << 0 << "\n";
      }
    }
  }

  return 0;
}
