/*
Time : 2022.02.20
Problem : BOJ14442 (https://www.acmicpc.net/problem/14442)
Algorithm Type : BFS
Outline :
NxM 크기의 맵이 주어진다. 맵의 0은 이동할 수 있고, 1은 이동할 수 없다. (벽)
(1,1)에서 (N,M)으로 이동하기 위한 최단 경로를 아라내려고 한다.
이동 도중에 벽을 K개까지 부수고 이동할 수 있다.
최단 경로를 출력한다.
Method :

Example :
6 4 1
0100
1110
1000
0000
0111
0000
-------
15
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

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};

// 문자열을 구분자를 기준으로 나눠서 벡터에 저장
int splitStringByToken(vector<string> &v, string &s, const char &del) {
  if(s.empty()) return 0;
  istringstream ss(s);
  string token;

  v.clear();
  while (getline(ss, token, del)) {
    if(!token.empty()) v.push_back(token);
  }

  return v.size();
}

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}


bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

int n, m, k;
int a[1000+5][1000+5];
int dist[1000+5][1000+5][10+5];

int _next(int x, int i) {
  switch (i)
  {
  case 0:
    return x-1;
  case 1:
    return x+1;
  case 2:
    return x*2;;
  }
  return 0;
}

int _prev(int x, int i) {
  switch (i)
  {
  case 0:
    return x+1;
  case 1:
    return x-1;
  case 2:
    return x/2;;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string tmp;
  const int mx = 1000000+5;
  cin >> n >> m >> k;
  for (int i=0; i<n; i++) {
    cin >> tmp;
    for (int j=0; j<m; j++) {
      a[i][j] = (tmp[j]=='0'?0:1);
    }
  }

  fill(&dist[0][0][0], &dist[1000+5-1][1000+5-1][10+5], mx);
  queue<pair<pii, int> > q;
  dist[0][0][0] = 1;
  q.push(mp(mp(0,0), 0));

  while(!q.empty()) {
    int x = q.front().first.X;
    int y = q.front().first.Y;
    int bk = q.front().second;
    q.pop();

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (outOfBound0(nx, ny, n, m)) continue;
      if (a[nx][ny] == 0) {
        // 벽이 아닌 경우 -> 이동 가능
        // 만약 벽을 0번 ~ 현재까지 부순 횟수번 사이에서
        // 더 가깝게 도착할 수 있다면 탐색X
        int flag = 0;
        for (int j=0; j<=bk; j++) {
          if (dist[nx][ny][j] <= dist[x][y][bk] + 1) flag = 1;
        }
        if (!flag) {
          q.push(mp(mp(nx,ny), bk));
          dist[nx][ny][bk] = dist[x][y][bk] + 1;
        }
      } else {
        if (bk == k) continue;
        if (dist[x][y][bk] + 1 < dist[nx][ny][bk+1]) {
          // 벽을 부수고 이동하는 경우 탐색
          q.push(mp(mp(nx,ny), bk+1));
          dist[nx][ny][bk+1] = dist[x][y][bk] + 1;
        }
      }
    }
  }

  int ans = mx;
  for (int i=0; i<=k; i++) {
    ans = min(ans, dist[n-1][m-1][i]);
    // cout << i << "\n";
    // for (int j=0; j<n; j++) {
    //   for (int k=0; k<m; k++) {
    //     cout << dist[j][k][i] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
  }
  cout << (ans==mx?-1:ans);

  return 0;
}