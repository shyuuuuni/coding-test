/*
Time : 2022.03.10
Problem : BOJ1719 (https://www.acmicpc.net/problem/1719)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
N개의 집하장과 M개의 집하장간 도로가 주어진다. (방향이 없다 = indirectional)
주어진 상황에서, 각 집하장에서 다른 집하장으로 가는 최단 거리를 가기 위해 바로 다음에 방문해야 하는 집하장을 적어놓은
경로표를 구하시오.
Method :

Example :
6 10
1 2 2
1 3 1
2 4 5
2 5 3
2 6 7
3 4 4
3 5 6
3 6 7
4 6 4
5 6 2
-------
- 2 3 3 2 2
1 - 1 4 5 5
1 1 - 4 5 6
3 2 3 - 6 6
2 2 3 6 - 6
5 5 3 4 5 -
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
const int N = 205;
int n, m;
int dist[N][N];
int nxt[N][N];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO
  cin >> n >> m;
  fill(&dist[0][0], &dist[N-1][N], INF);
  fill(&nxt[0][0], &nxt[N-1][N], 0);
  for (int i=1; i<=n; i++) {
    dist[i][i] = 0;
    nxt[i][i] = -1;
  }
  int a,b,c;
  while (m--) {
    cin >> a >> b >> c;
    if (c < dist[a][b]) {
      dist[a][b] = dist[b][a] = c;
      nxt[a][b] = b;
      nxt[b][a] = a;
    }
  }
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (i == j) cout << "- ";
      else cout << nxt[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
