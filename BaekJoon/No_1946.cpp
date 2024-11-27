#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 서류와 면접 둘 중 하나는 다른 지원자보다 높아야 함

// 1 4, 2 3, 3 2, 4 1, 5 5
// 1 4(합격 확정, 가장 높은)와 2 3 비교 2 3 합격(4 < 3)
// 1 4와 3 2 비교 3 2 합격
// 1 4와 4 1 비교 4 1 합격
// 1 4 와 5 5 비교 5 5 탈락

// 1 4, 2 5, 3 6, 4 2, 5 7, 6 1, 7 3
// 1 4와 2 5 비교 2 5 탈락
// 1 4와 3 6 비교 3 6 탈락
// 1 4와 4 2 비교 4 2 탈락
// 1 4와 5 7 비교 5 7 탈락
// 1 4와 6 1 비교 6 1 합격
// 1 4와 7 3 비교 7 3 합격

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++){
      int a, b;
      cin >> a >> b;

      v[i] = {a, b};
    }

    sort(v.begin(), v.end());

    int pass = 0;
    int minRank = INT_MAX;

    for(auto a : v){
      if(a.second < minRank){
        pass++;
        minRank = a.second;
      }
    }

    cout << pass << "\n";
  }

  return 0;
}