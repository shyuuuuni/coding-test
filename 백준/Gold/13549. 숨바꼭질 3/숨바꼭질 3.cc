/*
Time : 2022.01.19 (25 min)
Problem : BOJ13549 (https://www.acmicpc.net/problem/13549)
Algorithm Type : BFS
Outline :
직선에 수빈이가 위치 N, 동생이 위치 K에 서있다.
수빈이는 1초만에 X-1, X+1로 이동하거나 0초만에 2*X의 위치로 이동할 수 있다.
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
Method :
두 종류의 BFS를 통해 해결하였다.
입력을 받으면서, 적록색약의 경우 R과 G를 구분하지 못하므로 R로 통일하였다.
적록색약과 적록색약이 아닌 사람 기준으로 각각 BFS를 돌리면서
조각의 개수를 세어서 출력한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

void solve() {
  const int MAX_LEN = 2*100000+1;
  int n, k;
  vector<int> dist(MAX_LEN, -1);
  cin >> n >> k;
  queue<int>q;
  q.push(n);
  dist[n] = 0;
  while(!q.empty()) {
    int xx;
    int x = q.front();
    // cout << x << "\n";
    if(x == k) {
      cout << dist[x];
      return;
    }
    q.pop();
    // 순간이동
    for(xx=x*2; xx<MAX_LEN; xx*=2) {
      if(xx<0 || MAX_LEN<=xx) break;
      if(dist[xx]!=-1 && dist[xx] <= dist[x]) break;
      dist[xx] = dist[x];
      // cout << xx << " ";
      q.push(xx);
    }

    // 뒤로이동
    xx = x-1;
    if(!(xx<0 || MAX_LEN<=xx || (dist[xx]!=-1 && dist[xx] <= dist[x]+1))) {
      dist[xx] = dist[x]+1;
      q.push(xx);
    }

    // 뒤로이동
    xx = x+1;
    if(!(xx<0 || MAX_LEN<=xx || (dist[xx]!=-1 && dist[xx] <= dist[x]+1))) {
      dist[xx] = dist[x]+1;
      q.push(xx);
    }
  }
  
  return;
}