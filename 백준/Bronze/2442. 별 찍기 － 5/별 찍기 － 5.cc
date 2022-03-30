/*
Time : 2022.01.06 (2 min)
Problem : BOJ2442 (https://www.acmicpc.net/problem/2442)
Algorithm Type : I/O
Outline :
N번째 줄엘 별 2*N-1개를 찍는다.
이때 별은 가운데 기준 대칭이다.
Method :
N번째 줄에는 공백이 0개, N-1번째 줄에는 공백이 1개, ... 이런식으로 반복되므로
i번째 줄에는 공백이 N-i개 들어간 뒤 별이 2*i-1개 찍힌다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<n-i; j++) cout << " ";
    for(int j=0; j<2*i-1; j++) cout << "*";
    cout << "\n";
  }
  return 0;
}