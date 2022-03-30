/*
Time : 2022.03.08
Problem : BOJ1261 (https://www.acmicpc.net/problem/1261)
Algorithm Type : 다익스트라
Outline :
NxM 보드에 0(빈 칸), 1(벽)이 있다.
(1,1)에서 (N,M)으로 이동하기 위해서 부셔야 할 벽의 최소 개수를 출력한다.
Method :

Example :
3 3
011
111
110
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

int charToInt(char c) {
  if ('A' <= c && c <= 'Z')
    return (int)(c - 'A');
  else if ('a' <= c && c <= 'z')
    return (int)(c - 'a');
  else if ('0' <= c && c <= '9')
    return (int)(c - '0');
  return -1;
}

int n, m; // 세로, 가로
const int INF = 100000;
int dist[100+5][100+5];
string board[100+5];
priority_queue<pair<int,pii>, vector<pair<int,pii> >, greater<pair<int,pii> > > pq;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> m >> n; // 가로, 세로 순서
  fill(&dist[0][0], &dist[100+5-1][100+5], INF);
  for (int i=1; i<=n; i++) {
    string s;
    cin >> s;
    board[i] = '.' + s;
  }

  // for (int i=1; i<=n; i++) {
  //   for (int j=1; j<=m; j++) {
  //     cout << board[i][j];
  //   }
  //   cout << "\n";
  // }

  dist[1][1] = 0;
  pq.push({0, {1,1}});

  while (!pq.empty()) {
    int broken = pq.top().first;
    int x = pq.top().second.X;
    int y = pq.top().second.Y;
    // cout << x << "," << y << " " << broken << "\n";
    pq.pop();
    if (dist[x][y] < broken) continue; // 더 적게 부수고 도착할 수 있다면 스킵
    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (n<nx || m<ny || nx<1 || ny<1) continue;
      if (board[nx][ny] == '0') {
        // 벽이 아닌 경우
        if (dist[nx][ny] <= broken) continue;
        dist[nx][ny] = broken;
        // cout << "  push" << nx << "," << ny << " " << broken << "\n";
        pq.push({dist[nx][ny], {nx,ny}});
      } else {
        // 벽인 경우 -> 부셔야 함
        if (dist[nx][ny] <= broken+1) continue;
        dist[nx][ny] = broken+1;
        // cout << "  push" << nx << "," << ny << " " << broken+1 << "\n";
        pq.push({dist[nx][ny], {nx,ny}});
      }
    }
  }

  cout << dist[n][m];

  return 0;
}