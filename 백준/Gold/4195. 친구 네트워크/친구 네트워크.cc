/*
Time : 2022.03.22
Problem : BOJ4195 (https://www.acmicpc.net/problem/4195)
Algorithm Type : 집합, 유니온파인드
Outline :
테스트케이스마다 친구 관계의 수와, 친구 관계가 주어진다.
친구 관계로는 문자열 두개가 주어지며, A와 B가 친구 관계라는 의미이다.
친구 네트워크는 친구 관계인 사람, 친구의 친구, ... 와 같이 친구 관계로 묶인 네트워크를 의미한다.
입력으로 문자열이 들어올 때 마다, 두 사람의 친구 네트워크의 사람 수를 출력한다.
Method :

Example :
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty
-------
2
3
4
2
2
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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const int N = 200000 + 100;
int parent[N], netSize[N];

int getParent(int x) {
  if (x == parent[x]) return x;

  return parent[x] = getParent(parent[x]);
}

int unionBySize(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return netSize[x];
  if (netSize[x] < netSize[y]) swap(x,y); // x가 더 크도록 유지
  parent[y] = x;
  netSize[x] += netSize[y];
  return netSize[x];
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  int tc;
  cin >> tc;
  while (tc--) {
    for (int i=1; i<N; i++) {
      parent[i] = i;
      netSize[i] = 1;
    }
    int f, n = 1;
    map<string, int> mp;
    cin >> f;
    while (f--) {
      string x, y;
      cin >> x >> y;
      if (mp.find(x) == mp.end()) {
        mp[x] = n++;
      }
      if (mp.find(y) == mp.end()) {
        mp[y] = n++;
      }
      int xx = mp[x];
      int yy = mp[y];
      cout << unionBySize(xx, yy) << "\n";
    }
  }

  return 0;
}
