/*
Time : 2022.01.06 (1 min)
Problem : BOJ2439 (https://www.acmicpc.net/problem/2439)
Algorithm Type : I/O
Outline :
N번째 줄에 별 N개를 찍는 문제이다.
이때 별은 오른쪽 기준으로 정렬한다.
Method :
반복문을 이용하여 각 줄의 총 문자가 N개가 되도록 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) cout << " ";
    for(int j=0; j<i+1; j++) cout << "*";
    cout << "\n";
  }
  return 0;
}