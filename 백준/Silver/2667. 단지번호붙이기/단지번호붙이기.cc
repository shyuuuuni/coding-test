/*
Time : 2022.01.12 (15 min)
Problem : BOJ2667 (https://www.acmicpc.net/problem/2667)
Algorithm Type : BFS
Outline :
NxN 크기의 지도가 있다. 각 지도 안에는 집(1)과 집이아닌곳(0)이 있다.
집이 연결되어 있다면 단지로 정의하고, 단지에 번호를 붙이려고 한다.
지도가 입력되면 단지 수를 출력하고, 각 단지의 집의 수를 오름차순으로 정렬하여 출력한다.
Method :
좌표를 간단하게 생각해보자.
모눈 종이의 칸을 간단하게 왼쪽 아래의 점의 좌표라고 생각한다.
그러면 문제의 그림에 나와있는 각각의 칸을 (x,y) 좌표로 표현할 수 있다.
문제에서 직사각형을 주어질 때 전체 직사각형의 왼쪽 아래 위치와 오른쪽 위 위치를 입력한다.
왼쪽 아래 좌표를 (i1, j1), 오른쪽 위 좌표를 (i2, j2)라고 하면
i1~i2-1, j1~j2-1 까지는 모두 직사각형에 포함되어 있다고 보면 된다.
따라서 위와 같이 arr를 처리하고, 0인 부분만 BFS를 통해 방문 체크하며 값을 저장한다.
마지막 출력시 직사각형의 크기를 오름차순으로 출력하므로 ans 벡터를 정렬해서 출력한다.
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
void solve() {
  int n, cnt=0;
  int vis[25+1][25+1];
  string arr[25+1];
  vector<int> ans;
  queue<pii> q;
  cin >> n;
  fill(&vis[0][0], &vis[0][0] + 26*26, -1);
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(arr[i][j]=='1' && vis[i][j]==-1) {
        cnt++;
        q.push(mp(i,j));
        vis[i][j]=0;
      } else {
        continue;
      }
      int tmp=0;
      while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        tmp++;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
          if(vis[xx][yy]!=-1 || arr[xx][yy]!='1') continue;
          q.push(mp(xx,yy));
          vis[xx][yy]=0;
        }
      }
      ans.push_back(tmp);
    }
  }
  sort(ans.begin(), ans.end());
  cout << cnt << "\n";
  for(auto i : ans) cout << i << "\n";
  return;
}