#include <iostream>
#include <climits>

using namespace std;

int n;
long long arr[100001]; // 수 배열
long long answerA, answerB;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  // 투 포인터
  int left = 0, right = n - 1;
  answerA = arr[left], answerB = arr[right];

  // 정확한 대소 비교를 위해 절댓값으로 만들기
  long long prev = LLONG_MAX;
  while(left < right){
    long long current = arr[left] + arr[right];

    if(current == 0){
      cout << arr[left] << " " << arr[right] << "\n";
      return 0;
    }

    if(abs(current) < prev){
      prev = abs(current);
      answerA = arr[left];
      answerB = arr[right];
    }

    // 0에 가까운 값을 탐색
    if(current < 0) left++;
    else right--;
  }

  // 오름차순
  if(answerA > answerB) swap(answerA, answerB);

  cout << answerA << " " << answerB << "\n";

  return 0;
}