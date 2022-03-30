/*
Time : 2022.03.07
Problem : BOJ14889 (https://www.acmicpc.net/problem/14889)
Algorithm Type : BackTracking
Outline :
NxM 크기의 연구소에 0은 빈칸, 1은 벽, 2는 바이러스가 존재한다.
바이러스는 각 위치의 상하좌우로 퍼지게 된다.
이런 연구소에 벽을 3개 설치하려고 한다.
벽을 잘 설치해서 바이러스가 퍼지지 않는 안전영역의 넓이를 최대로 하게 만드시오.
Method :
N,M이 모두 3 이상, 8 이하의 자연수이다. 즉, 크기가 충분히 작다.
최대인 경우 64개 중, 3개의 위치에 벽을 세우는 경우이므로 64C3 = 약 42000개
42000개에 대해서 BFS를 돌아
Example :
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
-------
27
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
int board1[8][8], board2[8][8];
int mx = 0;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> board1[i][j];
    }
  }
  
  // 최대 8x8=64, 64 이하의 수 중에서 3개를 뽑는 경우
  vector<int> a(n*m, 0);
  for (int i=n*m-1; n*m-3<=i; i--)
    a[i] = 1;

  do {
    int flag = 1;
    int vis[8][8] = {};
    queue<pii> q;

    for (int i=0; i<n; i++) {
      for (int j=0; j<m&&flag; j++) {
        board2[i][j] = board1[i][j];
        if (a[i*m+j] == 1) {
          // (i,j)에 벽을 세우는 경우
          if (board2[i][j] != 0) {
            // 그 위치가 바이러스인 경우
            flag = 0;
          } else {
            board2[i][j] = 1;
          }
        }
        if (board2[i][j] == 2) {
          vis[i][j] = 1;
          q.push(mp(i,j));
        }
      }
    }
    if (flag == 0) continue;
    // cout << "curboard : \n";
    // for (int i=0; i<n; i++) {
    //   for (int j=0; j<m; j++) {
    //     cout << board2[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    while (!q.empty()) {
      int x = q.front().X;
      int y = q.front().Y;
      for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBound0(nx,ny,n,m) || vis[nx][ny]==1 || board2[nx][ny] != 0) continue;
        vis[nx][ny] = 1;
        q.push(mp(nx,ny));
      }
      q.pop();
    }

    // cout << "after board : \n";
    // for (int i=0; i<n; i++) {
    //   for (int j=0; j<m; j++) {
    //     cout << vis[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    int cur = 0;

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (board2[i][j] == 0 && vis[i][j] == 0) {
          cur++;
        }
      }
    }

    mx = max(mx, cur);

  } while(next_permutation(a.begin(), a.end()));

  cout << mx;

  return 0;
}