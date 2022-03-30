/*
Time : 2022.01.21 (30 min)
Problem : BOJ1182 (https://www.acmicpc.net/problem/1182)
Algorithm Type : Backtracking
Outline :
N개의 정수 수열에서, 부분수열의 합이 S인 경우의 개수를 출력한다.
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

int n,s;
int nums[20+1];
int ans=0, cur=0, i=0;

void func(int idx) {
  if(idx == n) {
    if(cur == s && i) {
      ans++;
    }
    return;
  }
  cur += nums[idx];
  i++;
  func(idx+1);
  cur -= nums[idx];
  i--;
  func(idx+1);
  return;
}

void solve() {
  cin >> n >> s;
  for(int i=0; i<n; i++)
    cin >> nums[i];
  func(0);
  cout << ans;
  return;
}