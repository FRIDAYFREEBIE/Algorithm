#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b);

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<string> v;

  for(int i = 0; i < n; i++){
    string temp;

    cin >> temp;

    auto it = find(v.begin(), v.end(), temp);

    if(it == v.end()) v.push_back(temp);
  }

  sort(v.begin(), v.end(), compare);

  for(const auto& str : v){
    cout << str << "\n";
  }

  return 0;
}

bool compare(const string& a, const string& b) {
  if(a.size() != b.size()) return a.size() < b.size();
  else return a < b;
}