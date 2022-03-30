/*
Time : 2022.01.09 (3 min)
Problem : BOJ10866 (https://www.acmicpc.net/problem/10866)
Algorithm Type : Deque
Outline :
정수 덱을 이용하여 주어진 명령을 처리한다.
Method :
STL Deque를 사용하여 구현한다.
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int solve1() {
  int n, x;
  string s;
  deque<int> dq;
  cin >> n;
  while(n--) {
    cin >> s;
    if(s == "push_front") {
      cin >> x;
      dq.push_front(x);
    } else if(s == "push_back") {
      cin >> x;
      dq.push_back(x);
    } else if(s == "size") {
      cout << dq.size() << "\n";
    } else if(s == "empty") {
      cout << (dq.empty()?1:0) << "\n";
    } else if(dq.empty()) {
      cout << "-1\n";
    } else if(s == "pop_front") {
      cout << dq.front() << "\n";
      dq.pop_front();
    } else if(s == "pop_back") {
      cout << dq.back() << "\n";
      dq.pop_back();
    } else if(s == "front") {
      cout << dq.front() << "\n";
    } else {
      cout << dq.back() << "\n";
    }
  }
  return 0;
}
