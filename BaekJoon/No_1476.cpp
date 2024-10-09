#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int e, s, m;
  cin >> e >> s >> m;

  int result = 0, tempe = 0, temps = 0, tempm = 0;

  while(e != tempe || s != temps || m != tempm) {
    tempe++;
    temps++;
    tempm++;

    if(tempe > 15){
      tempe = 1;
    }

    if(temps > 28){
      temps = 1;
    }

    if(tempm > 19){
      tempm = 1;
    }

    result++;
  }

  cout << result << "\n";

  return 0;
}
