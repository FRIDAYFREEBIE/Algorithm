#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

// 최대 m개의 치킨집을 제외하고 제거했을 때 가장 작은 도시의 치킨 거리 구하기
// 1. while(m--)
// 2. m개의 치킨집을 제거(브루트포스)
// 3. 각 집의 치킨 거리를 계산 -> 도시의 치킨 거리 갱신(백트래킹)
// 3. 현재 도시의 치킨 거리보다 크다면 중단(가지치기)
// 4. 치킨집 복구

int n, m, city[51][51];
vector<pair<int, int>> house, chicken;
vector<int> selected; // 현재 선택된 치킨집
int preDistance[102][13]; // 거리 미리 구하기
int minChicken = INT_MAX; // int 최댓값

void selectChicken(int index, int cnt); // 치킨집 선택
int chickenDistance(); // 치킨집 거리 계산

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  // 0: 빈칸 1: 집 2: 치킨집
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> city[i][j];

      // 집
      if(city[i][j] == 1) house.push_back({i, j});
      // 치킨집
      else if(city[i][j] == 2) chicken.push_back({i, j});
    }
  }

  // 미리 구하기
  for(int i = 0; i < house.size(); i++){
    for(int j = 0; j < chicken.size(); j++){
      preDistance[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
    }
  }

  selectChicken(0, 0);

  cout << minChicken << "\n";

  return 0;
}

// 치킨집 백트래킹
// 최대 m개의 치킨집을 제외한 경우의 수를 재귀적으로 탐색
void selectChicken(int index, int cnt){
  if(cnt == m){
    int temp = chickenDistance();
    minChicken = min(minChicken, temp);
    return;
  }

  for(int i = index; i < chicken.size(); i++){
    selected.push_back(i); // i번째 치킨집 선택

    selectChicken(i + 1, cnt + 1);

    selected.pop_back(); // 선택 취소
  }
}

int chickenDistance(){
  int cityDistance = 0;

  // 모든 집을 순회
  for(int h = 0; h < house.size(); h++){
    int distance = INT_MAX;

    // 선택된 모든 치킨집 순회
    for(int index : selected){
      distance = min(distance, preDistance[h][index]);
    }

    cityDistance += distance;

    // 백트래킹 가지치기
    if(cityDistance >= minChicken) return INT_MAX;
  }

  return cityDistance;
}