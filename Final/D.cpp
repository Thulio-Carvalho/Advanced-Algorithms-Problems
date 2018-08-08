#include <bits/stdc++.h>
#define MAXN 300021

using namespace std;
typedef long long ll;

int N;
ll arr[MAXN];
ll A, B, C;
map<ll, ll> freq;

void computeMinValues() {
  ll sorted[N];

  copy(arr, arr + N, sorted);
  sort(sorted, sorted + N);

  A = sorted[0];
  B = sorted[1];
  C = sorted[2];
}

ll solve() {

  if (A != B && B != C)
    return freq[C];

  else if (A == B && B != C)
    return freq[C];

  else if (A != B && B == C) {
    ll total = 0;
    for (ll i = 1; i < freq[B]; i++) { total += i; }
    return total;
  }
  
  // 1 1 1 1 

  else if (A == B && B == C) { 
    ll F = freq[A];
    ll total = 1;   
    ll secondChoice =  F - 2;
    for (ll i = F; i > 3; i--) {
      total += (secondChoice * (secondChoice + 1)) / 2;
      secondChoice--;
    } 

    return total;
  }

  return 0;
}
int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
    freq[arr[i]]++;
  }

  computeMinValues();

  ll ans = solve();

  printf("%lld\n", ans);

  return 0;
}
