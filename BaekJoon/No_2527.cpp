#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0; i < 4; i++){
    int X1, Y1, X2, Y2, P1, Q1, P2, Q2;
    cin >> X1 >> Y1 >> P1 >> Q1 >> X2 >> Y2 >> P2 >> Q2;

    if(X1 > P2 || Y1 > Q2 || X2 > P1 || Y2 > Q1) cout << "d" << "\n";
		else if((X1 == P2 && Y1 == Q2) || (X2 == P1 && Y2 == Q1) || (X1 == P2 && Q1 == Y2) || (X2 == P1 && Q2 == Y1)) cout << "c" << "\n";
		else if (X1 == P2 || Y1 == Q2 || X2 == P1 || Y2 == Q1) cout << "b" << "\n";
		else cout << "a" << "\n";
  }

  return 0;
}