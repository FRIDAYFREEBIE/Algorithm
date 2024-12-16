#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, l;
  cin >> n >> l;

  int location[1000], start, tape =  0;
  for(int i = 0; i < n; i++) cin >> location[i];

  sort(location, location + n);

  start =  location[0];

  for(int i  = 1; i < n; i++){
    if(l <= location[i] - start){
      tape++;
      start =  location[i];
    }
  }

  cout << tape + 1 << "\n";

  return 0;
}