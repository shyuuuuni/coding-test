/*
Time : 2022.01.06 (5 min)
Problem : BOJ13300 (https://www.acmicpc.net/problem/13300)
Algorithm Type : Array
Outline :
수학여행 방 배정 과정에서 다음과 같은 조건에 맞춰서 방을 배정해야 한다.
1. 성별이 동일해야한다.
2. 학년이 동일해야한다.
최소한의 방의 개수를 출력한다.
Method :
입력 순서가 N->정수들->v 순서이므로 입력과 동시에 처리할 수 없다.
먼저 입력을 받은 후, 한번씩 순회하면서 v의 개수를 카운트하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, s, y, ans=0;
  int students[2][6] = {};
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> s >> y;
    students[s][y-1]++;
  }
  for(int i=0; i<2; i++) {
    for(int j=0; j<6; j++) {
      if(students[i][j])
        ans += (students[i][j] + k - 1) / k;
    }
  }
  cout << ans;
  return 0;
}