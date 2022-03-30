/*
Time : 2022.02.21
Problem : BOJ9328 (https://www.acmicpc.net/problem/9328)
Algorithm Type : BFS
Outline :
H x W 크기의 빌딩 지도가 있다.
. : 빈 공간
* : 벽
$ : 문서
알파벳 대문자 : 문
알파벳 소문자 : 열쇠 (그 알파벳 대문자에 대한)
지도가 주어졌을 대, 상근이가 훔칠 수 있는 최대 문서의 개수를 출력한다.
Method :
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
5 11
*.*********
*...*...*x*
*X*.*.*.*.*
*$*...*...*
***********
0
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony
-------
3
1
0
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

int tc;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int ans = 0;
    int h,w;
    queue<pii> q;
    queue<pii> locked[26];
    char a[100+5][100+5] = {};
    int key[26] = {};
    int vis[100+5][100+5] = {};
    cin >> h >> w;

    fill(&a[0][0], &a[100+5-1][100+5], '.');
    
    for (int i=1; i<=h; i++) {
      for (int j=1; j<=w; j++) {
        cin >> a[i][j];
      }
    }

    string s;
    cin >> s;
    if (s[0] != '0') {
      for (char c : s) {
        int idx = charToInt(c);
        key[idx] = 1;
      }
    }

    q.push(mp(0,0));
    vis[0][0] = 1;

    while (!q.empty()) {
      int x = q.front().X;
      int y = q.front().Y;
      // cout << x << " " << y << "\n";
      q.pop();
      if (a[x][y] == '$') ans++;
      for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx<0 || ny<0 || h+1<nx || w+1<ny) continue;
        if (vis[nx][ny]==1 || a[nx][ny]=='*') continue;
        else if ('A' <= a[nx][ny] && a[nx][ny] <= 'Z') { // 문
          int idx = charToInt(a[nx][ny]);
          if (key[idx]) {
            q.push(mp(nx,ny));
            vis[nx][ny] = 1;
          } else {
            locked[idx].push(mp(nx,ny));
          }
        }
        else if ('a' <= a[nx][ny] && a[nx][ny] <= 'z') { // 열쇠
          int idx = charToInt(a[nx][ny]);
          q.push(mp(nx,ny));
          vis[nx][ny] = 1;
          if (!key[idx]) {
            key[idx] = 1;
            while (!locked[idx].empty()) {
              q.push(locked[idx].front());
              vis[locked[idx].front().X][locked[idx].front().Y] = 1;
              locked[idx].pop();
            }
          }
        }
        else {
          q.push(mp(nx,ny));
          vis[nx][ny] = 1;
        }
      }
    }

    // for (int i=0; i<=h; i++) {
    //   for (int j=0; j<=w; j++) {
    //     cout << vis[i][j];
    //   }
    //   cout << "\n";
    // }

    cout << ans << "\n";
  }
  return 0;
}