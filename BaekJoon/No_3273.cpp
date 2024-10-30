#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> numVector(n);
  for(int i = 0; i < n; i++){
    cin >> numVector[i];
  }

  int x;
  cin >> x;

  sort(numVector.begin(), numVector.end());

  // 투 포인터
  int left = 0, right = n -1, pairCnt = 0;

  while(left < right){
    int sum = numVector[left] + numVector[right];

    if(sum < x){
      left ++;
    }
    else if(sum > x){
      right --;
    }
    else{
      pairCnt ++;
      left ++;
      right --;
    }
  }

  cout << pairCnt << "\n";

  return 0;
}