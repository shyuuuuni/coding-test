 /* @author shyuuuuni (seunghyun4525@gmail.com)
  * @brief 백준 시뮬레이션 연습 문제 풀이

  * @copyright Copyright (c) 2022
  * 
  * 문제 조건을 꼼꼼히 살펴보아야 한다. 물고기를 먹을 때 마다 먹은 위치에서부터 새로 BFS를 시작하고,
  * 최단거리를 먼저 구하고, 최단거리 내의 모든 물고기 집합을 구한다.
  * 그 중에서 문제 조건에 부합하는 우선순위를 부여해 정렬 한 후 가장 적합한 물고기로 처리해야 한다.
  */
#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> stt;
int board[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                stt = make_pair(i, j);
                board[i][j] = 0;
            } else if (board[i][j] == 1) {
                board[i][j] = -1;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(stt);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int dist = board[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != -1) continue;

            board[nx][ny] = dist + 1;
            q.push(make_pair(nx, ny));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}