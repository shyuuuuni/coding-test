/*
Time : 2022.01.12 (15 min)
Problem : BOJ5014 (https://www.acmicpc.net/problem/5014)
Algorithm Type : BFS
Outline :
총 F층으로 이루어진 건물에 사무실이 있다.
목표 위치는 G층이고, 현재 강호는 S층에 있다.
엘리베이터를 타고 가는데, 엘리베이터는 다음과 같은 버튼이 있다.
1. 위로 U층을 이동하는 버튼
2. 아래로 D층을 이동하는 버튼
(만약 해당 층에 층이 없다면 이동하지 않는다.)
G층에 도착하기 위한 최소 버튼 클릭 수를 출력한다.
만약 이동할 수 없다면 "use the stairs"를 출력한다.
Method :

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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int vis[1000000+1];
void solve() {
  // 총 F층, 출발:S -> 도착:G
  // Up: 위로 u층, Down: 아래로 d층
  int f, s, g, u, d, ans=-1;
  int dd[2] = {-1,-1};
  queue<int> q;
  cin >> f >> s >> g >> u >> d;
  fill(&vis[0], &vis[0]+1000001,-1);
  dd[0]=u;
  dd[1]=(-d);
  q.push(s);
  vis[s] = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == g) {
      ans = vis[cur];
      break;
    }
    for(int i=0; i<2; i++) {
      int ccur = cur + dd[i];
      if(ccur<=0 || f<ccur) continue;
      if(vis[ccur]!=-1) continue;
      vis[ccur] = vis[cur] + 1;
      q.push(ccur);
    }
  }
  if(ans == -1) cout << "use the stairs";
  else cout << ans;
  return;
}