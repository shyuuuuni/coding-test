/*
Time : 2022.01.20 (30 min)
Problem : BOJ1629 (https://www.acmicpc.net/problem/1629)
Algorithm Type : Recursion
Outline :
A^B mod C 를 구하는 프로그램을 작성한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

long long pow_(long long a, long long b, long long c) {
  // return a^b mod c
  if(b == 1) return a%c; // base condition
  long long half = pow_(a, b/2, c);
  half = half * half % c;
  if(b%2) {
    return half * a % c;
  } else {
    return half % c;
  }
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << pow_(a,b,c);
  return;
}