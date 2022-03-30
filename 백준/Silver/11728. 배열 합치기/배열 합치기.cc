/*
Time : 2022.02.07 (20 mins)
Problem : BOJ11728 (https://www.acmicpc.net/problem/11728)
Algorithm Type : Sort (Merge)
Outline :
정렬되어 있는 두 배열 A,B가 주어졌을 때,
두 배열을 합친 배열을 출력한다.
Method :
Merge sort를 구현하는 것 처럼 가장 왼쪽에 있는 원소들을 비교하면서 하나의 배열로 합친다.
Example :
2 2
3 5
2 9
-------
2 3 5 9
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dz[6] = {0,0,0,0,-1,1};
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

/*
 * declare here
 */
int n, m, pa, pb;
int a[1000000+1], b[1000000+1], c[2000000+1];

bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

void solve() {
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int j=0; j<m; j++) cin >> b[j];
  pa = 0;
  pb = 0;
  while((pa < n) && (pb < m)) {
    if(a[pa] < b[pb]) {
      c[pa+pb] = a[pa];
      pa++;
    } else {
      c[pa+pb] = b[pb];
      pb++;
    }
  }
  if(pa == n) {
    while(pb < m) {
      c[pa+pb] = b[pb];
      pb++;
    }
  } else {
    while(pa < n) {
      c[pa+pb] = a[pa];
      pa++;
    }
  }
  for(int i=0; i<pa+pb; i++) cout << c[i] << " ";
  return;
}