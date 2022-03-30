/*
Time : 2022.03.08
Problem : BOJ1753 (https://www.acmicpc.net/problem/1753)
Algorithm Type : Simulation
Outline :
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
Method :

Example :
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
-------
0
2
3
7
INF
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

int v, e;
int k; // 시작 정점
const int INF = (1 << 30);
vector<pii> con[20000+1]; // con[i] : i번째 정점에 연결되어 있는 (가중치, 정점) 벡터
int dist[20000+1]; // dist[i] : k로부터 i까지의 최단 경로
priority_queue<pii, vector<pii>, greater<pii>> pq; // (가중치, 다음정점) 입력

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> v >> e;
  cin >> k;
  for (int i=0; i<e; i++) {
    int s, d, w;
    cin >> s >> d >> w;
    con[s].push_back(mp(w, d));
  }

  fill(dist, dist+20000+1, INF);

  // pq : 
  dist[k] = 0;
  pq.push({0,k});
  
  while (!pq.empty()) {
    int d = pq.top().first;
    int x = pq.top().second;
    pq.pop();
    if (dist[x] != d) continue;

    // 최솟값으로 갱신
    dist[x] = d;

    for (pii nxt : con[x]) {
      if (dist[nxt.second] <= d + nxt.first) continue; // 기존 경로가 최단 경로일 경우
      dist[nxt.second] = d + nxt.first;
      pq.push({dist[nxt.second], nxt.second}); // start->x->nxt 가 최단경로임
      // cout << "push" << dist[nxt.second] << " " << nxt.second << "\n";
    }
  }

  for (int i=1; i<=v; i++) {
    if (dist[i] == INF) cout << "INF\n";
    else cout << dist[i] << "\n";
  }


  return 0;
}