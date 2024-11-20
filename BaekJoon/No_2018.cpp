#include <iostream>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n; 

  int end = 1, start = 1, cnt = 1, sum = 1;
  while(end != n){
    if(sum == n){
      cnt++;
      end++;
      sum = sum + end;
    }
    else if(sum > n){
      sum = sum - start;
      start++;
    }
    else if(sum < n){
      end++;
      sum = sum + end;
    }
  }

  cout << cnt << "\n";

  return 0;
}