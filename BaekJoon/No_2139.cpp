#include <iostream>

using namespace std;

int d, m, y;
int month[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int specialyear;
int totalDay = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(true){
    cin >> d >> m >> y;

		if(d == 0 && m == 0 && y == 0) break;

		specialyear = 0;
		if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) specialyear = 1;

		if(specialyear == 1 && m > 2) ++totalDay;

		for(int i = 0; i < m; i++) totalDay += month[i];

		totalDay += d;

		cout << totalDay << endl;

		totalDay = 0;
  }

  return 0;
}