#include <iostream>

using namespace std;

int func(int n, int r, int c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, r, c;
  cin >> n >> r >> c;
  cout << func(n, r, c) << "\n";

  return 0;
}

int func(int n, int r, int c){
  if(n == 0){
    return 0;
  }

  int half = 1 << (n - 1);

  // 1번
  if(r < half && c < half){
    return func(n - 1, r, c);
  }
  // 2번
  else if(r < half && c >= half){
    return half * half + func(n - 1, r, c - half);
  }
  // 3번
  else if(r >= half && c < half){
    return 2 * half * half + func(n - 1, r - half, c);
  }
  // 4번
  else{
    return 3 * half * half + func(n - 1, r - half, c - half);
  }
}