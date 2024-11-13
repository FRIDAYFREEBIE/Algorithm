#include <iostream>

using namespace std;

int d[1000000];
int pre[1000000];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i = 2; i <= n; i++){
    d[i] = d[i - 1] + 1;
    pre[i] = i - 1;

    if(i % 3 == 0 && d[i] > d[i / 3] + 1){
      d[i] = d[i / 3] + 1;
      pre[i] = i / 3;
    }
    if(i % 2 == 0 && d[i] > d[i / 2] + 1){
      d[i] =  d[i / 2] + 1;
      pre[i] = i / 2;
    }
  }

  cout << d[n] << "\n";

  int current = n;
  while(true){
    cout << current << " ";
    if(current == 1){
      break;
    }
    current = pre[current];
  }

  return 0;
}