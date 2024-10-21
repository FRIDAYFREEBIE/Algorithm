#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  unordered_map<int, int> numMap; // 빈도 맵
  vector<int> numVector(n);
  vector<int> resultVector(n, -1);

  for (int i = 0; i < n; i++){
    cin >> numVector[i];
    numMap[numVector[i]]++;
  }

  stack<pair<int, int>> frequencyStack; // 빈도 스택 (빈도, 숫자)

  for (int i = n - 1; i >= 0; i--){
    int currentNum = numVector[i]; // 현재 숫자
    int currentNumFrequency = numMap[numVector[i]]; // 현재 숫자의 빈도

    while(!frequencyStack.empty() && frequencyStack.top().first <= currentNumFrequency){
      frequencyStack.pop();
    }

    if(!frequencyStack.empty()){
      resultVector[i] = frequencyStack.top().second;
    }

    frequencyStack.push({currentNumFrequency, currentNum});
  }

  for (int i = 0; i < n; i++){
    cout << resultVector[i] << " ";
  }

  cout << "\n";

  return 0;
}
