#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, e;
  vector<int> v;
  cin >> n;
  
  while (n--) {
    cin >> e;
    v.push_back(e);
  }

  int sum = 0;
  int best = 0;

  for (int x : v) {
    sum = max(x, x + sum);
    best = max(sum, best);
  }
  cout << best << endl;
}
