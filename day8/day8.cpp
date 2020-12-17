/**
 *    author: etohirse
 *    created: 16.12.2020 19:16:52
 **/
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::ifstream fin("input.in");
std::ofstream fout("input.out");
int fv[1000];

static std::pair<int, bool> run(
    const std::vector<std::pair<std::string, int>> &mp) {
  int acc(0);
  std::unordered_set<int> seen;
  auto pc(0u);
  while (pc < mp.size()) {
    if (!seen.insert(pc).second) {
      return std::make_pair(acc, false);
    }
    if (mp[pc].first == "acc") {
      acc += mp[pc].second;
      ++pc;
    } else if (mp[pc].first == "jmp") {
      pc += mp[pc].second;
    } else {
      ++pc;
    }
  }
  return std::make_pair(acc, true);
}

int main() {
  std::vector<std::pair<std::string, int>> mp;
  int a, count(0);
  std::string s;
  while (fin >> s >> a) {
    mp.push_back(make_pair(s, a));
    count++;
  }

  // part 1
  int acc(0);
  count = 0;
  while (count < 643) {
    fv[count]++;
    if (fv[count] > 1) {
      fout << acc << '\n';
      break;
    }
    std::string x = mp[count].first;
    int y = mp[count].second;

    if (x == "acc") {
      acc += y;
    } else if (x == "jmp")
      count = count + y - 1;
    count++;
  }

  // part 2
  std::unordered_map<std::string, std::string> fix{{"jmp", "nop"},
                                                   {"nop", "jmp"}};
  for (auto i = 0u; i < 643; ++i) {
    if (mp[i].first == "nop" || mp[i].first == "jmp") {
      mp[i].first = fix[mp[i].first];
      auto ans = run(mp);
      if (ans.second) {
        fout << ans.first << '\n';
        break;
      }
      mp[i].first = fix[mp[i].first];
    }
  }
  return 0;
}
