/*
Time : 2022.03.22
Problem : BOJ1976 (https://www.acmicpc.net/problem/1976)
Algorithm Type : 집합, 유니온파인드
Outline :
도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 판별하는 프로그램을 작성하시오.
같은 도시를 여러 번 방문하는 것도 가능하다.
가능하다면 YES, 불가능하다면 NO를 출력한다.
Method :

Example :
3
3
0 1 0
1 0 1
0 1 0
1 2 3
-------
YES
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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const int N = 200+100;
int n, m;
int adj[N][N];
int parent[N], unionRank[N];

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void unionByRank(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return;
  if (unionRank[x] > unionRank[y]) swap(x,y); // x < y도록 유지
  if (unionRank[x] == unionRank[y]) unionRank[x]++; // x == y이면 전체 트리 높이 +1
  parent[y] = x;
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  cin >> n >> m;

  for (int i=1; i<=n; i++) parent[i] = i;

  for (int i=1; i<=n; i++) unionRank[i] = 1;

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> adj[i][j];
      if (adj[i][j] && getParent(i) != getParent(j)) {
        unionByRank(i, j);
      }
    }
  }

  int flag;
  cin >> flag;

  for (int i=2; i<=m; i++) {
    int city;
    cin >> city;
    if (getParent(flag) != getParent(city)) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}
