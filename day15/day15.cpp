/**
 *    author: etohirse
 *    created: 23.12.2020 20:06:44
 **/
#include <fstream>
#include <iostream>
#include <unordered_map>

typedef long long ll;

std::ifstream fin("input.in");

int main() {
  std::string s;
  std::unordered_map<ll, ll> fv;
  ll i(0), count(0);
  while (getline(fin, s, ',')) {
    if (count) fv[i] = count;
    i = stoll(s);
    ++count;
  }
  for (; count < 30000000; ++count) {
    auto [it, is_new] = fv.emplace(i, count);
    if (is_new) {
      i = 0;
    } else {
      i = count - it->second;
      it->second = count;
    }
    }
  std::cout << i;
  return 0;
}
