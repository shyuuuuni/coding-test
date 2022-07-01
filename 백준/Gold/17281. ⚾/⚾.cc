/**
 * @file 백준-17281-⚾-시뮬레이션.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 시뮬레이션 연습 문제 풀이
 * @date 2022-07-01
 * @copyright Copyright (c) 2022
 * 시뮬레이션을 next_permutation을 이용해 구현. 문제 조건에서 1번 타자를 4번째 타자로 고정한다는 조건을 주의한다.
 */
#include <bits/stdc++.h>

using namespace std;

int ining;
int hits[50][9];

int main(void) {
    int answer = 0;
    cin >> ining;
    for (int i = 0; i < ining; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> hits[i][j];
        }
    }

    int permutation[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    do {
        int cur_point = 0;
        int order[9];
        for (int i = 0; i < 9; i++) {
            if (i == 3) {
                order[i] = 0;
            } else if (i < 3) {
                order[i] = permutation[i];
            } else {
                order[i] = permutation[i - 1];
            }
        }

        // 주자
        int ptr = 0;

        // simulation
        for (int i = 0; i < ining; i++)
        {
            int result[9];
            int score = 0;
            int out = 0;
            int players = 0b0000;
            for (int j = 0; j < 9; j++)
            {
                result[j] = hits[i][order[j]];
            }

            while (out < 3)
            {
                int hit = result[ptr];

                if (hit == 0)
                {
                    out++;
                }
                else if (hit == 1)
                {
                    if ((players & 0b0100) == 0b0100)
                    {
                        score++;
                    }
                    players = ((players << 1) & 0b0111);
                    players = (players | 0b0001);
                }
                else if (hit == 2)
                {
                    if ((players & 0b0110) == 0b0110)
                    {
                        score += 2;
                    }
                    else if ((players & 0b0110) == 0b0100 || (players & 0b0110) == 0b0010)
                    {
                        score += 1;
                    }
                    players = ((players << 1) & 0b0111);
                    players = (players | 0b0001);
                    players = ((players << 1) & 0b0111);
                }
                else if (hit == 3)
                {
                    if ((players & 0b0111) == 0b0111)
                    {
                        score += 3;
                    }
                    else if ((players & 0b0111) == 0b0110 || (players & 0b0111) == 0b0011 || (players & 0b0111) == 0b0101)
                    {
                        score += 2;
                    }
                    else if ((players & 0b0111) == 0b0100 || (players & 0b0111) == 0b0010 || (players & 0b0111) == 0b0001)
                    {
                        score += 1;
                    }
                    players = ((players << 1) & 0b0111);
                    players = (players | 0b0001);
                    players = ((players << 1) & 0b0111);
                    players = ((players << 1) & 0b0111);
                }
                else
                {
                    // 홈런
                    if ((players & 0b0111) == 0b0111)
                    {
                        score += 3;
                    }
                    else if ((players & 0b0111) == 0b0110 || (players & 0b0111) == 0b0011 || (players & 0b0111) == 0b0101)
                    {
                        score += 2;
                    }
                    else if ((players & 0b0111) == 0b0100 || (players & 0b0111) == 0b0010 || (players & 0b0111) == 0b0001)
                    {
                        score += 1;
                    }
                    score++;
                    players = 0b0000;
                }

                ptr = (ptr + 1) % 9;
            }

            cur_point += score;
        }

        if (answer < cur_point) {
            answer = cur_point;
        }
    } while (next_permutation(permutation, permutation + 8));

    cout << answer;

    return 0;
}