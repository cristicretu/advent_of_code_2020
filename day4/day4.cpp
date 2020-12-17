/**
 *    author: etohirse
 *    created: 15.12.2020 17:45:47
 **/
#include <fstream>
#include <vector>

std::ifstream fin("input.in");
std::ofstream fout("input.out");

std::vector<std::string> s;

int main() {
  int i(0), atentie(0);
  std::string a;
  while (true) {
    getline(fin, a);
    if (a.size() == 0) {
      atentie++;
      i++;
    } else {
      atentie = 0;
      s[i] += a;
    }
    if (atentie == 2) break;
  }

  for (int i = 0; i < 1000; ++i, fout << '\n') fout << s[i];

  return 0;
}
