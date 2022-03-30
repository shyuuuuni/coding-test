#include <bits/stdc++.h>
using namespace std;

int toSeconds(string hms) {
    int sec = 0;

    sec += ((hms[0]-'0')*10 + (hms[1]-'0')) * 60 * 60; // h to sec
    sec += ((hms[3]-'0')*10 + (hms[4]-'0')) * 60; // m to sec
    sec += ((hms[6]-'0')*10 + (hms[7]-'0')); // s to sec

    return sec;
}

string toHms(int sec) {
    string hms = "";
    int q;

    // calc h
    q = sec / (60 * 60); sec = sec % (60 * 60);
    if (q < 10) hms.push_back('0');
    hms.append(to_string(q)+":");

    // calc m
    q = sec / (60); sec = sec % (60);
    if (q < 10) hms.push_back('0');
    hms.append(to_string(q)+":");

    // calc sec
    q = sec;
    if (q < 10) hms.push_back('0');
    hms.append(to_string(q));
    
    return hms;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int answer = 0;

    // play time, adv_time to seconds
    int pt = toSeconds(play_time);
    int at = toSeconds(adv_time);

    // 구간 합을 위한 누적합
    vector<long long> segsum(pt+1, 0);
    
    // logs to seconds
    for (auto &log : logs) {
        segsum[toSeconds(log.substr(0,8))]++;
        segsum[toSeconds(log.substr(9))]--;
    }

    for (int i=1; i<=pt; i++) {
        segsum[i] += segsum[i-1];
    }
    
    for (int i=1; i<=pt; i++) {
        segsum[i] += segsum[i-1];
    }
    
    long long cur_mx = -1;
    for (int i=0; i<=pt; i++) {
        if (pt < i + at) break;
        long long cur = segsum[i+at-1];
        if (0 < i) cur -= segsum[i-1];
        if (cur_mx < cur) {
            cur_mx = cur;
            answer = i;
        }
    }
    
    return toHms(answer);
}