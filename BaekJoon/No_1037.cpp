#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  int * arr = new int[n];

  // 배열 입력
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  // 약수가 한 개
  if(n == 1){
    cout << arr[0] * arr[0] << "\n";
    return 0;
  }
  else{
    // 배열 정렬
    sort(arr, arr + n);
  }

  // 배열 시작과 끝의 곱 = 원래 수
  cout << arr[0] * arr[n - 1] << "\n";

  return 0;
}