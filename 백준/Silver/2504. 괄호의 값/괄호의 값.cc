/*
Time : 2022.01.10 (20 min)
Problem : BOJ2054 (https://www.acmicpc.net/problem/2054)
Algorithm Type : Stack-Parenthesis
Outline :
소괄호와 대괄호를 이용해 만들어지는 괄호열 중에 올바른 괄호열을 다음과 같이 정의한다.
1. '()' '[]'는 올바른 괄호열이다.
2. 올바른 괄호열 x에 대해서 (x), [x]도 올바른 괄호열이다.
3. 올바른 괄호열 x, y에 대해서 xy도 올바른 괄호열이다.
이때 올바른 괄호열의 값(괄호값)을 다음과 같이 정의한다.
1. () = 2
2. [] = 3
3. (x) = 2 * 'x의 괄호값'
4. [x] = 3 * 'x의 괄호값'
5. xy = 'x의 괄호값' + 'y의 괄호값'
괄호열을 읽고 그 괄호값을 계산하여 출력한다.
Method :
스택을 이용하여 앞에서부터 읽어서 여는 괄호일 경우 스택에 저장한다.
계산을 위해서는 결국 () 또는 []와 같이 바로 직전에 열었던 괄호를 닫았을 경우 2, 3이라는 값이 된다.
이외의 경우에서는 괄호 내부의 괄호값을 2, 3배 하는 연산을 수행한다.
따라서 스택에 여는 괄호를 저장하고, 만약 스택의 top과 맞는 닫히는 괄호가 들어온 경우
()인 경우 2배, []인 경우 3배를 해 준다.
이때 tmp라는 값은 괄호 내부에 있는 괄호값에 곱해질 값을 의미한다.
([][])의 경우 ('3' + '3') = ('6') = 12 이런식으로 계산해도 되지만,
처음 '(' 인 경우 언젠간 닫히면 2를 곱해주므로,
2x[] + 2x[]로 표현 가능하다.
따라서 스택에 여는 괄호를 넣으면서 곱할 값을 업데이트하고, 내부에서 닫힐 경우 그 종류에 따라 곱할 값을 곱해준다.
이후 괄호가 닫힌 경우 tmp 에 2 또는 3이 곱해져 있던 것을 다시 나눠서 없애준다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

void solve1() {
  int ans=0, tmp=1;
  string s;
  cin >> s;
  stack<char> stk;
  char prv = 'x';
  for(auto c : s) {
    if(c == '(') {
      tmp *= 2;
      stk.push(c);
    } else if(c == '[') {
      tmp *= 3;
      stk.push(c);
    } else if(c == ')') {
      if(stk.empty() || stk.top() == '[') {
        cout << "0\n";
        return;
      } else if(prv == '(') {
        ans += tmp;
      }
      tmp /= 2;
      stk.pop();
    } else {
      if(stk.empty() || stk.top() == '(') {
        cout << "0\n";
        return;
      } else if(prv == '[') {
        ans += tmp;
      }
      tmp /= 3;
      stk.pop();
    }
    prv = c;
  }
  if(stk.empty()) cout << ans;
  else cout << "0\n";
  
  return;
}