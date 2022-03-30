/*
Time : 2022.03.09
Problem : BOJ17182 (https://www.acmicpc.net/problem/17182)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
N개의 행성이 있다.
그 중에서 K라는 행성에서 출발하여 다른 모든 행성을 적어도 한번씩 방문하려고 한다.
행성간 이동시 필요한 시간이 주어졌을 때, 최소 이동 시간을 출력한다.
Method :

Example :
4 1
0 83 38 7
15 0 30 83
67 99 0 44
14 46 81 0
-------
74
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

const int INF = 0x3f3f3f3f;
const int N = 15;
int n, me;
int dist[N][N];
int nxt[N][N];
int vis[N];
vector<int> ans;
int mn = INF;

void solve(int ptr, int len) {
  // 현재 위치가 ptr, len개 방문함
  if (len == n) {
    int cur = 0;
    for (int a : ans) {
      cur += a;
    }
    if (cur < mn) mn =  cur;
    return;
  }
  // cout << ptr << " "<< len <<  "\n";
  for (int i=0; i<n; i++) {
    if (vis[i] || i==ptr) continue;
    int st = ptr;
    vector<int> path;
    while (1) {
      if (vis[st] == 0) {
        vis[st] = 1;
        path.push_back(st);
      }
      if (st == i) break;
      st = nxt[st][i];
    }
    ans.push_back(dist[ptr][i]);
    solve(i, len+path.size());

    ans.pop_back();
    for (int p : path) {
      vis[p] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // fast io
  
  cin >> n >> me;
  fill(&dist[0][0], &dist[N-1][N], INF);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int w;
      cin >> w;
      if (w < dist[i][j]) {
        dist[i][j] = w;
        nxt[i][j] = j; // i->j로 이동하기 위한 최단거리에서 i의 다음 노드
      }
    }
  }
  for (int i=0; i<n; i++) {
    dist[i][i] = 0;
    nxt[i][i] = -1;
  }
  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (dist[i][k]+dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k]+dist[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<n; j++) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  vis[me] = 1;
  solve(me, 1);

  cout << mn;

  return 0;
}