#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  vector<int> v(n, 0);
  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());
  
  for(int i = 0; i < n; i++){
    long target = v[i];
    int start = 0, end = n - 1;

    while(start < end){
      int sum = v[start] + v[end];

      // 서로 다른 두 수
      if(target == sum){
        // 자기 자신
        if(start != i && end != i){
          cnt++;
          break;
        }
        // 자기 자신 방지
        else if(start == i) start++;
        else if(end == i) end--;
      }
      else if(sum < target) start++;
      else end--;
    }
  }

  cout << cnt << "\n";

  return 0;
}