#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 보석 N개, 무게 M, 가격 V, 가방 K개, 가방의 무게 C를 고려하여 훔칠 수 있는 부석의 최대 가격 구하기(최대 1개의 보석을 넣을 수 있음)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 보석과 가방의 갯수
  int n, k;
  cin >> n >> k;

  // 보석
  vector<pair<int, int>> jewel; // <무게, 가격>
  for(int i = 0; i < n; i++){
    int m, v;
    cin >> m >> v;

    jewel.push_back({m, v});
  }

  sort(jewel.begin(), jewel.end());

  // 가방
  vector<int> bag(k);
  for(int i = 0; i < k; i++){
    cin >> bag[i];
  }

  sort(bag.begin(), bag.end());

  // jewel: {99, 2}, {23, 5}, {65, 1}
  // bag: 2, 10

  // if(bag[bagIndex] >= jewel[jewelIndex]) bagIndex++
  // else jewelIndex++

  long long result = 0;
  priority_queue<int> pq;
  int jewelIndex = 0;
  for(int bagIndex = 0; bagIndex < k; bagIndex++){
    // 용량 제한
    while(jewelIndex < n && bag[bagIndex] >= jewel[jewelIndex].first){
      pq.push(jewel[jewelIndex].second);
      jewelIndex++;
    }

    if(!pq.empty()){
      result += pq.top();
      pq.pop();
    }
  }

  cout << result << "\n";

  return 0;
}