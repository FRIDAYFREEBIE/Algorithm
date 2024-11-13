#include <iostream>
#include <cmath> // sqrt 함수 사용

using namespace std;

int w, h, x, y, p, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> w >> h >> x >> y >> p;

  int radius = h / 2;
  int lCircleX = x;
  int lCircleY = y + radius;
  int rCircleX = x + w;
  int rCircleY = y + radius;

  for(int i = 0; i < p; i++){
    int px, py;
    cin >> px >> py;

    bool inRectangle = (px >= x && px <= x + w && py >= y && py <= y + h);

    bool inLeftCircle = (pow(px - lCircleX, 2) + pow(py - lCircleY, 2) <= pow(radius, 2));

    bool inRightCircle = (pow(px - rCircleX, 2) + pow(py - rCircleY, 2) <= pow(radius, 2));

    if(inRectangle || inLeftCircle || inRightCircle){
      cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}
