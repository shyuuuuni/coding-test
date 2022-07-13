/**
 * @file 백준-1094-막대기-수학.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 수학 연습 문제 풀이
 * @date 2022-07-13
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int x;
    int cnt = 0;
    int div = 64;

    cin >> x;

    while (0 < x) {
        if (x < div) {
            div /= 2;
            continue;
        }
        x -= div;
        cnt++;
    }

    cout << cnt;
}