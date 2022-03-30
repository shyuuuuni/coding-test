/*
Time : 2022.03.10
Problem : BOJ23286 (https://www.acmicpc.net/problem/23286)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
그래프 위에서 허들 연습을 하려고 한다.
그래프에는 정점이 N개, 간선이 M개 있다. (간선은 directional이다.)
총 T번 연습하며, 각 연습마다 출발점과 도착점이 있다.
각 연습마다 출발점에서 도착점으로 이동할 때 가장 높이가 높은 허들의 높이가 최소가 되도록 경로를 설정하자.
Method :

Example :
5 6 3
1 2 12
3 2 8
1 3 5
2 5 3
3 4 4
2 4 8
3 4
1 2
5 1
-------
4
8
-1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

bool compare(const string &a, const string &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const int N = 305;
const int INF = 0x3f3f3f3f;
int n, m, t;
int u, v, h;
int s, e;
int d[N][N];


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  cin >> n >> m >> t;
  fill(&d[0][0], &d[N-1][N], INF);
  while (m--) {
    cin >> u >> v >> h;
    if (h < d[u][v])
      d[u][v] = h;
  }
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (d[i][j] > max(d[i][k],d[k][j]))
          d[i][j] = max(d[i][k],d[k][j]);
      }
    }
  }
  while (t--) {
    cin >> s >> e;
    if (d[s][e] >= INF)
      cout << -1;
    else
      cout << d[s][e];
    cout << "\n";
  }


  return 0;
}
