#include <iostream>

using namespace std;

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, temp = 0;

  while(true){
    int a, b, c, temp = 0;

    cin >> a >> b >> c;

    if(a == 0 && b == 0 && c == 0) break;

		if ((c * c == a * a + b * b) || (b * b == a * a + c * c) || (a * a == c * c + b * b)) cout << "right" << endl;
		else cout << "wrong" << endl;
  }

  return 0;
}