#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> is_win(50, 0);
    int lotto_rank[10] = {6, 6, 5, 4, 3, 2, 1, 6, };
    int correct = 0, failure = 0, zeros = 0;
    for (int x : win_nums) {
        is_win[x] = 1;
    }
    for (int x : lottos) {
        if (x == 0) {
            zeros++;
        } else if (is_win[x]) {
            correct++;
        } else {
            failure++;
        }
    }
    answer.push_back(lotto_rank[correct+zeros]); // 최대 등수
    answer.push_back(lotto_rank[correct]); // 최저 등수
    return answer;
}