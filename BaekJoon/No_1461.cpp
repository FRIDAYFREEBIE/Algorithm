#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 0을 기준으로 벡터 2개 생성 후 정렬
// v1 = {-1} , v2 = {3 4 5 6 11}
// 2. 현재 위치를 기준으로 가장 먼 곳의 책을 최대 2(m)개를 먼저 정리

int n, m, cost;
vector<int> plusVector, minusVector;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for(int i = 0 ; i < n; i++){
    int temp;
    cin >> temp;

    if(temp < 0) minusVector.push_back((-temp));
    else plusVector.push_back(temp);
  }

  sort(minusVector.begin(), minusVector.end());
  sort(plusVector.begin(), plusVector.end());

  int maxDistance = 0;
  if(!minusVector.empty()) maxDistance = max(maxDistance, minusVector.back());
  if(!plusVector.empty()) maxDistance = max(maxDistance, plusVector.back());

  for(int i = minusVector.size() - 1; i >= 0; i-= m) cost += minusVector[i] * 2;
  for(int i = plusVector.size() - 1; i >= 0; i-= m) cost += plusVector[i] * 2;

  cout << cost - maxDistance << "\n";

  return 0;
}