/*
Time : 2022.03.29
Problem : BOJ5052 (https://www.acmicpc.net/problem/5052)
Algorithm Type : 문자열, Trie(자료구조)
Outline :
전화번호 목록이 주어졌을 때, 이 목록이 일관성이 있는지 없는지 출력한다.
일관성을 유지한다는 것은 한 번호가 다른 번호의 접두어인 경우가 없다는 것을 의미한다.
예를 들어 911(긴급 전화), 91 12 54 26(선영) 과 같은 전화번호가 있다면
선영에게 전화하기 위해 911을 입력하는 순간 긴급 전화가 걸리게 된다.
Method :

Example :
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
-------
NO
YES
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

class Trie {
  private:
    int toInteger(char c) {
      return c - '0';
    }

  public:
    bool isTerminal;
    Trie* children[10];

    Trie() {
      this->isTerminal = false;
      for (int i=0; i<10; i++) {
        this->children[i] = NULL;
      }
    }

    bool insert(string phoneNo) {
      bool isConsist = true;
      bool flag = false;
      Trie* cursor = this;
      for (char &c : phoneNo) {
        if (!cursor->children[toInteger(c)]) {
          cursor->children[toInteger(c)] = new Trie();
          flag = true;
        } else if (cursor->children[toInteger(c)]->isTerminal) {
          isConsist = false;
        }
        cursor = cursor->children[toInteger(c)];
      }
      cursor->isTerminal = true;
      return isConsist && flag;
    }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  int tc;
  cin >> tc;
  while (tc--) {
    Trie trie;
    bool result = true;
    int n;
    cin >> n;
    while(n--) {
      string phoneNo;
      cin >> phoneNo;
      result = result && trie.insert(phoneNo);
    }
    if (result) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
