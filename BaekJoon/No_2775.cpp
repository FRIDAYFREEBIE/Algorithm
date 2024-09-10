#include <iostream>

using namespace std;

int GetPeople(int k, int n);

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int t, k, n, sum = 0;

  cin >> t;

  for(int i = 0; i < t; i++){
    cin >> k >> n;

    cout << GetPeople(k, n) << "\n";
  }

  return 0;
}

// 재귀함수
int GetPeople(int k, int n){
  if(k == 0) return n;
  if(n == 1) return 1;

  return(GetPeople(k - 1, n) + GetPeople(k, n - 1));
}

// 2-3

// 2-1 2-2 2-3
// 1-1 1-2 1-3
// 0-1 0-2 0-3

// 2-3 = 2-2 + 1-3

// 2-2
// = 2-1 + 1-2
// = 1 + 1-1 + 0-2
// = 1 + 1 + 2
// = 4


// 1-3
// = 1-2 + 0-3
// = 1-1 + 0-2 + 3
// = 1 + 2 + 3
// = 6