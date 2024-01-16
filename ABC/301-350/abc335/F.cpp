#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll a[int(2e5 + 5)];

ll ans[int(2e5 + 5)], dp[1005][1005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int b = sqrt(n);

  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= b; j++) {
      ans[i] += dp[j][i % j];
      ans[i] %= MOD2;
    }

    if (a[i] <= b) {
      dp[a[i]][i % a[i]] += ans[i];
      dp[a[i]][i % a[i]] %= MOD2;
    } else {
      for (int j = 1; i + a[i] * j <= n; j++) {
        ans[i + a[i] * j] += ans[i];
        ans[i + a[i] * j] %= MOD2;
      }
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += ans[i];
    sum %= MOD2;
  }
  cout << sum << endl;

  return 0;
}
