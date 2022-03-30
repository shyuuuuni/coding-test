/*
Time : 2022.01.12 (40 min)
Problem : BOJ9466 (https://www.acmicpc.net/problem/9466)
Algorithm Type : BFS
Outline :
학생 1, 2, 3, 4, ..., N이 프로젝트를 함께하고 싶은 팀원을 선택한다.
학생 1이 1(자기자신)을 선택한 경우 혼자 팀이 될 수 있다.
학생 1이 학생 2를, 학생 2가 학생 3을, ..., 학생 r이 학생 1을 선택한다면
학생 1~r은 한 팀으로 될 수 있다.
어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    int target[100000+1]; // target[i] = j (학생 i가 j를 지목)
    int vis[100000+1]; // -1이면 미방문, 1이상이면 시작점의 인덱스를 가지고 있음.
    int valid_start[100000+1]={0}; // valid_start[i] = 0이면 i부터 시작한건 팀X, 1이면 팀
    queue<pii> q;
    fill(vis, vis+100001, -1);
    for(int i=1; i<=n; i++) cin >> target[i];
    for(int i=1; i<=n; i++) {
      if(vis[i] != -1) continue;
      if(vis[target[i]] != -1) {
        // 내가 지목한 학생이 이전에 방문한 학생인 상황
        // -> 이전에 방문했다면 순회하면서 나를 왔어야 함.
        // 그러나 vis[i]가 -1이므로 나에게 돌아오지 않는다는것을 의미함.
        vis[i] = i;
        valid_start[i] = 0;
      } else {
        // vis[target[i]] == -1
        // 내가 시작점이라는 의미
        q.push(mp(i, target[i])); //(start_idx, cur_idx)
      }
      while(!q.empty()) {
        int start_idx = q.front().first;
        int cur_idx = q.front().second;
        vis[cur_idx] = start_idx;
        q.pop();
        if(target[cur_idx] == start_idx) {
          // 돌고 돌아서 시작점으로 돌아왔다 = 팀
          
        }
      }
    }
  }
  return;
}

int target[100000+1]; // target[i] = j (학생 i가 j를 지목)
int start_idx[100000+1]; // -1이면 미방문, 1이상이면 시작점의 인덱스를 가지고 있음.
int valid_start[100000+1]={0}; // valid_start[i] = 0이면 i부터 시작한건 팀X, 1이면 팀
int dfs(int stt, int cur) {
  int t = target[cur];
  int ans = 0;
  start_idx[cur] = stt;
  if(start_idx[t] == -1) { // 다음 노드가 이전에 방문X
    ans = dfs(stt, t);
  } else { // 다음 노드가 이전에 방문 O
    if(start_idx[t] == start_idx[cur]) {
      // 사이클이 생긴 경우 ... -> {t -> cur -> t}
      ans = t;
      start_idx[cur] = t;
      valid_start[t] = 1;
    } else {
      // 이전에 방문한 노드인데, 출발점이 다름
      // 이전에 방문했다면 사이클이라면 현재 노드를 들렸을것임.
      // 따라서 invalid
      ans = 0;
      valid_start[stt] = 0;
    }
  }
  if(ans) {
    start_idx[cur] = ans;
    if(cur == ans) ans = 0;
  }
  return ans;
}
void solve1() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n; cin >> n;
    fill(start_idx, start_idx+100001, -1);
    fill(valid_start, valid_start+100001, 0);
    for(int i=1; i<=n; i++) cin >> target[i];
    for(int i=1; i<=n; i++) {
      if(start_idx[i] != -1) continue; // 전에 방문한 노드
      if(start_idx[target[i]] != -1) continue; // 다음 노드가 이전에 방문한 노드
      int check = dfs(i, i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
      int s = start_idx[i];
      if(valid_start[s] == 0) ans++;
    }
    cout << ans << "\n";
  //   for(int i=1; i<=n; i++) {
  //     cout << i << " ";
  //   } cout << "\n";
  //   for(int i=1; i<=n; i++) {
  //     cout << start_idx[i] << " ";
  //   } cout << "\n";
  //   for(int i=1; i<=n; i++) {
  //     cout << valid_start[i] << " ";
  //   } cout << "\n";
  }
  return;
}