#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;

  vector<long long> v(n);
  cin >> v[0];

  // 누적합
  for(int i = 1; i < n; i++){
    long long temp;
    cin >> temp;

    v[i] = v[i - 1] + temp;
  }

  int minLength = n + 1, start = 0, end = 0;
  while(end < n){
    long long sum = v[end] - (start > 0 ? v[start - 1] : 0);
    
    if(sum >= s){
      minLength = min(minLength, end - start + 1);
      start++;
    }
    else if(sum < s)
      end++;
  }

  if(minLength == n + 1) cout << 0 << "\n";
  else cout << minLength << "\n";

  return 0;
}