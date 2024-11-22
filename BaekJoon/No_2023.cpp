#include <iostream>

using namespace std;

// DFS + 자릿수(current * 10 + a)
// 2 3 5 7 시작
// current * 10 + a가 소수 -> DFS(current * 10 + a)
// 현재 자릿수 == n -> break;

void DFS(int current, int digits); // 현재 수, 자릿수
bool isPrime(int num); // 소수 판별

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  // 2 3 5 7 시작
  DFS(2, 1); DFS(3, 1); DFS(5, 1); DFS(7, 1);

  return 0;
}

void DFS(int current, int digits){
  // 자릿수가 같다면
  if(digits == n){
    if(isPrime(current)) cout << current << "\n";
    return;
  }
  
  // 1 ~ 9 범위의 짝수 제외
  for(int i = 1; i <= 9; i += 2){
    int newNum = current * 10 + i;
    // newNum이 소수라면 재귀 DFS
    if(isPrime(newNum)) DFS(newNum, digits + 1);
  }
}

bool isPrime(int num){
  // 2는 소수
  if(num == 2) return true;

  // 짝수, 1, 음수 제외
  if(num % 2 == 0 || num <= 1) return false;

  for(int i = 3; i <= num / 2; i += 2){
    if(num % i == 0) return false;
  }

  return true;
}