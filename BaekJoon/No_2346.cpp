#include <iostream>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  // n 만큼
  deque<pair<int, int>> d;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    d.push_back({i, temp});
  }

  while(!d.empty()){
    int current = d.front().first; // 현재 인덱스
    int move = d.front().second; // 움직임 거리

    cout << current + 1 << " ";
    d.pop_front();

    if(d.empty()){
      break;
    }

    if(move > 0){
      for(int i = 0; i < move - 1; i++){
        d.push_back(d.front());
        d.pop_front();
      }
    }
    else if(move < 0){
      for(int i = 0; i < -move; i++){
        d.push_front(d.back());
        d.pop_back();
      }
    }
  }

  return 0;
}