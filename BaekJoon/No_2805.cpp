#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  int max = 0;
  vector<int> treeVector(n);
  for(int i = 0; i < n; i++){
    cin >> treeVector[i];

    // 가장 큰 나무
    if(treeVector[i] > max){
      max = treeVector[i];
    }
  }

  // 이분탐색
  int start = 0, end = max, result = 0;
  while(start <= end){
    int mid = (start + end) / 2;

    long long sum = 0;
    for(int i = 0; i < n; i++){
      // 나무가 mid보다 클 때만
      if(treeVector[i] - mid > 0){
        sum += treeVector[i] - mid;
      }
    }

    if(sum >= m){
      result = mid;
      start = mid + 1; // 높이 높이기
    }
    else {
      end = mid - 1; // 높이 낮추기
    }
  }

  cout << result << "\n";

  return 0;
}