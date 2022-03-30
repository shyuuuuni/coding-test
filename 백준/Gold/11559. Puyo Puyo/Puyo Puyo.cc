/*
Time : 2022.01.27 (1 hour)
Problem : BOJ11559 (https://www.acmicpc.net/problem/11559)
Algorithm Type : Simulation
Outline :
다음과 같은 룰을 가진 뿌요뿌요가 있다.
뿌요는 여러 색깔을 가진다. 뿌요는 중력의 영향으로 바닥이나 다른 뿌요가 나올 때 까지 아래로 떨어진다.
뿌요를 놓고 난 후 같은색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.
이걸 1연쇄라고 한다. 뿌요들이 없어지면 위에 다른 뿌요들 또한 차례대로 떨어진다.
마찬가지로 같은색 뿌요가 4개 이상 모이면 터지게 되고 1연쇄가 추가로 늘어난다.
터질 수 있는 뿌요가 여러 그룹이여도 동시에 터지고 한번의 연쇄만 추가된다.
필드가 주어졌을 때 연쇄가 몇 번 연속으로 일어나는지 출력한다.
Method :
최대 M개의 치킨집을 선택해서 치킨 거리가 최소가 될때
최소가 되게 하는 방법은 M개의 치킨집을 선택하는 방법이다.
(왜냐하면 치킨집이 많아야 각각의 집에서 치킨 거리가 짧아지기 때문)
따라서 (전체치킨집수)Combination(M) 의 조합의 경우의 수를 모두 테스트하며
각 경우마다 치킨 거리의 합을 구해서 최솟값을 출력한다.
이를 위해 next_permutation을 활용하여 조합을 완전탐색하였다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m;
string board1[12], board2[12];

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || n<=y);
}

void drop() {
  string tmp[12];
  for(int i=0; i<n; i++)
    tmp[i] = board2[i];
  for(int j=0; j<m; j++) {
    // j : x좌표
    int idx = n-1;
    for(int i=n-1; 0<=i; i--) {
      // i : y좌표
      if(board1[i][j]!='.')
        tmp[idx--][j] = board1[i][j];
    }
    for(int i=0; i<n; i++) {
      board1[i][j] = tmp[i][j];
    }
  }
  return;
}

int puyo() {
  int idx=0;
  int link[6*12] = {};
  int dst[12][6];
  int rmv = 0;
  queue<pair<pii,pair<char, int> > > q;
  fill(&dst[0][0], &dst[11][6], -1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(board1[i][j]=='.') continue;
      if(dst[i][j]!=-1) continue;
      dst[i][j] = idx;
      link[idx] = 1;
      q.push(mp(mp(i,j), mp(board1[i][j],idx++)));
      while(!q.empty()) {
        int x = q.front().first.X;
        int y = q.front().first.Y;
        int c = q.front().second.first;
        int num = q.front().second.second;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(oob(xx,yy)) continue;
          if(dst[xx][yy]!=-1 || board1[xx][yy]!=c) continue;
          q.push(mp(mp(xx,yy), mp(c,num)));
          dst[xx][yy] = num;
          link[num]++;
          if(4 == link[num]) {
            rmv++;
          }
        }
      }
    }
  }
  // cout << "result : \n";
  // for(int i=0; i<n; i++) {
  //   for(int j=0; j<m; j++)
  //     cout << dst[i][j] << " ";
  //   cout << "\n";
  // }
  // cout << "===\n";
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) {
      if(board1[i][j]!='.' && (4<=link[dst[i][j]])) {
        board1[i][j] = '.';
      }
    }
  }
  return rmv;
}

void solve() {
  n = 12; // 세로
  m = 6;  // 가로
  int ans=0;
  for(int i=0; i<n; i++) {
    cin >> board1[i];
    board2[i] = "......";
  }

  while(1) {
    drop();
    // for(int i=0; i<n; i++) {
    //   cout << board1[i] << "\n";
    // }
    if(puyo()) {
      ans++;
    } else {
      break;
    }
  }

  cout << ans;

  return;
}