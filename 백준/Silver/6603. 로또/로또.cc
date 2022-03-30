/*
Time : 2022.01.21 (15 min)
Problem : BOJ6603 (https://www.acmicpc.net/problem/6603)
Algorithm Type : Backtracking
Outline :
로또에서 {1,2,...,49} 중 6개를 고른다.
위 중 k개의 수를 고른 후, 그 수 안에서 번호 6개를 고른다.
S와 K가 주어졌을 때 고르는 방법의 수를 출력한다.
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

int k;
int v[50];

void func(int cur) {
  return;
}

void solve() {
  while(1) {
    cin >> k;
    if(k==0) break;
    for(int i=0; i<k; i++) cin >> v[i];
    vector<int> tmp(k,0);
    for(int i=0; i<6; i++) {
      tmp[i] = 1;
    }
    sort(v, v+k);
    do {
      for(int i=0; i<k; i++) {
        if(tmp[i]) cout << v[i] << " ";
      }
      cout << "\n";
    } while (prev_permutation(tmp.begin(), tmp.end()));
    cout << "\n";
  }
  return;
}