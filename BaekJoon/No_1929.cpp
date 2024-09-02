#include <iostream>
#include <algorithm>

using namespace std;

bool IsPrime(int a); // a가 소수인지 구해주는 매서드

int main(){
  ios :: sync_with_stdio(false);

  int m, n;

  cin >> m >> n;

  for(int i = m; i <= n; i++){
    if(IsPrime(i))
      cout << i << "\n";
  }

  return 0;
}

// 2부터 루트a까지 검사한다.
bool IsPrime(int a)
{
  if(a < 2) return false;

  for(int i = 2; i * i <= a; i++){ 
    if(a % i == 0) return false;
  }

  return true;
}