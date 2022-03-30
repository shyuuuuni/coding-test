/*
Time : 2022.01.07 (20 min)
Problem : BOJ1874 (https://www.acmicpc.net/problem/1874)
Algorithm Type : Stack
Outline :
스택을 이용하여 주어진 수열을 만든다.
1부터 N까지의 숫자를 순서대로 push, pop 할 수 있다.
이때 pop 하면서 나온 순서대로 수열을 구성하는데, 문제에서 주어지는
수열이 만들 수 있는지를 확인하고, 만들 수 있다면 push-pop 순서를 출력한다.
Method :
1부터 N까지 순서대로 숫자를 빼오기 위해서 nums라는 이름의 정수 스택을 선언했다.
스택 s는 문제에서 수열을 만들기 위해서 사용하는 스택이다.
만약 입력으로 들어온 이번에 나와야 하는 숫자가, 현재 s의 top보다 작다면 NO를 출력한다.
(왜냐하면 입력으로 들어온 수열을 뽑기 위해서는 스택에서 pop 해야 하는데,
스택의 특성상 top에서만 pop 할 수 있기 때문에 출력이 불가능하다.)
이외의 경우에는 해당 숫자에 맞춰서 스택을 push, pop 하면서
정답 출력용 queue인 ans에 문자를 추가하면서 진행한다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

int used[100000 + 1];
void solve1() {
  int tc, ptr=1;
  stack<int> s, nums;
  queue<char> ans;
  cin >> tc;
  for(int i=tc; 0<i; i--) nums.push(i);
  while(tc--) {
    // cout << "current :" << (!s.empty()?s.top():-1) << " " << (!nums.empty()?nums.top():-1) << "\n";
    int n;
    cin >> n;
    if(!s.empty() && n < s.top()) {
      cout << "NO";
      return;
    } else {
      while(!nums.empty() && nums.top() <= n) {
        s.push(nums.top());
        nums.pop();
        ans.push('+');
      }
      while(!s.empty() && n <= s.top()) {
        s.pop();
        ans.push('-');
      }
    }
  }
  while(!ans.empty()) {
    cout << ans.front() << "\n";
    ans.pop();
  }
  return;
}