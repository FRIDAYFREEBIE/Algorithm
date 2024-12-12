#include <iostream>
#include <vector>

using namespace std;

vector<int> truePeople;
vector<vector<int>> party;
vector<int> parent;

void unionFunc(int a, int b);
int findFunc(int a);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  parent.resize(n + 1);
  party.resize(m);

  int t;
  cin >> t;
  truePeople.resize(t);

  for(int i = 0; i < t; i++) cin >> truePeople[i];

  for(int i = 0; i < m; i++){
    int partySize;
    cin >> partySize;

    for(int j = 0; j < partySize; j++){
      int temp;
      cin >> temp;

      party[i].push_back(temp);
    }
  }

  for(int i = 1; i <= n; i++) parent[i] = i;

  for(int i = 0; i < m; i++){
    int first = party[i][0];

    for(int j = 1; j < party[i].size(); j++) unionFunc(first, party[i][j]);
  }

  int answer = 0;
  for(int i = 0; i < m; i++){
    bool isPossible = true;
    int current = party[i][0];

    for(int j = 0; j < t; j++){
      if(findFunc(current) == findFunc(truePeople[j])){
        isPossible = false;
        break;
      }
    }

    if(isPossible) answer++;
  }

  cout << answer << "\n";

  return 0;
}

void unionFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a != b) parent[b] = a;
}

int findFunc(int a){
  if(parent[a] == a) return a;
  else return parent[a] = findFunc(parent[a]);
}