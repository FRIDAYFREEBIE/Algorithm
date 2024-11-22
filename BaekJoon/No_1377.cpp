#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 버블 정렬에서 swap이 일어나지 않는 루프 알아내기
// swap이 일어나지 않음 -> 모두 정렬된 상태 -> 가장 많은 인덱스를 이동한 거리
// 1. 입력 -> arr[]
// 2. sort(arr)
// 3. 정렬 전 후 인덱스 비교
// 3-1. max(max, 정렬 전 인덱스 - 정렬 후 인덱스)
// 4. max 출력

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  vector<pair<int, int>> arr(n + 1); // <value, index>
  for(int i = 1; i <= n; i++){
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());

  int ans = 0;
  for(int i = 1; i <= n; i++) ans = max(ans, (arr[i].second - i)); //  정렬 전 인덱스 - 정렬 후 인덱스

  cout << ans + 1 << "\n";

  return 0;
}