#include <iostream>
#include <string>

using namespace std;

char film[65][65];

string result = "";

bool check(int n, int col, int row);
void quad(int n, int col, int row);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> film[i][j];
    }
  }

  quad(n, 0, 0);

  cout << result <<"\n";

  return 0;
}

bool check(int n, int col, int row){
  char temp = film[col][row];
  for(int i = col; i < col + n; i++){
    for(int j = row; j < row + n; j++){
      if(temp != film[i][j]){
        return false;
      }
    }
  }

  return true;
}

void quad(int n, int col, int row){
  if(check(n, col, row)){
    result += film[col][row];
    return;
  }

  result += "(";
  int next = n / 2;
  quad(next, col, row);
  quad(next, col, next + row);
  quad(next, col + next, row);
  quad(next, col + next, row + next);
  result += ")";
}