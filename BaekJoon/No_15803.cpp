#include <iostream>

using namespace std;

int x1, x2, x3, y1_, y2, y3;

// 직선 0 반환
int CCW(){
  return (x2 - x1) * (y3 - y1_) - (y2 - y1_) * (x3 - x1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> x1 >> y1_ >> x2 >> y2 >> x3 >> y3;

  if(CCW() == 0) cout << "WHERE IS MY CHICKEN?" << "\n";
  else cout << "WINNER WINNER CHICKEN DINNER!" << "\n";

  return 0;
}