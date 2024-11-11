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
      cout << arr[i] << " ";
    }

    cout << "\n";

    return;
  }

  int temp = 0;
  for(int i = 0; i < n; i++){
    if(!isUsed[i] && temp != num[i]){
      if(num[i] >= prev){
        arr[k] = num[i];
        isUsed[i] = true;
        temp = arr[k];
        
        func(k + 1, arr[k]);

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