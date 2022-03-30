#include <bits/stdc++.h>
using namespace std;

/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/

string solution(string new_id) {
    string answer = new_id;
    vector<int> rm;

    // Step 1
    for (auto &c : answer) {
        if ('A' <= c && c <= 'Z') {
            c += ('a' - 'A');
        }
    }

    // Step 2
    for (auto iter = answer.begin(); iter != answer.end();) {
        char c = *iter;
        if (('a' <= c && c <= 'z') ||
            ('0' <= c && c <= '9') ||
            (c == '-') ||
            (c == '_') ||
            (c == '.')) {
            iter++;
        } else {
            iter = answer.erase(iter);
            continue;
        }
    }

    // Step 3
    string buf = answer;
    answer = "";
    for (int i=0; i<(int)buf.size(); ) {
        char c = buf[i];
        int nxt = i+1;
        if (c == '.') {
            while (nxt<(int)buf.size()) {
                if (buf[nxt] == '.') {
                    nxt++;
                    continue;
                } else {
                    break;
                }
            }
        }
        answer.push_back(c);
        i = nxt;
    }

    // Step 4
    while (!answer.empty() && answer[0]=='.') {
        answer.erase(answer.begin());
    }
    while (!answer.empty() && answer.back()=='.') {
        answer.pop_back();
    }

    // Step 5
    if (answer.empty()) answer.push_back('a');

    // Step 6
    if (15 < answer.length()) {
        answer = answer.substr(0, 15);
    }
    while (!answer.empty() && answer.back()=='.') {
        answer.pop_back();
    }

    // Step 7
    while ((int)answer.size() < 3) {
        answer.push_back(answer.back());
    }

    return answer;
}