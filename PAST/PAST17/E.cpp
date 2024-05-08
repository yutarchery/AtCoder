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

string s;
vector<pair<char, int>> ans;

int main() {
  cin >> s;
  char now = s[0];
  int cnt = 1;

  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      ans.push_back({now, cnt});
      now = s[i];
      cnt = 1;
    }
  }
  ans.push_back({now, cnt});

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second;
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
