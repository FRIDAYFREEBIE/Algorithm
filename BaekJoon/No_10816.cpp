#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v1(n);

  for(int i = 0; i < n; i++){
    cin >> v1[i];
  }

  map<int, int> freq;

  for (int i = 0; i < n; i++) {
    freq[v1[i]]++;
  } 

  int m;
  cin >> m;

  vector<int> v2(m);

  for(int i = 0; i < m; i++){
    cin >> v2[i];
  }

  for (int i = 0; i < m; i++) {
    cout << freq[v2[i]] << " ";
  }

  cout << "\n";
  
  return 0;
}