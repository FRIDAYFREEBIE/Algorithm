#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  vector<long long> numVector(t);
  for(int i = 0; i < t; i++){
    cin >> numVector[i];
  }

  for(int i = 0; i < t; i++){
    long long temp = numVector[i];
    while(true){
      if(isPrime(temp)){
        break;
      }
      else{
        temp++;
      }
    }

    cout << temp << "\n";
  }

  return 0;
}

bool isPrime(long long n){
  if(n == 1){ // 1은 소수가 아님
    return false;
  }
  
  if(n == 2){ // 2는 소수
    return true;
  }

  if(n % 2 == 0){ // 짝수는 소수가 아님
    return false;
  }

  // 홀수만
  for(long long i = 3; i <= sqrt(n); i += 2){
    if(n % i == 0){
      return false;
    }
  }

  return true;
}
