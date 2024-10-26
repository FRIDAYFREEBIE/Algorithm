#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int x, y, w, h;
  cin >> x >> y >> w >> h;

  int result = 10000;
  if(x < result){
    result = x;
  }
  if(y < result){
    result = y;
  }
  if(w - x < result){
    result = w - x;
  }
  if(h - y < result){
    result = h - y;
  }

  cout << result << "\n";

  return 0;
}