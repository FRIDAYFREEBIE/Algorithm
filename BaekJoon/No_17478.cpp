#include <iostream>

using namespace std;

void func(int a, string str){
  cout << str << "\"����Լ��� ������?\"" << "\n";

  if(a == 0){
    cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
    cout << str << "��� �亯�Ͽ���." << "\n";
    return;
  }

  cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
  cout << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
  cout << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

  func(a - 1, str + "____");

  cout << str << "��� �亯�Ͽ���." << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
  func(n, "");

  return 0;
}