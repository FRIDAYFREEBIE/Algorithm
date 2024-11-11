#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int num[9];

int n, m;

void func(int k, int prev){
  if(k == m){
    for(int i = 0; i < m; i++){
      cout << num[arr[i]] << " ";
    }

    cout << "\n";

    return;
  }

  for(int i = 0; i < n; i++){
    if(prev <= num[i]){
      arr[k] = i;
      func(k + 1, num[i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> num[i];
  }

  sort(num, num + n);

  func(0, -1);

  return 0;
}