#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;
  int checking_index = 0;
  for (size_t i = 0; i <= s2.size(); i++) {
    size_t found = s1.find(s2.substr(0, i), checking_index);

    if (found != string::npos) {
      result.push_back(found);
      checking_index = found;
    } else {
      result.push_back(-1);
      break;
    }
  }
  return result;
}