#include <iostream>

using namespace std;

int k;
int arr[13];
int num[13];
bool isUsed[13];

// 백트래킹
void func(int n, int prev){
  if(n == 6){
    for(int i = 0; i < 6; i++){
      cout << arr[i] << " ";
    }

    cout << "\n";

    return;
  }

  for(int i = 0; i < k; i++){
    if(!isUsed[i] && prev < num[i]){
      arr[n] = num[i];
      isUsed[i] = true;

      func(n + 1, num[i]);

      isUsed[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true){
    cin >> k;

    if(k == 0){
      break;
    }

    // 배열 초기화
    for(int i = 0; i < 13; i++){
      arr[i] = 0;
      num[i] = 0;
      isUsed[i] = false;
    }

    // 입력
    for(int i = 0; i < k; i++){
      cin >> num[i];
    }

    func(0, -1);

    cout << "\n";
  }

  return 0;
}