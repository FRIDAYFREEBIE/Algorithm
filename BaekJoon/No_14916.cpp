#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  // 5원
  int result = n / 5;
  int remain = (n - result * 5) % 2;

  while(remain != 0){
    if(result == 0){
      cout << -1 << "\n";
      return 0;
    }

    result--;
    remain = (n - result * 5) % 2;
  }

  cout << result + (n - result * 5) / 2 << "\n";



  return 0;
}