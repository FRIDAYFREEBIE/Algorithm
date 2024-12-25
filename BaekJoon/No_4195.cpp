#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> graph; // 친구관계
unordered_map<string, int> num; // 친구관계 수

string findFunc(string a);
void unionFunc(string a, string b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    // 초기화
    graph.clear();
    num.clear();

    for(int i = 0; i < n; i++){
      string a, b;
      cin >> a >> b;
      
      // graph a에 아무 값도 없을 때
      if(graph.count(a) == 0){
        graph.insert({a, a});
        num.insert({a, 1});
      }

      if(graph.count(b) == 0){
        graph.insert({b, b});
        num.insert({b, 1});
      }

      unionFunc(a, b);

      cout << num[findFunc(a)] << "\n";
    }
  }

  return 0;
}

string findFunc(string a){
  if(graph[a] == a) return a;
  else return graph[a] = findFunc(graph[a]);
}

void unionFunc(string a, string b){
  string A = findFunc(a);
  string B = findFunc(b);

  if(A == B) return;

  graph[B] = A;
  num[A] += num[B];
}