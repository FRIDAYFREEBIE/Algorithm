#include <iostream>

using namespace std;

int arr[100001];
int d[100001];
int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    d[i] = d[i - 1] + arr[i];
  }

  while(m--){
    int a, b;
    cin >> a >> b;

    cout << d[b] - d[a - 1] << "\n";
  }

  return 0;
}