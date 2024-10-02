#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
  int age;
  string name;
  int index;
};

bool compare(const Data& a, const Data& b);

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  vector<Data> v;

  for(int i = 0; i < n; i++){
    int age;
    string name;

    cin >> age >> name;

    v.push_back({age, name, i});
  }

  sort(v.begin(), v.end(), compare);

  for(const auto& a : v){
    cout << a.age << " " << a.name << "\n";
  }
  
  return 0;
}

bool compare(const Data& a, const Data& b){
  if (a.age == b.age) return a.index < b.index;

  return a.age < b.age;
}
