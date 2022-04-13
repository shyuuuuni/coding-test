/*
Time : 2022.04.13
Problem : BOJ14725 (https://www.acmicpc.net/problem/14725)
Algorithm Type : Trie, 재귀
Outline :
입력으로 로봇 개미가 개미굴을 탐색하며 각 층마다 먹이 이름을 가져온다.
로봇 개미는 더이상 내려갈 수 없다면 신호를 더이상 보내지 않는다.
보내온 신호를 바탕으로 개미굴의 구조를 출력하려고 한다. 한 층이 깊어질수록 먹이 이름 앞에 "--"가 하나씩 더 붙는다.
또한 각 층마다 같은 층에 여러개의 먹이가 있다면 사전순으로 출력한다.
Method :
Trie 자료구조를 약간 변형하여 해결하였다.
Trie 자료구조의 속성으로 map<string,Trie*> 형의 children 속성을 갖는다.
children은 현재 개미굴 층과 이어진 다음 층의 먹이 이름이 string인 Trie의 포인터를 쌍으로 저장한다.
예를 들어 APPLE -> BANANA -> KIWI 순으로 개미굴이 존재한다면, APPLE의 children에는
children[BANANA] == &Banana-Trie 로 하나가 저장되어있고, 그 연결된 Trie(BANANA)의 children은 마찬가지로
children[KIWI] == &Kiwi-Trie 로 저장되어 있는 식이다.
입력이 위와 같이 위 층에서부터 하나씩 들어오므로, insert함수를 구현할 때 기존 트라이가 맨 위에서부터 내려오던것과 달리
insert(s)를 사용하면 해당 층 바로 아래에 s라는 먹이 이름을 갖는 개미굴을 연결하도록 구현하고,
입력을 받을 때 포인터를 옮겨가면서 층을 입력마다 한 층씩 내려가도록 구현하였다.
마지막으로 트라이를 출력 형식에 맞춰서 출력하면 되는데, printTrie(tab) 이라는 함수를 재귀적으로 호출하여 출력하였다.
tab은 정수형 인자로, tab값 하나당 "--"를 하나씩 앞에 출력하도록 설정되어 있고,
map을 iterator를 이용하여 출력하고 -> 그 iterator의 children에 대해서도 처리하기 위해 printTrie()를 재귀적으로 호출한다.
이때 더 하위 children을 탐색하기 위해서는 tab값을 1 증가시켜야 한다.
Example :
4
2 KIWI BANANA
2 KIWI APPLE
2 APPLE APPLE
3 APPLE BANANA KIWI
-------
APPLE
--APPLE
--BANANA
----KIWI
KIWI
--APPLE
--BANANA
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
    void printtab(short tab) {
      while(tab--) {
        cout << "--";
      }
    }
  
  public:
    map<string,Trie*> children;

    Trie() {
    }

    Trie* insert(string s) {
      Trie* cursor = this;

      if (cursor->children.find(s) == cursor->children.end()) {
        cursor->children[s] = new Trie();
      }

      return cursor->children[s];
    }

    void printTrie(short tab) {
      Trie* cursor = this;

      for (auto iter=cursor->children.begin(); iter!=cursor->children.end(); iter++) {
        printtab(tab);
        cout << iter->first << "\n";
        iter->second->printTrie(tab+1);
      }

      return;
    }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO
  
  short n;
  Trie trie;

  cin >> n;
  while (n--) {
    short k;
    Trie* cursor = &trie;

    cin >> k;
    while(k--) {
      string s;

      cin >> s;
      cursor = cursor->insert(s);
    }
  }

  trie.printTrie(0);

  return 0;
}
