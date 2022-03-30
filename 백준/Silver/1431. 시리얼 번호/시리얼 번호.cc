/*
Time : 2022.02.07 (10 mins)
Problem : BOJ1341 (https://www.acmicpc.net/problem/1341)
Algorithm Type : Sort
Outline :
N개의 기타 각각에 시리얼 번호가 적혀있다.
시리얼 번호는 알파벳 대문자와 숫자로 이루어져 있다.
기타를 시리얼 번호대로 다음과 같이 정렬을 하려고 한다.
시리얼번호 A,B에 대해서
1. A와 B의 길이가 짧은것이 먼저 나온다.
2. 길이가 같은 경우 시리얼 번호의 숫자의 합이 작은 것이 먼저 나온다.
3. 둘 다 비교할 수 없다면 사전순으로 비교한다. (숫자가 알파벳보다 사전순으로 작다)
Method :
STL sort의 compare함수를 조건에 맞게 설계하여 정렬한다.
Example :
5
ABCD
145C
A
A910
Z321
=====
A
ABCD
Z321
145C
A910
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

bool isint(char c) {
  return '0' <= c && c <= '9';
}

bool compare(const string& a, const string& b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  if(a.size() != b.size()) return a.size() < b.size();
  int as = 0, bs = 0;
  for(int i=0; i<a.size(); i++)
    if(isint(a[i])) as += a[i] - '0';
  for(int i=0; i<b.size(); i++)
    if(isint(b[i])) bs += b[i] - '0';
  if(as != bs) return as < bs;
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string guitars[50+1] = {};
  cin >> n;
  for(int i=0; i<n; i++) cin >> guitars[i];
  sort(guitars, guitars+n, compare);
  for(int i=0; i<n; i++) cout << guitars[i] << "\n";
  return 0;
}