#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, m;
const auto nam = vector<string>{"zero", "one", "two",   "three", "four",
                                "five", "six", "seven", "eight", "nine"};
bool Comp(ll a, ll b) {
  auto va = vector<string>{};
  while (0 < a) {
    va.push_back(nam[a % 10]);
    a /= 10;
  }
  reverse(va.begin(), va.end());
  auto vb = vector<string>{};
  while (0 < b) {
    vb.push_back(nam[b % 10]);
    b /= 10;
  }
  reverse(vb.begin(), vb.end());

  return va < vb;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> m >> n;
  auto vals = vl{};
  vals.reserve(n - m + 1);
  for (auto i = m; i <= n; ++i) {
    vals.push_back(i);
  }

  sort(vals.begin(), vals.end(), Comp);
  auto c = 0;
  for (const auto& x : vals) {
    cout << x << ' ';
    ++c;
    if (10 == c) {
      cout << '\n';
      c = 0;
    }
  }

  return 0;
}