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

int n, a[int(2e5 + 5)];

int dp[int(2e5 + 5)], last[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i + 1]) {
      dp[i + 1] = min(dp[i - 1] + 2, i + 1 - last[a[i]]);
    }
    last[a[i]] = i;
    ans = max(ans, dp[i + 1]);
  }
  cout << ans << endl;

  return 0;
}
