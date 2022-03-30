/*
Time : 2022.02.21
Problem : BOJ1941 (https://www.acmicpc.net/problem/1941)
Algorithm Type : Backtracking
Outline :
25명의 여학생으로 이루어진 5x5 모양으로 자리가 배치된다.
25명의 여학생은 각각 S,Y 세력에 포함되어 있고, S는 소문난 칠공주를 만드려고 한다.
소문난 칠공주는 다음 조건을 만족한다.
1. 7명의 여학생들로 구성되어야 한다.
2. 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
3. 반드시 ‘이다솜파’(S)의 학생들로만 구성될 필요는 없다.
4. ‘이다솜파’(S)가 반드시 우위를 점해야 한다. 따라서 7명의 학생 중 ‘이다솜파’(S)의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
여학생반의 자리 배치도가 주어졌을 때, ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.
Method :

Example:
YYYYY
SYSYS
YYYYY
YSYYS
YYYYY
-------
2
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

const int n = 5;
int ans = 0;
char a[n][n];
int comb[25];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i=18; i<n*n; i++) {
    comb[i] = 1;
  }

  do {
    int mask[n][n] = {};
    int vis[n][n] = {};
    for (int i=0; i<n*n; i++) {
      mask[i/n][i%n] = comb[i];
    }

    // 1. Y의 개수와 S의 개수를 센다.
    int s=0, y=0;
    pii stt;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (mask[i][j]) {
          s += (a[i][j]=='S');
          y += (a[i][j]=='Y');
          stt = mp(i,j);
        }
      }
    }
    if (s < y) continue; // 이다솜파가 3명 이하인 경우 불가능
    // 2. 모두 연결되어있는지 확인한다.
    int flag = 0;
    queue<pii> q;
    vis[stt.X][stt.Y] = 1;
    q.push(stt);
    while (!q.empty()) {
      flag++;
      for (int i=0; i<4; i++) {
        int nx = q.front().X + dx[i];
        int ny = q.front().Y + dy[i];
        if(outOfBound0(nx,ny,n,n)) continue;
        if(vis[nx][ny]==1 || !mask[nx][ny]) continue;
        vis[nx][ny] = 1;
        q.push(mp(nx,ny));
      }
      q.pop();
    }
    if (flag==7) ans++;
  } while (next_permutation(comb, comb+n*n));

  cout << ans;

  return 0;
}