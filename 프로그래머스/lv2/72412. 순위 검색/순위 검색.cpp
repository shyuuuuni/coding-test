#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, int> getMask;
    int cnt[256][100000+10] = {0, };

    //########### bitmasking ###########
    // condition
    getMask["-"] = 0;
    getMask["and"] = 0;

    // language
    getMask["cpp"] = 1<<6;             // 64
    getMask["java"] = 1<<7;            // 128
    getMask["python"] = (1<<6)+(1<<7); // 192

    // front/back
    getMask["backend"] = 1<<4;     // 16
    getMask["frontend"] = 1<<5;    // 32

    // career
    getMask["junior"] = 1<<2;      // 4
    getMask["senior"] = 1<<3;      // 8

    // food
    getMask["chicken"] = 1<<0;     // 1
    getMask["pizza"] = 1<<1;       // 2
    //########### bitmasking ###########

    // 비트마스킹을 이용해 코딩테스트 값 저장
    for (string s : info) {
        int point;
        const int LOOP = 4;
        string opt;
        stringstream ss;
        vector<int> masks;

        ss.str(s); // s -> stream
        
        // info에서 조건 가져와서 마스크로 변환
        for (int i=1; i<=LOOP; i++) {
            ss >> opt;
            masks.push_back(getMask[opt]);
        }

        // 모든 경우의 수에 대해서 코딩 테스트 점수 추가
        ss >> point;
        for (int i=0; i<LOOP*LOOP; i++) {
            int idx = 0, div = i;
            for (int j=0; j<LOOP; j++) {
                int r = div % 2;
                div /= 2;
                idx += masks[j] * r;
            }
            cnt[idx][point]++;
        }
    }

    // 누적합 구하기
    for (int i=0; i<256; i++) {
        for (int j=1; j<100000+10; j++) {
            cnt[i][j] += cnt[i][j-1];
        }
    }

    for (string s : query) {
        int point, idx = 0;
        const int LOOP = 7;
        string opt;
        stringstream ss;

        ss.str(s);

        // 쿼리에서 조건을 가져와서 마스크로 변환
        for (int i=1; i<=LOOP; i++) {
            ss >> opt;
            idx += getMask[opt];
        }
        ss >> point;
        answer.push_back(cnt[idx][100000+5] - cnt[idx][point-1]);
    }

    return answer;
}