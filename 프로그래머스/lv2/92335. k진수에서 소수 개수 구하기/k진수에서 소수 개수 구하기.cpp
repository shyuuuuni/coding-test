#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

#define EASY_MAX 10000000+1

vector<int> is_prime;
void prime_init_() {
    is_prime.assign(EASY_MAX, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i=2; i<sqrt(EASY_MAX)+1; i++) {
        if(!is_prime[i]) continue;
        for(int j=2; i*j < EASY_MAX+1; j++) {
            is_prime[i*j] = 0;
        }
    }
}

int prime_check(long long num) {
    int flag = 1;
    for(long long i=2; i*i <= num; i++) {
        if(num % i == 0) {
            flag = 0;
            break;
        }
    }
        
    return flag;
}

int solution(int n, int k) {
    int answer = 0;
    long long cur, prv=-1, t;
    stack<long long> stk;
    prime_init_();
    while(n) {
        long long r = n % k;
        n = n / k;
        stk.push(r);
    }
    cout << stk.size();
    while(!stk.empty()) {
        t = stk.top();
        stk.pop();
        if(t == 0) {
            if(prv <= 0) continue;
            else {
                if(EASY_MAX < cur) {
                    if(prime_check(cur)) answer++;
                } else {
                    if(is_prime[cur]) answer++;
                }
                prv = 0;
                cur = 0;
            }
        } else {
            if(prv <= 0) {
                cur = t;
            } else {
                cur *= 10;
                cur += t;
            }
            prv = t;
        }
    }
    if(prv) {
        if(EASY_MAX < cur) {
            if(prime_check(cur)) answer++;
        } else {
            if(is_prime[cur]) answer++;
        }
    }
    return answer;
}