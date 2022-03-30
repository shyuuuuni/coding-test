/*
Time : 2022.02.20
Problem : BOJ16920 (https://www.acmicpc.net/problem/16920)
Algorithm Type : BFS
Outline :
NxM 크기의 격자판이 비어있거나(.), 벽이 있다(#)
해당 격자판 위에서 "확장 게임"을 진행하려고 한다.
확장 게임은 플레이어별로 성을 가지고 있고, 플레이어 1부터 마지막 플레이어까지 확장을 한다.
확장이란 자신이 가지고 있는 성에서 Si칸 만큼 이동할 수 있는 모든 칸에 성을 동시에 만든다.
(벽 또는 다른 플레이어의 성으로는 확장할 수 없다.)
모든 플레이어가 더이상 확장을 할 수 없을 때 까지 게임을 진행한다.
초기 게임판이 주어졌을 때 최종 상태를 출력한다. (플레이어별로 가진 성의 수를 출력)
Method :
Example :
3 3 2
1 1
1..
...
..2
-------
6 3
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

int n, m, p;
string a[1000+5];
int castle[1000+5][1000+5];
int dist[1000+5][1000+5];
int how_move[10+5];
int turn[10+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> p; // 세로x가로, 플레이어 수
  vector<pii> stt(p+5);
  queue<int> q1;
  queue<pii> q2;
  vector<vector<pii> > v(p+1);
  for (int i=1; i<=p; i++) {
    int s;
    cin >> s;
    how_move[i] = s;
  }
  for (int i=0; i<n; i++) {
    cin >> a[i];
    for (int j=0; j<m; j++) {
      if ('1' <= a[i][j] && a[i][j] <= '9') {
        castle[i][j] = charToInt(a[i][j]);
        v[charToInt(a[i][j])].push_back(mp(i,j));
      }
    }
  }

  for (int i=1; i<=p; i++) {
    q1.push(i);
  }
  
  while(!q1.empty()) {
    int player = q1.front();
    fill(&dist[0][0], &dist[1000+5-1][1000+5], 1000*1000+5);
    q1.pop();
    for (auto pi : v[player]) {
      dist[pi.X][pi.Y] = 0;
      castle[pi.X][pi.Y] = player;
      q2.push(pi);
    }
    v[player].clear();
    if (q2.empty()) continue;
    while(!q2.empty()) {
      int x = q2.front().X;
      int y = q2.front().Y;
      int move = dist[x][y];
      q2.pop();
      if (move == how_move[player]) {
        v[player].push_back(mp(x,y));
        continue;
      }
      for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBound0(nx,ny,n,m)) continue;
        else if (castle[nx][ny] != 0 || a[nx][ny]=='#') continue; // 이미 지나왔거나, 다른 사람 영역
        else if (move + 1 < dist[nx][ny]) {
          // 최단 경로일 경우
          q2.push(mp(nx,ny));
          dist[nx][ny] = move + 1;
          castle[nx][ny] = player;
        }
      }
    }
    q1.push(player);
  }
  int ans[10] = {0};
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      ans[castle[i][j]]++;
    }
  }
  for (int i=1; i<=p; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}