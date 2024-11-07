#include <iostream>
#include <vector>

using namespace std;

long long pow(int a, int b);
void update(int start, int length);

vector<char> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  while(cin >> n){
    long long length = pow(3, n);
    v.clear();
    v.resize(length, '-');
    
    update(0, length);

    for(auto &a : v){
      cout << a;
    }

    cout << "\n";
  }

  return 0;
}

long long pow(int a, int b){
  if(b == 0){
    return 1;
  }

  long long temp = pow(a, b / 2);
  temp = temp * temp;

  if(b % 2 != 0){
    temp = temp * a;
  }

  return temp;
}

// 현재 구간의 시작 위치, 길이
void update(int start, int length){
  if(length < 3){
    return;
  }

  int gapStart = start + length / 3;
  int gapEnd = start + 2 * (length / 3);
  for(int i = gapStart; i < gapEnd; i++){
    v[i] = ' ';
  }

  update(start, length / 3);
  update(start + 2 * (length / 3), length / 3);
}