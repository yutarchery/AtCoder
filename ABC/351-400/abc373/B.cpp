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

char s[26];
int loc[26], ans = 0;

int main() {
  for (int i = 0; i < 26; i++) {
    cin >> s[i];
    loc[s[i] - 'A'] = i;
  }
  for (int i = 0; i + 1 < 26; i++) {
    ans += abs(loc[i + 1] - loc[i]);
  }
  cout << ans << endl;

  return 0;
}
