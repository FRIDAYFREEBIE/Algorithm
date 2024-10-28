#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> treeVector(n);
  for(int i = 0; i < n; i++){
    cin >> treeVector[i];
  }

  int gcd = treeVector[1] - treeVector[0];; // 공약수
  for (int i = 1; i < n - 1; i++) {
    gcd = GCD(gcd, treeVector[i + 1] - treeVector[i]);
  }

  int cnt = 0; // 나무 갯수
  for(int i = 0; i < n - 1; i++){
    cnt += (treeVector[i + 1] - treeVector[i]) / gcd - 1;
  }

  cout << cnt << "\n";
  
  return 0;
}

int GCD(int a, int b){
  if(b == 0){
    return a;
  }
  else{
    return GCD(b, a % b);
  }
}