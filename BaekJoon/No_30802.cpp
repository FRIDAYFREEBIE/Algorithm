#include <iostream>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n, t, p, arr[6], cnt = 0;

  cin >> n;

  for(int i = 0; i < 6; i++){
    cin >> arr[i];
  }

  cin >> t >> p;
  
  for(int i = 0; i < 6; i++){
    cnt += (arr[i] / t + (arr[i] % t > 0));
  }

  cout << cnt << "\n" << n / p << " " << n % p << "\n";

  return 0;
}