/*
Time : 2022.01.06 (10 min)
Problem : BOJ10093 (https://www.acmicpc.net/problem/10093)
Algorithm Type : I/O
Outline :
두 자연수 사이의 수의 개수와 수들을 오름차순으로 출력한다.
두 자연수는 0보다 크고 10^15보다 작거나 같다. 두 수의 차이는 최대 100,000 이다.
Method :
10^15 는 int형 변수가 표현할 수 있는 32bit로 표현할 수 없기 때문에 long long 정수를 이용하여 처리한다.
두 수 사이의 수의 개수는 (큰 수) - (작은 수) - 1 로 표현 가능하다.
Failed :
두 수가 같을 경우를 처리하지 않아서 틀렸었다.
두 수가 같을 경우에도 두 수 사이의 원소의 개수가 0인데, 기존 코드의 경우 -1을 출력햇다.
max 함수로 0과 계산한 값을 넣어서 두 수가 같아도 0을 출력하도록 처리하였다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (b < a) swap(a, b);
  cout << max((long long)0, b - a - 1) << "\n";
  for(long long i=a+1; i<b; i++) cout << i << " ";
  return 0;
}