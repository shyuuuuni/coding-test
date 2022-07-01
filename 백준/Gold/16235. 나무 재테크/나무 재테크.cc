/**
 * @file 백준-16235-나무 재테크-시뮬레이션.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 시뮬레이션 연습 문제 풀이
 * @date 2022-07-01
 * 조건에 맞추어 적절히 구현한다. 나이가 작은 나무부터 영양분을 섭취하는 것을 정렬을 이용한다.
 */
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int energy[10 + 1][10 + 1]; // 땅의 양분
int add[10 + 1][10 + 1]; // 겨울마다 더할 양분
vector<int> tree[10 + 1][10 + 1]; // (i,j)위치에 있는 나무
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 인접 8칸
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 인접 8칸

int
main(void)
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            energy[i][j] = 5;
            cin >> add[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    int year = 0;
    while (year < k) {
        year++;
        

        // 봄
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) {
                if (tree[i][j].empty()) {
                    continue;
                }
                // init
                vector<int> nxt;
                int add_energy = 0;
                sort(tree[i][j].begin(), tree[i][j].end());

                for (int t = 0; t < tree[i][j].size(); t++)
                {
                    if (tree[i][j][t] <= energy[i][j]) {
                        energy[i][j] -= tree[i][j][t];
                        nxt.push_back(tree[i][j][t] + 1);
                    } else {
                        add_energy += tree[i][j][t] / 2;
                    }
                }
                tree[i][j].clear();
                for (auto t : nxt) {
                    tree[i][j].push_back(t);
                }
                // 여름
                energy[i][j] += add_energy;
            }
        }

        // 가을
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (tree[i][j].empty()) {
                    continue;
                }
                for (auto t : tree[i][j]) {
                    if (t % 5 == 0) {
                        // 나무 번식
                        for (int l = 0; l < 8; l++) {
                            int nx = i + dx[l];
                            int ny = j + dy[l];
                            if (1 <= nx && 1 <= ny && nx <= n && ny <= n) {
                                tree[nx][ny].push_back(1);
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                energy[i][j] += add[i][j];
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            answer += tree[i][j].size();
        }
    }

    cout << answer;
    return 0;
}