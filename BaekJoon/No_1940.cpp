#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[15001], cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++) cin >> arr[i];

  // 1 2 3 4 5 7
  sort(arr, arr + n);

  int start = 0, end = n - 1;
  while(start < end){
    int sum = arr[start] + arr[end];

    if(sum == m){
      cnt++;
      start++;
      end--;
    }
    else if(sum > m){
      end--;
    }
    else if(sum < m){
      start++;
    }
  }

  cout << cnt << "\n";

  return 0;
}