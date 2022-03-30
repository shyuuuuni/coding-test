/*
Time : 2022.01.09 (3 min)
Problem : BOJ2164 (https://www.acmicpc.net/problem/2164)
Algorithm Type : Queue
Outline :
1부터 N까지의 숫자가 써있는 카드가 일렬로 세워져있다.
카드가 한 장만 남을때 까지 다음과 같은 과정을 반복한다.
1. 첫번째 카드를 제거한다.
2. 그 다음 카드를 제일 뒤로 옮긴다.
마지막에 남는 카드를 출력한다.
Method :
Queue를 이용하여 front에 있는 첫번째 카드는 버리고, 그 다음 front에 있는
첫번째 카드를 pop 하고 다시 push 한다.
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int solve1() {
  int n; cin >> n;
  queue<int> q;
  for(int i=1; i<=n; i++) q.push(i);
  while(!q.empty()) {
    n = q.front(); q.pop();
    if(q.empty()) {
      cout << n;
      break;
    }
    n = q.front(); q.pop();
    q.push(n);
  }
  return 0;
}