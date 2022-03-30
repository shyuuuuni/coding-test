/*
Time : 2022.01.07 (30 min)
Problem : BOJ17298 (https://www.acmicpc.net/problem/17298)
Algorithm Type : Stack
Outline :
수열 A = A1, A2, ..., An이 있다.
NGE(i)는 Ai보다 오른쪽에서 더 큰 수 중 가장 왼쪽에 있는 수를 의미한다.
NGE(1)부터 NGE(N)까지 공백으로 구분해 출력한다. 만약 존재하지 않는 경우 -1을 출력한다.
Method :

*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int NGE[1000000+1];
int solve1() {
  int n;
  // stk: NGE를 구하는 중인 원소
  stack<pair<int,int> > stk;
  cin >> n;
  fill(NGE, NGE+n, -1);
  for(int i=0; i<n; i++) {
    int ai;
    cin >> ai;
    pair<int, int> cur = make_pair(i, ai); // i번째 수열의 값 ai
    if(stk.empty() || ai < stk.top().second) {
      stk.push(cur);
    } else {
      while(!stk.empty() && stk.top().second < ai) {
        NGE[stk.top().first] = ai;
        stk.pop();
      }
      stk.push(cur);
    }
  }
  for(int i=0; i<n; i++) cout << NGE[i] << " ";
  return 0;
}