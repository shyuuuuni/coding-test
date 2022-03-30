/*
Time : 2022.02.21
Problem : BOJ11967 (https://www.acmicpc.net/problem/11967)
Algorithm Type : BFS
Outline :
NxN개의 방이 있는 헛간이 있다. 좌표는 (1,1) ~ (N,N)까지 번호로 붙어있다.
최대한 많은 방에 불을 켜려고 한다.
처음에는 (1,1)에만 불이 커져있다. 또한 불이 켜져있는 방으로만 들어갈 수 있다.
또한 방에는 스위치가 있어서, 해당 스위치를 키면 다른 방의 불을 끄고 켤 수 있다.
불을 켤 수 있는 최대 방의 개수를 출력한다.
Method :
Example :
3 6
1 1 1 2
2 1 2 2
1 1 1 3
2 3 3 1
1 3 1 2
1 3 2 1
-------
5
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

int n, m;
int a[100+5][100+5];
int clicked[100+5][100+5];
vector<pii> v[100+5][100+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;

  for (int i=0; i<m; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    v[x-1][y-1].push_back(mp(a-1,b-1));
  }

  pii nxt;
  int flag = -1;
  a[0][0] = 1;
  for (auto p : v[0][0]) {
    a[p.first][p.second] = 1;
  }

  while(1) {
    int visit[100+5][100+5] = {};
    queue<pii> q;

    if (flag == -1) {
      nxt = mp(0,0);
    }
    flag = 0;

    q.push(nxt);
    visit[nxt.first][nxt.second] = 1;
    
    while(!q.empty()) {
      int x = q.front().X;
      int y = q.front().Y;
      // cout << x << " " << y << "\n";
      q.pop();
      for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBound0(nx,ny,n,n)) continue;
        else if (visit[nx][ny] == 1) continue;
        else if (a[nx][ny] == 0) continue;
        else {
          if (v[nx][ny].size() != 0) {
            // 스위치가 있는 경우
            for (auto p : v[nx][ny]) {
              if (a[p.first][p.second] == 0) {
                nxt = mp(nx,ny);
                flag = 1;
              }
              a[p.first][p.second] = 1;
            }
          }
          visit[nx][ny] = 1;
          q.push(mp(nx,ny));
        }
      }
    }

    if (flag == 0) break;
  }

  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (a[i][j] == 1) ans++;
    }
  }

  cout << ans;

  return 0;
}