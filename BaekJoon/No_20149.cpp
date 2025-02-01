#include <iostream>
#include <iomanip>

using namespace std;

pair<int, int> p1, p2, p3, p4;
double x, y;
bool isSinglePoint = false;

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c){
  long long temp = 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first);
  
  if(temp > 0) return 1;
  if(temp < 0) return -1;
  return 0;
}

bool func() {
  int ab = CCW(p1, p2, p3) * CCW(p1, p2, p4);
  int cd = CCW(p3, p4, p1) * CCW(p3, p4, p2);

  if(ab == 0 && cd == 0){
    bool isOverlapping = max(p1.first, p2.first) >= min(p3.first, p4.first) && max(p3.first, p4.first) >= min(p1.first, p2.first) && max(p1.second, p2.second) >= min(p3.second, p4.second) && max(p3.second, p4.second) >= min(p1.second, p2.second);
    return isOverlapping;
  }

  if(ab <= 0 && cd <= 0){
    double A1 = p2.second - p1.second, B1 = p1.first - p2.first, C1 = A1 * p1.first + B1 * p1.second;
    double A2 = p4.second - p3.second, B2 = p3.first - p4.first, C2 = A2 * p3.first + B2 * p3.second;
    double det = A1 * B2 - A2 * B1;

    if(det != 0){ 
      isSinglePoint = true;
      x = (B2 * C1 - B1 * C2) / det;
      y = (A1 * C2 - A2 * C1) / det;
    }
    else{
      if(p1 == p3 || p1 == p4) { x = p1.first; y = p1.second; isSinglePoint = true; }
      if(p2 == p3 || p2 == p4) { x = p2.first; y = p2.second; isSinglePoint = true; }
    }

    return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> p1.first >> p1.second >> p2.first >> p2.second;
  cin >> p3.first >> p3.second >> p4.first >> p4.second;

  if(func()){
    cout << 1 << "\n";
    if(isSinglePoint) cout << fixed << setprecision(9) << x << " " << y << "\n";
  }
  else cout << 0 << "\n";

  return 0;
}
