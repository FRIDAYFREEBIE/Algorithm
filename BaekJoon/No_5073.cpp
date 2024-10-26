#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  while (true) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    int sides[3] = {a, b, c};
    sort(sides, sides + 3);
    
    a = sides[0];
    b = sides[1];
    c = sides[2];

    if (a + b <= c) {
      cout << "Invalid" << "\n";
    }
    else if (a == b && b == c) {
      cout << "Equilateral" << "\n";
    }
    else if (a == b || b == c || a == c) {
      cout << "Isosceles" << "\n";
    }
    else {
      cout << "Scalene" << "\n";
    }
  }
  
  return 0;
}
