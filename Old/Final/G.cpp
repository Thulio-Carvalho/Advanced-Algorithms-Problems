#include <bits/stdc++.h>

using namespace std;

int N, H;

int main() {

  scanf("%d %d", &N, &H);
  double constant = H / sqrt(N);
  for (int i = 0; i < N - 1; i++) {
    if (i == N - 2) {
      printf("%.12f", constant * sqrt(i + 1));  
    } else {
    printf("%.12f ", constant * sqrt(i + 1));
    }
  } printf("\n");

  return 0;
}