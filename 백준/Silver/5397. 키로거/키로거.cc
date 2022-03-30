/*
Time : 2022.01.07 ( min)
Problem : BOJ5397 (https://www.acmicpc.net/problem/5397)
Algorithm Type : Linked List
Outline :
키보드를 누른 명령을 모두 기록하는 키로거가 존재한다.
비밀번호를 입력한 키가 주어졌을 때, 비밀번호를 출력한다.
Method :
STL의 list를 이용하여 구현하였다.
cursor라는 이름의 iterator를 화살표에 따라서 이동시키면서,
백스페이스 연산은 erase 함수로 처리하였고,
단어를 입력하는 연산은 insert 함수로 처리하였다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  // ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    solve1();
    cout << "\n";
  }
  return 0;
}

void solve1() {
  list<char> list;
  auto cursor = list.begin();
  string s;
  cin >> s;
  for(auto c : s) {
    if(c == '<') {
      if(cursor != list.begin()) cursor--;
    } else if(c == '>') {
      if(cursor != list.end()) cursor++;
    } else if(c == '-') {
      if(cursor != list.begin()) {
        cursor--;
        cursor = list.erase(cursor);
      }
    } else {
      list.insert(cursor, c);
    }
  }
  for(auto i : list) cout << i;
}