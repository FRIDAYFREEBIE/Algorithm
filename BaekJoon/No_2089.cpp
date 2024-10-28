#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> binaryVector;

  if(n == 0){
    cout << 0 << "\n";
    return 0;
  }

  while(n != 0){
    int remain = n % -2;
    n /= -2;

    if(remain < 0){
      remain += 2;
      n++;
    }

    binaryVector.push_back(remain);
  }

  for(int i = binaryVector.size() - 1; i >= 0; i--){
    cout << binaryVector[i];
  }

  return 0;
}