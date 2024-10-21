#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  double n;
  cin >> n;

  double numSum = 0;
  int max = -4000, min = 4000;

  vector<int> numVector;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    numSum += temp;
    numVector.push_back(temp);

    if(temp >= max){
      max = temp;
    }
    
    if(temp <= min){
      min = temp;
    }
  }

  // 산술평균
  double average = round(numSum / n);

  if(average == -0){
    average = 0;
  }

  cout << average << "\n";

  // 중앙값
  vector<int> tempVector = numVector;
  sort(tempVector.begin(), tempVector.end());

  double centerNum = tempVector[round(n / 2) - 1];

  cout << centerNum << "\n";

  // 최빈값
  unordered_map<int, int> mostMap;
  vector<int> mostVector;

  // 빈도
  for(auto &a : numVector){
    mostMap[a]++;
  }

  // 최대 빈도
  int maxCnt = 0;
  for(auto &a : mostMap){
    if(a.second >= maxCnt){
      maxCnt = a.second;
    }
  }

  for(auto &a : mostMap){
    if(a.second == maxCnt){
      mostVector.push_back(a.first);
    }
  }

  sort(mostVector.begin(), mostVector.end());

  if(mostVector.size() > 1){
    cout << mostVector[1] << "\n";
  }
  else{
    cout << mostVector[0] << "\n";
  }

  // 범위
  cout << max - min << "\n";

  return 0;
}