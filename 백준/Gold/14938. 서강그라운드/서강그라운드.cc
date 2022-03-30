/*
Time : 2022.03.09
Problem : BOJ11780 (https://www.acmicpc.net/problem/11780)
Algorithm Type : 플로이드
Outline :
N개의 지역에 R개의 길이 연결되어 있다.
각 지역에는 얻을 수 있는 아이템의 개수가 적혀있고, 길마다 거리가 존재한다.
예은이가 어떠한 지역에 내려와서 최대 M만큼의 거리를 이동할 수 있다고 한다.
예은이가 얻을 수 있는 최대 아이템 개수를 출력한다.
Method :

Example :
5 5 4
5 7 8 2 3
1 4 5
5 2 4
3 2 3
1 2 3
-------
23
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
const int N = 100+5;
int n, m, r; // 지역, 수색범위, 길 개수
int item[N];
int dist[N][N];
vector<pii> adj[N];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> r;
  fill(&dist[0][0], &dist[N-1][N], INF);
  for (int i=1; i<=n; i++) cin >> item[i];
  while (r--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
    if (c < dist[a][b]) {
      dist[a][b] = c;
    }
    if (c < dist[b][a]) {
      dist[b][a] = c;
    }
  }
  for (int i=1; i<=n; i++) dist[i][i] = 0;

  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        } 
      }
    }
  }

  int ans = 0;
  for (int start=1; start<=n; start++) {
    int cur = 0;
    for (int dest=1; dest<=n; dest++) {
      if (dist[start][dest] <= m) {
        cur += item[dest];
      }
    }
    if (ans < cur) {
      ans = cur;
    }
  }

  cout << ans;

  return 0;
}