#include <iostream>

using namespace std;

int arr[9];

int n, m;

void func(int k, int prev){
  if(k == m){
    for(int i = 0; i < m; i++){
      cout << arr[i] << " ";
    }

    cout << "\n";

    return;
  }

  for(int i = 1; i <= n; i++){
    if(i >= prev){
      arr[k] = i;
      func(k + 1, i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  func(0, -1);

  return 0;
}