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
  int bLength = b.length();

  vector<vector<int>> dp(aLength + 1, vector<int>(bLength + 1, 0));

  for(int i = 1; i <= aLength; i++){
    for(int j = 1; j <= bLength; j++){
      if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // LCS 문자열 복원
  string lcs = "";
  int i = aLength, j = bLength;
  while(i > 0 && j > 0){
    if(a[i - 1] == b[j - 1]){
      lcs += a[i - 1];
      i--; j--;
    } 
    else if(dp[i - 1][j] > dp[i][j - 1]) i--;
    else j--;
  }

  reverse(lcs.begin(), lcs.end());

  cout << dp[aLength][bLength] << "\n" << lcs << "\n";

  return 0;
}
