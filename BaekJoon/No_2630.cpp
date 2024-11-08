#include <iostream>

using namespace std;

int paper[129][129];
int result[2];

bool check(int n, int col, int row);
void cut(int n, int col, int row);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> paper[i][j];
    }
  }

  cut(n, 0, 0);
  cout << result[0] << "\n";
  cout << result[1] << "\n";

  return 0;
}

bool check(int n, int col, int row){
  int temp = paper[col][row];
  for(int i = col; i < n + col; i++){
    for(int j = row; j < n + row; j++){
      if(temp != paper[i][j]){
        return false;
      }
    }
  }

  return true;
}

void cut(int n, int col, int row){
  if(check(n, col, row)){
    result[paper[col][row]]++;
    return;
  }

  int nextSize = n / 2;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cut(nextSize, col + nextSize * i, row + nextSize * j);
    }
  }
}
