#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  deque<int> d;
  for(int i = 1; i <= n; i++){
    d.push_back(i);
  }

  int right = 0, left = 0,  cnt = 0;
  while(m--){
    int temp;
    cin >> temp;

    for(int i = 0; i < d.size(); i++){
      if(d[i] == temp){
        right = i;
        left = d.size() - i;
        break;
      }
    }

    if(right < left){
      while(d.front() != temp){
        d.push_back(d.front());
        d.pop_front();
        cnt++;
      }
    }
    else{
      while(d.front() != temp){
        d.push_front(d.back());
        d.pop_back();
        cnt++;
      }
    }

    d.pop_front();
  }

  cout << cnt << "\n";

  return 0;
}