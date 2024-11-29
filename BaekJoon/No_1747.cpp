#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool func(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long n;
  cin >> n;

  // 소수 배열 초기화
  long arr[10000001];
  for(int i = 2; i < 10000001; i++) arr[i] = i;

  // 에라스토네스의 체(제곱근 까지)
  for(int i = 2; i < sqrt(10000001); i++){
    if(arr[i] == 0) continue;

    // 배수 지우기
    for(int j = i + i; j < 10000001; j = j + i) arr[j] = 0;
  }

  // 팰린드롬 수 확인
  int i = n;
  while(true){
    if(arr[i] != 0){
      int result = arr[i];

      if(func(result)){
        cout << result << "\n";
        break;
      }
    }

    i++;
  }

  return 0;
}

// 팰린드롬 판별
bool func(int n){
  // 배열로 변환
  string str = to_string(n);
  char const* temp = str.c_str();

  int s = 0;
  int e = str.size() - 1;

  while(s < e){
    if(temp[s] != temp[e]) return false;

    s++;
    e--;
  }

  return true;
}