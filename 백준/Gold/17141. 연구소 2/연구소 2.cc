/**
 * @file 백준-17141-연구소2-시뮬레이션.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 시뮬레이션 연습 문제 풀이
 * @date 2022-07-12
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;

const int INF = -100;
int n; // 연구소 크기
int m; // 바이러스 개수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int> > ori; // 연구소 원본
vector<int> seq;
vector<pair<int, int> > points;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ori.push_back(vector<int>(n));
        for (int j = 0; j < n; j++) {
            cin >> ori[i][j];
            if (ori[i][j] == 2) {
                points.push_back(make_pair(i, j));
            }
        }
    }
    seq = vector<int>(points.size(), 1);
    for (int i = 0; i < points.size() - m; i++)
    {
        seq[i] = 0;
    }
    return;
}

vector<vector<int> > createMap() {
    vector<vector<int> > result = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) {
        result[i] = vector<int>(ori[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == 1) {
                result[i][j] = INF;
            } else if (result[i][j] == 2) {
                result[i][j] = 0;
            }
        }
    }
    return result;
}

vector<pair<int,int> > initVirus(vector<int> &seq, vector<vector<int> > &curMap) {
    vector<pair<int, int> > result;
    int cnt = 0;

    for (int i = 0; i < points.size(); i++) {
        if (seq[i] == 0) {
            continue;
        }
        result.push_back(points[i]);
    }

    return result;
}

int main(void) {
    init();

    int answer = 50*50+1;

    // logic
    do {
        queue<pair<int, pair<int, int> > > q; // bfs queue
        vector<vector<int> > curMap = createMap();
        int vis[50][50] = {};
        int curTime = 0;

        // 처음 바이러스 초기화
        vector<pair<int, int> > virus = initVirus(seq, curMap);
        for (auto pii : virus)
        {
            q.push(make_pair(0, pii));
            vis[pii.first][pii.second] = 1;
        }


        while (!q.empty()) {
            int t = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            curTime = max(t, curTime);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || n <= nx || n <= ny) {
                    continue;
                }
                if (vis[nx][ny] == 1) {
                    continue;
                }
                if (curMap[nx][ny] != 0) {
                    continue;
                }

                curMap[nx][ny] = t + 1;
                vis[nx][ny] = 1;
                q.push(make_pair(t + 1, make_pair(nx, ny)));
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && curMap[i][j] == 0) {
                    flag = false;
                }
            }
        }

        if (flag) {
            answer = min(curTime, answer);
        }
    } while (next_permutation(seq.begin(), seq.end()));

    if (answer == 50*50+1) {
        cout << -1;
    } else {
        cout << answer;
    }

    return 0;
}