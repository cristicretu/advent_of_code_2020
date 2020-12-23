/**
 *    author: etohirse
 *    created: 21.12.2020 08:29:25
 **/
#include <fstream>
#include <vector>

typedef long long ll;

std::ifstream fin("input.in");
std::ofstream fout("input.out");

std::vector<int> av;

int main() {
  ll depart;
  std::string s;
  fin >> depart >> s;
  std::string curr = "";
  int i(0);
  while (s[i] != NULL) {
    while (isdigit(s[i])) curr += s[i], i++;
    if (curr.size()) av.push_back(stoi(curr));
    curr = "";
    i++;
  }
  for (int i =) return 0;
}
