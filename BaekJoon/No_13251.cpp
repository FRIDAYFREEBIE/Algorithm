#include <iostream>

using namespace std;

int m, k;
int arr[51];
double p[51];
double ans = 0.0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m;

  int temp = 0;
  for(int i = 0; i < m; i++){
    cin >> arr[i];
    temp += arr[i];
  }

  cin >> k;

  for(int i = 0; i < m; i++){
    if(arr[i] >= k){
      p[i] = 1.0;

      for(int j = 0; j < k; j++){
        p[i] *= (double)(arr[i] - j) / (temp - j);
      }
    }

    ans += p[i];
  }

  cout << fixed;
  cout.precision(9);
  cout << ans << "\n";

  return 0;
}