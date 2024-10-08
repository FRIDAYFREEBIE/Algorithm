#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  vector<int> v;
  int sum = 0;

  for(int i = 0; i < 9; i++){
    int temp;
    cin >> temp;

    v.push_back(temp);

    sum += temp;
  }

  sort(v.begin(), v.end());

  int temp = sum - 100;
  int a = 0, b = 0;

  while(a == 0 && b == 0){
    for(int i = 0; i < v.size(); i++){
      for(int j = 0; j < v.size(); j++){
        if(j != i && v[i] + v[j] == temp){
          a = v[i];
          b = v[j];
        }
      }
    }
  }

  for(int i = 0; i < v.size(); i++){
    if(v[i] != a && v[i] != b){
      cout << v[i] << "\n";
    }
  }

  return 0;
}
