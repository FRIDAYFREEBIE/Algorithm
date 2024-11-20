#include <iostream>
#include <vector>

using namespace std;

int n;
long long m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  vector<long long> v(n);
  cin >> v[0];

  for(int i = 1; i < n; i++){
    long long temp;
    cin >> temp;

    v[i] = v[i - 1] + temp;
  }

  int start = 0, end = 0, cnt = 0;
  while(end < n){
    long long sum = v[end] - (start > 0 ? v[start - 1] : 0);

    if(sum == m){
      cnt++;
      end++;
    }
    else if(sum > m){
      start++;
    }
    else if(sum < m){
      end++;
    }
  }

  cout << cnt << "\n";

  return 0;
}