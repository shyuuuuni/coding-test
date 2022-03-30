/*
Time : 2022.01.22 (3 min)
Problem : BOJ2475 (https://www.acmicpc.net/problem/2475)
Algorithm Type : Math
Outline :
5자리 수가 주어졌을 때, 검증수는 각 숫자의 제곱의 합을 10으로 나눈 수이다.
검증수를 출력한다.
Method :
정수 A,B의 크기가 충분히 작기 때문에 int형으로 검증수를 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int ans = 0, tc=5;
  while(tc--) {
    int num; cin >> num;
    ans += num*num%10;
  }
  cout << ans%10;
  return 0;
}