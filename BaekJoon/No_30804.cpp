#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  vector<int> fruits(n);
  for(int i = 0; i < n; ++i) cin >> fruits[i];

  // 과일 갯수
  unordered_map<int, int> typeCount;
  int left = 0, maxLength = 0, typeCnt = 0;
  for(int right = 0; right < n; right++){
    // 오른쪽
    typeCount[fruits[right]]++;

    if(typeCount[fruits[right]] == 1) typeCnt++;
    
    // 슬라이딩 윈도우 (왼쪽 하나 이동)
    while(typeCnt > 2){
      typeCount[fruits[left]]--;
      if(typeCount[fruits[left]] == 0) typeCnt--;
      left++;
    }

    maxLength = max(maxLength, right - left + 1);
  }

  cout << maxLength << "\n";

  return 0;
}