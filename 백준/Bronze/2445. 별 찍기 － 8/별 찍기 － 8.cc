/*
Time : 2022.01.06 (13 min)
Problem : BOJ2444 (https://www.acmicpc.net/problem/24434)
Algorithm Type : I/O
Outline :
Input이 5일때 다음과 같은 별을 찍는 알고리즘을 설계한다.
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
Method :
n번째 줄까지는 i개의 별을 찍고 2(n-i)개의 공백을 찍고, 다시 i개의 별을 찍는다.
n+1번째 줄부터 다시 i=2라고 생각하고, (n-i+1)개의 별을 찍고, 2(i-1)개의 공백을 찍고, 다시 (n-i+1)개의 별을 찍는다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<i; j++) cout << "*";
    for(int j=0; j<2*(n-i); j++) cout << " ";
    for(int j=0; j<i; j++) cout << "*";
    cout << "\n";
  }
  for(int i=2; i<=n; i++) {
    for(int j=0; j<(n-i+1); j++) cout << "*";
    for(int j=0; j<2*(i-1); j++) cout << " ";
    for(int j=0; j<(n-i+1); j++) cout << "*";
    cout << "\n";
  }
  return 0;
}