#include <iostream>

#define MAX 100

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n, m, arr[MAX] = {0, };

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int sum = 0, temp;
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = j + 1; k < n; k++){
        temp = arr[i] + arr[j] + arr[k];

        if(temp > sum && m - temp >= 0){
          sum = temp;
        }
      }
    }
  }

  cout << sum << "\n";

  return 0;
}