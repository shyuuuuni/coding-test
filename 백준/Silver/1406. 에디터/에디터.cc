/*
Time : 2022.01.07 (15 min)
Problem : BOJ1406 (https://www.acmicpc.net/problem/1406)
Algorithm Type : Linked List
Outline :
최대 600,000개의 영어 소문자를 기록할 수 있는 에디터를 구현한다.
편집기에는 '커서'가 존재하며, 편집기에는 다음과 같은 명령어가 존재한다.
1. L : 커서를 왼쪽으로 한칸 옮긴다.
2. D : 커서를 오른쪽으로 한칸 옮긴다.
3. B : 커서 왼쪽의 문자를 삭제한다.
4. P $ : $라는 문자를 커서 왼쪽에 추가한다.
초기 편집기의 문자열이 주어지고, 명령이 차례로 주어졌을때 모든 명령어 수행 이후
편집기에 입력되어 있는 문자열을 출력한다.
Method :
Linked List를 이용하면 쉽게 해결할 수 있다.
양 옆으로 커서를 이동하는 방식은 Linked List의 Pointer를 이동시키면 된다.
삭제하는 명령어는 커서 위치를 알고있으므로 O(1)에 삭제할 수 있다.
추가하는 명령어 또한 위치가 커서 위치를 알고있으므로 O(1)에 추가할 수 있다.
연습을 위해 STL을 사용하는 방식과 야매 Linked List를 구현하는 방식으로 시도했다.
Failed :
STL을 이용하여 구현할 때 iterator에 대한 부분에 숙지가 부족했다.
*/
#include <bits/stdc++.h>
using namespace std;
void use_stl();
void implement_simple_linked_list();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  use_stl();
  return 0;
}

void use_stl() {
  list<char> list;
  string s;
  int n;
  cin >> s;
  cin >> n;
  for(auto i : s) list.push_back(i);
  auto cursor = list.end();
  for(int i=0; i<n; i++) {
    char order, argu;
    cin >> order;
    if(order == 'P') {
      cin >> argu;
      list.insert(cursor, argu); // 커서가 가리키는 부분은 그대로 유지됨
    } else if(order == 'L') {
      if(cursor != list.begin()) cursor--;
    } else if(order == 'D') {
      if(cursor != list.end()) cursor++;
    } else if(order == 'B') {
      if(cursor != list.begin()) {
        cursor--;
        cursor = list.erase(cursor);
      }
    } else {
      continue;
    }
  }
  for(auto i : list) cout << (char)i;
  return;
}

