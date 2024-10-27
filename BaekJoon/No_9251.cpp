#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;

  int aLength = a.length();
  int blength = b.length();

  vector<vector<int>> strVector(aLength + 1, vector<int>(blength + 1, 0)); // 2차원 벡터

  for(int i = 1; i <= aLength; i++){
    for(int j = 1; j <= blength; j++){
      if(a[i - 1] == b[j - 1]){
        strVector[i][j] = strVector[i - 1][j - 1] + 1;
      }
      else{
        strVector[i][j] = max(strVector[i - 1][j], strVector[i][j - 1]);
      }
    }
  }

  cout << strVector[aLength][blength] << "\n";

  return 0;
} 