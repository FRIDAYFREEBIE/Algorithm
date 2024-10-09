#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string whiteBoard[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};
string blackBoard[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

char board[50][50];

int whiteBoardCnt(int startX, int startY);
int blackBoardCnt(int startX, int startY);


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  int minRepaints = 64;

  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      int repaintsWhite = whiteBoardCnt(i, j);
      int repaintsBlack = blackBoardCnt(i, j);
      minRepaints = min(minRepaints, min(repaintsWhite, repaintsBlack));
    }
  }

  cout << minRepaints << "\n";

  return 0;
}

int whiteBoardCnt(int startX, int startY) {
  int count = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[startX + i][startY + j] != whiteBoard[i][j]) {
        count++;
      }
    }
  }
  return count;
}

int blackBoardCnt(int startX, int startY) {
  int count = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[startX + i][startY + j] != blackBoard[i][j]) {
        count++;
      }
    }
  }
  return count;
}