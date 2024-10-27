#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct custom{
  bool operator()(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second){ // 값 기준
      return a.second > b.second;
    }
    else{ // 인덱스 기준
      return a.first > b.first;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  priority_queue<pair<int, int>, vector<pair<int, int>>, custom> numQueue; // <인덱스, 값>

  int n, l;
  cin >> n >> l;

  for(int i = 0; i < n; i ++){
    int temp;
    cin >> temp;

    numQueue.push(make_pair(i, temp));

    while(numQueue.top().first <= i - l){
      numQueue.pop();
    }

    cout << numQueue.top().second << "\n";
  }

  return 0;
}