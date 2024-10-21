#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned int k, n, result = 0;
  cin >> k >> n;

  unsigned int maxLength = 0;

  vector<unsigned int> lanVector;
  for(int i = 0; i < k; i++){
    unsigned int temp;
    cin >> temp;

    lanVector.push_back(temp);

    if(temp >= maxLength){
      maxLength = temp;
    }
  }
  
  unsigned int left = 1, right = maxLength, mid = 0;

  // 이분탐색
  while(left <= right){
    mid = (left + right) / 2;
    unsigned temp = 0;
    for(auto &a : lanVector){
      temp += a / mid;
    }

    if(temp >= n){
      left = mid + 1;
      result = max(result, mid);
    }
    else{
      right = mid - 1;
    }
  }

  cout << result << "\n";

  return 0;
}