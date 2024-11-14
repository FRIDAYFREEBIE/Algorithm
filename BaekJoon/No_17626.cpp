#include <iostream>

using namespace std;

int n;

int arr[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  arr[1] = 1;

  for(int i = 2; i <= n; i++){
    int temp = n + 1;
    for(int j = 1; j * j <= i; j++){
      temp = min(temp, arr[i - j * j]);
    }

    arr[i] = temp + 1;
  }

  cout << arr[n] << "\n";

  return 0;
}