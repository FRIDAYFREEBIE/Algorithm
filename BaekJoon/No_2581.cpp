#include <iostream>

using namespace std;

bool IsPrime(int a); // a가 소수인지 구해주는 매서드

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int  n, m;

  cin >> n >> m;

  if(n == 1){
    cout << -1 << "\n";
    return 0;
  }

  int min = 100000, sum = 0;
  bool temp = false;

  for(int i = n; i < m; i++){
    if(IsPrime(i)){
      sum += i;

      if(i < min) min = i;

      temp = true;
    }
  }

  if(!temp) cout << -1 << "\n";
  else cout << sum << "\n" << min << "\n";

  return 0;
}

bool IsPrime(int a){
  if(a == 2) return true;

  for(int i = 2; i * i <= a; i++){
    if(a % i == 0) return false;
  }

  return true;
}