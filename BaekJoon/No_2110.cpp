#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, c;
  cin >> n >> c;

  vector<int> houseVector(n);
  for(int i = 0; i < n; i++){
    cin >> houseVector[i];
  }

  sort(houseVector.begin(), houseVector.end());

  int start = 1, end = houseVector[n -1] - houseVector[0], result = 0;
  while(start <= end){
    int mid = (start + end) / 2;

    int routerCnt = 1, temp = houseVector[0];
    for(int i = 1; i < n; i++){
      // 집 사이의 간격이 mid보다 크거나 같다면
      if(houseVector[i] - temp >= mid){
        routerCnt++;
        temp = houseVector[i];
      }
    }

    // c보다 많은 공유기를 사용했다면
    if(routerCnt >= c){
      result = mid;
      start = mid + 1;
    }
    else{
      end = mid - 1;
    }
  }

  cout << result << "\n";

  return 0;
}