#include <iostream>
#include <cstring>
using namespace std;

int n, k;
bool arr[1001];

void func();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  memset(arr, true, sizeof(arr));
  arr[0] = arr[1] = false;

  int cnt = 0;
  for(int i = 2; i <= n; i++){
    for(int j = i; j <= n; j += i){
      if(arr[j]){
        arr[j] = false;
        cnt++;

        if(cnt == k){
          cout << j << "\n";
          return 0;
        }
      }
    }
  }

  return 0;
}