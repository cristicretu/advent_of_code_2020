/**
 *    author: etohirse
 *    created: 16.12.2020 13:24:02
 **/
#include <algorithm>
#include <fstream>
#include <vector>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

int getNr(std::string s) {
  std::string alt = "";
  for (unsigned i = 0; i < s.size(); ++i) {
    if (s[i] == 'F')
      alt += '0';
    else if (s[i] == 'B')
      alt += '1';

    if (s[i] == 'R')
      alt += '1';
    else if (s[i] == 'L')
      alt += '0';
  }

  int dec_value = 0, base = 1;
  for (int i = alt.size() - 1; i >= 0; i--) {
    if (alt[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}

std::vector<int> av;

int main() {
  std::string s;
  int ans(0);
  while (fin >> s) {
    ans = std::max(ans, getNr(s));
    av.push_back(getNr(s));
  }
  fout << ans << '\n';

  std::sort(av.begin(), av.end());
  int last = -1;
  for (auto i : av) {
    if (last != -1 and i - last == 2) fout << i - 1;
    last = i;
  }
  return 0;
}
