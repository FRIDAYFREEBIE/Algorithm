#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n, 0);

  for(int i = 1; i <= n; i++){
    int temp;
    cin >> temp;

    for(int j = 0; j < n; j++){
      if(temp == 0 && v[j] == 0){
        v[j] = i;
        break;
      }

      if(v[j] == 0) temp--;
    }
  }

  for(int i = 0; i < n; i++) cout << v[i] << " ";

  cout << "\n";

  return 0;
}