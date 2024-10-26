#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int minx = 10000, maxx = -10000, miny = 10000, maxy = -10000;

  for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
        
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }

  int width = maxx - minx;
  int height = maxy - miny;
  int area = width * height;

    cout << (maxx - minx) * (maxy - miny) << "\n";

    return 0;
}
