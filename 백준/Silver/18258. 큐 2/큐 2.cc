/*
Time : 2022.01.09 (10 min)
Problem : BOJ10845 (https://www.acmicpc.net/problem/10845)
Algorithm Type : Queue
Outline :
정수를 저장하는 큐를 이용하여 주어진 명령을 처리한다.
Method :
STL Queue를 이용하여 주어진 조건에 따라 처리해주었다.
STL Queue는 Queue가 비어있을때 pop 또는 접근할 경우 에러가 발생하므로
체크를 해주어야 한다.
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
  queue<int> q;
  cin >> n;
  while(n--) {
    cin >> s;
    if(s == "push") {
      cin >> x;
      q.push(x);
    } else if(s == "size") {
      cout << q.size() << "\n";
    } else if(s == "empty") {
      cout << (q.empty()?1:0) << "\n";
    } else if(q.empty()) {
      cout << "-1\n";
    } else if(s == "pop") {
      cout << q.front() << "\n";
      q.pop();
    } else if(s == "front") {
      cout << q.front() << "\n";
    } else {
      cout << q.back() << "\n";
    }
  }
  return 0;
}