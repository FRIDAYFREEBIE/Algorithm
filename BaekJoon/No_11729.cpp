#include <iostream>

using namespace std;

void func(int a, int b, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  cout << (1 << n) - 1 << "\n";

  func(1, 3, n);

  return 0;
}

// n개를 a에서 b로 옮김
void func(int a, int b, int n){
  if(n == 1){
    cout << a << " " << b << "\n";
    return;
  }

  func(a, 6 - a - b, n - 1);

  cout << a << " " << b << "\n";

  func(6 - a - b, b, n - 1);
}