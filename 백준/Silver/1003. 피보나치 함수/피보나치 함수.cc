/*
Time : 2022.02.10 (10 mins)
Problem : BOJ1003 (https://www.acmicpc.net/problem/1003)
Algorithm Type : Dynamic Programming
Outline :
n번째 피보나치 수를 구할 때, n==0과 n==1이 출력되는 횟수를 출력한다.
Method :
피보나치 수는 fib(n) = fib(n-1) + fib(n-2)로 구한다.
각 피보나치 수를 구할 때 출력하는 0과 1의 개수도 마찬가지로 위 점화식을 따른다.
즉, one(n) = one(n-1) + one(n-2) (one -> zero도 성립) 이 성립한다.
위 성질을 dp로 미리 계산하고, 테스트케이스별로 출력한다.
Example :
3
0
1
3
-------
1 0
0 1
1 2
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

bool compare(const string &a, const string &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  int o[40+5] = {};
  int z[40+5] = {};
  o[0] = 0; o[1] = 1;
  z[0] = 1; z[1] = 0;
  for(int i=2; i<=40; i++) {
    // fib(i) = fib(i-1) + fib(i-2)
    // i번째 0/1 수 = (i-1) 0/1수 + (i-2) 0/1 수
    o[i] = o[i-1] + o[i-2];
    z[i] = z[i-1] + z[i-2];
  }
  cin >> tc;
  while(tc--) {
    int x;
    cin >> x;
    cout << z[x] << " " << o[x] << "\n";
  }
  return 0;
}