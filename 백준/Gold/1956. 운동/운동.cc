/*
Time : 2022.03.09
Problem : BOJ1956 (https://www.acmicpc.net/problem/1956)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :

Method :
V개의 마을와 E개의 도로로 구성되어 있는 도시가 있다. 도로는 마을과 마을 사이에 놓여 있으며, 일방 통행 도로이다.(directional graph)
운동을 하기 위한 경로를 짜려고 하는데, 마지막 마을에서 처음 마을로 돌아오는 사이클이여야 한다.
또한 사이클을 이루는 경로의 합이 최소가 되도록 하려고 한다.
Example :
3 4
1 2 1
3 2 1
1 3 5
2 3 2
-------
3
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

const int INF = 0x3f3f3f3f;
const int N = 405;
int v, e;
int dist[N][N];

int main(void) {
  cin >> v >> e;
  fill(&dist[0][0], &dist[N-1][N], INF);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < dist[a][b]) {
      dist[a][b] = c;
    }
  }
  for (int i=1; i<=v; i++) dist[i][i] = 0;
  // FW
  for (int k=1; k<=v; k++) {
    for (int i=1; i<=v; i++) {
      for (int j=1; j<=v; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  int ans = INF;
  for (int i=1; i<=v; i++) { // 출발지
    for (int j=1; j<=v; j++) {
      if (i==j) continue;
      if (dist[i][j] + dist[j][i] < ans) {
        ans = dist[i][j] + dist[j][i];
      }
    }
  }

  if (INF <= ans) cout << -1;
  else cout << ans;

  return 0;
}
