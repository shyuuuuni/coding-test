/*
Time : 2022.03.09
Problem : BOJ11780 (https://www.acmicpc.net/problem/11780)
Algorithm Type : 플로이드
Outline :
n(2 ≤ n ≤ 100)개의 도시가 있다.
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다.
각 버스는 한 번 사용할 때 필요한 비용이 있다.
모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값과 그 경로를 구하는 프로그램을 작성하시오.
Method :
모든 도시에서 각 도시로 이동하는 최단 거리를 구하는 문제이므로 플로이드 알고리즘을 사용한다.
기존 문제와 다른 점은 경로를 출력해야 한다는 점이다.
Example :
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4
-------
0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0
0
2 1 2
2 1 3
2 1 4
3 1 3 5
4 2 4 5 1
0
5 2 4 5 1 3
2 2 4
3 2 4 5
2 3 1
3 3 5 2
0
2 3 4
2 3 5
3 4 5 1
3 4 5 2
4 4 5 1 3
0
2 4 5
2 5 1
2 5 2
3 5 1 3
3 5 2 4
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

int n; // 도시 개수
int m; // 버스(간선) 개수
const int INF = 0x3f3f3f3f;
int dist[100+5][100+5];
int prv[100+5][100+5];
vector<pii> adj[100+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  fill(&dist[0][0], &dist[100+5-1][100+5], INF);

  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c}); // a->b로 가중치가 c인 간선이 있다
    if (c < dist[a][b]) {
      dist[a][b] = c;
      prv[a][b] = a;
    }
  }

  for (int i=1; i<=n; i++) {
    dist[i][i] = 0;
    prv[i][i] = i;
  }

  for (int k=1; k<=n; k++) { // 중간
    for (int i=1; i<=n; i++) { // 출발
      for (int j=1; j<=n; j++) { // 도착
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          prv[i][j] = prv[k][j];
        }
      }
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (dist[i][j] == INF) cout << 0 << " ";
      else cout << dist[i][j] << " ";
    }
    cout << "\n";
  }

  stack<int> ans;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (dist[i][j] == INF || i == j) {
        cout << 0 << "\n";
        continue;
      }
      int ptr = j;
      while (1) {
        ans.push(ptr);
        if (i == ptr) break;
        ptr = prv[i][ptr];
      }
      cout << ans.size() << " ";
      while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
      }
      cout << "\n";
    }

  }

  return 0;
}