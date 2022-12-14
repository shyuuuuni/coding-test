/*
Time : 2022.01.09 (10 min)
Problem : BOJ10845 (https://www.acmicpc.net/problem/10845)
Algorithm Type : Queue
Outline :
정수를 저장하는 큐를 이용하여 주어진 명령을 처리한다.
Method :
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