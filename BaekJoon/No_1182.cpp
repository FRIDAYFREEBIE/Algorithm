#include <iostream>

using namespace std;

int arr[20];

int n, s;

int cnt = 0;
void func(int cur, int tot){
  if(cur == n){
    if(tot == s){
      cnt++;
    }
    
    return;
  }

  func(cur + 1, tot);
  func(cur + 1, tot + arr[cur]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  func(0, 0);

  if(s == 0){
    cnt--;
  }

  cout << cnt << "\n";

  return 0;
}