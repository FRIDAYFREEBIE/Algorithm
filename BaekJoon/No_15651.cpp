#include <iostream>

using namespace std;

int arr[9];

int n, m;

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++){
      cout << arr[i] << " ";
    }

    cout << "\n";

    return;
  }

  for(int i = 1; i <= n; i++){
    arr[k] = i;
    func(k + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;  

  func(0);

  return 0;
}