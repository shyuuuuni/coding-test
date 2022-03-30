/*
Time : 2022.03.08
Problem : BOJ1916 (https://www.acmicpc.net/problem/1916)
Algorithm Type : 다익스트라
Outline :
N개의 도시에서, 출발지->도착지로 이동하는 버스가 M개 있다.
A->B 로 이동하는 최소 비용을 출력한다.
Method :

Example :
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
-------
4
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

int n;
int m;
int stt, dst;
const int INF = 1 << 30;
vector<pii> adj[1000+5];
int dist[1000+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  cin >> m;
  for (int i=0; i<m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w,b});
  }
  cin >> stt >> dst;
  fill(dist, dist+1000+5, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[stt] = 0;
  pq.push({0, stt});
  while (!pq.empty()) {
    int cur = pq.top().second; int cur_dist = pq.top().first; pq.pop();
    if (dist[cur] != cur_dist) continue;
    for (pii nxt : adj[cur]) {
      if (dist[nxt.second] <= cur_dist + nxt.first) continue;
      dist[nxt.second] = cur_dist + nxt.first;
      pq.push({dist[nxt.second], nxt.second});
    }
  }

  cout << dist[dst];

  return 0;
}