#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int num[9];
bool isUsed[9];

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
    if(!isUsed[i]){
      if(num[i] > prev){
        arr[k] = i;
        isUsed[i] = true;
        func(k + 1, num[i]);
        isUsed[i] = false;
      }
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