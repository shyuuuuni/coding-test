/**
 * @file 백준-1978-소수 찾기.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 수학 연습 문제 풀이
 * @date 2022-07-14
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    int cnt = 0;
    vector<int> numbers;

    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    vector<int> isPrime(1000 + 1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 2; i * i <= 1000; i++) {
        if (isPrime[i] == 0) {
            continue;
        }
        for (int j = 2; i * j <= 1000; j++)
        {
            isPrime[i * j] = 0;
        }
    }

    for (int num : numbers) {
        if (isPrime[num])
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}