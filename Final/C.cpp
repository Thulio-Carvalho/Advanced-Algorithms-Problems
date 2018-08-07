#include <bits/stdc++.h>
#define MAXN 30010

using namespace std;

typedef long long ll;

int T, N;
string original[MAXN], actual[MAXN];
int BIT[MAXN];
map <string, int> numbers;
int seq[MAXN];


void read();
void debug();

void update(int index, int val) {
  while (index <= MAXN) {
    BIT[index] += val;
    index += (index & -index);
  }
}

ll query(int index) {
  ll total = 0;
  while (index > 0) {
    total += BIT[index];
    index -= (index & -index);
  }
  return total;
}

ll query(int l, int r) {
  return query(r) - query(l-1);
}

int main() {
  scanf("%d", &T);

  while (T--) {
    memset(BIT, 0, sizeof BIT);
    read();
    ll answer = 0;

    for (int i = 0; i < N; i++){
      // cout << seq[i] << " ";

      update(seq[i], 1);
      // debug();
      answer += query(seq[i]+1, MAXN);
    } 
    // cout << endl ;

    cout << answer << endl;

    // debug();
  }
  return 0;
}

void read() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    cin >> actual[i];
    numbers[actual[i]] = i + 1;
  }
  for (int i = 0; i < N; i++) {
    cin >> original[i];
    seq[i] = numbers[original[i]];
  }
}

void debug() {
  for (int i = 0; i < 20; i++) {
    cout << BIT[i] << " ";
  } cout << endl;
}