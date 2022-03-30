/*
Time : 2022.02.05 (30 mins)
Problem : BOJ14500 (https://www.acmicpc.net/problem/14500)
Algorithm Type : Simulation
Outline :
크기가 NxM인 종이 위에 숫자가 적혀있다.
종이 위에 폴리오미노 하나를 올려서 가려진 숫자의 최댓값을 출력한다.
Method :

Example :
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
-------
9
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dz[6] = {0,0,0,0,-1,1};
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

/*
 * declare here
 */
int n, m;
int board[500+1][500+1];
int idx = 0;

vector<pii> vsize;
vector<vector<int> > shape[30];

void ps(int sn) {
  pii s = vsize[sn];
  vector<vector<int> > v = shape[sn];
  for(int i=0; i<s.first; i++) {
    for(int j=0; j<s.second; j++) {
      if(v[i][j]) cout << v[i][j];
      else cout << " ";
    }
    cout << "\n";
  }
}

void rotation(vector<vector<int> > &vec, vector<vector<int> > &res, int &r, int &c) {
  vector<vector<int> > tmp(c, vector<int>(r,0));

  for(int i=0; i<c; i++)
    for(int j=0; j<r; j++)
      res[i][j] = vec[r-j-1][i];

  swap(r,c);
  return;
}

void init_with_rot(vector<vector<int> > origin, int r, int c) {
  vector<vector<int> > tmp1(r,vector<int>(c)); // 3x2
  vector<vector<int> > tmp2(c,vector<int>(r)); // 2x3
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      tmp1[i][j] = origin[i][j];

  shape[idx++] = tmp1; // 원본(3x2)
  vsize.push_back(mp(r, c));

  rotation(tmp1, tmp2, r, c); // 한번 회전(2x3)
  shape[idx++] = tmp2;
  vsize.push_back(mp(r, c));

  rotation(tmp2, tmp1, r, c); // 두번 회전(3x2)
  shape[idx++] = tmp1;
  vsize.push_back(mp(r, c));

  rotation(tmp1, tmp2, r, c); // 세번 회전(2x3)
  shape[idx++] = tmp2;
  vsize.push_back(mp(r, c));

  return;
}

void init() {
  // ㅡ 모양
  vector<vector<int> > tmp0(1,vector<int>(4)); // 1x4
  vector<vector<int> > tmp1(4,vector<int>(1)); // 4x1
  for(int i=0; i<4; i++) {
    tmp0[0][i] = 1;
    tmp1[i][0] = 1;
  }
  shape[idx++] = tmp0;
  vsize.push_back(mp(1, 4));

  shape[idx++] = tmp1;
  vsize.push_back(mp(4, 1));

  // ㅁ 모양
  vector<vector<int> > tmp2(2,vector<int>(2)); // 2x2
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      tmp2[i][j] = 1;
  shape[idx++] = tmp2;
  vsize.push_back(mp(2, 2));

  // ㄱ 모양
  int r = 3, c = 2;
  vector<vector<int> > tmp3(3,vector<int>(2)); // 3x2
  tmp3[0][0] = tmp3[1][0] = tmp3[2][0] = tmp3[2][1] = 1;
  init_with_rot(tmp3, r, c);

  r = 3, c = 2;
  vector<vector<int> > tmp4(3,vector<int>(2)); // 3x2
  tmp4[0][1] = tmp4[1][1] = tmp4[2][1] = tmp4[2][0] = 1; // reverse
  init_with_rot(tmp4, r, c);

  // ㄹ 모양
  r = 3, c = 2;
  vector<vector<int> > tmp5(3,vector<int>(2)); // 3x2
  vector<vector<int> > tmp6(2,vector<int>(3)); // 2x3
  tmp5[0][0] = tmp5[1][0] = tmp5[1][1] = tmp5[2][1] = 1;
  shape[idx++] = tmp5;
  vsize.push_back(mp(r,c));
  rotation(tmp5, tmp6, r,c);
  shape[idx++] = tmp6;
  vsize.push_back(mp(r,c));

  r = 3, c = 2;
  vector<vector<int> > tmp7(3,vector<int>(2)); // 3x2
  vector<vector<int> > tmp8(2,vector<int>(3)); // 2x3
  tmp7[0][1] = tmp7[1][1] = tmp7[1][0] = tmp7[2][0] = 1;
  shape[idx++] = tmp7;
  vsize.push_back(mp(r,c));
  rotation(tmp7, tmp8, r,c);
  shape[idx++] = tmp8;
  vsize.push_back(mp(r,c));

  // ㅜ 모양
  r = 2, c = 3;
  vector<vector<int> >tmp9(2, vector<int>(3)); // 2x3
  tmp9[0][0] = tmp9[0][1] = tmp9[0][2] = tmp9[1][1] = 1;
  init_with_rot(tmp9, r, c);

  return;
}


bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

void solve() {
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> board[i][j];

  init();

  // for(int i=0; i<vsize.size(); i++) {
  //   cout << vsize[i].first << " " << vsize[i].second << "\n";
  //   ps(i);
  // }
  
  int mx = -1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      for(int k=0; k<vsize.size(); k++) {
        vector<vector<int> > v = shape[k];
        int xl = vsize[k].first;
        int yl = vsize[k].second;
        int cur = 0;
        if(oob(i+xl-1, j+yl-1, n, m)) continue;
        for(int a=0; a<xl; a++) {
          for(int b=0; b<yl; b++) {
            if(v[a][b] == 1) cur += board[i+a][j+b];
          }
        }
        mx = max(mx, cur);
      }
    }
  }

  cout << mx;
  return;
}