#include <iostream>
#include <algorithm>

using namespace std;

int n, k, cnt, result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  int low = 1, high = k;
  while(low < high){
    int mid = (low + high) / 2;

    cnt = 0;

    for(int i = 1; i <= n; i++){
      cnt += min(n, mid / i);
    }

    if(cnt < k) low = mid + 1;
    else high = mid;
  }

  cout << low << "\n";

  return 0;
}