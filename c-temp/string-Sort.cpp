#include <bits/stdc++.h>
using namespace std;

string S;
int K;

int main() {
  cin >> S >> K;
  vector<string> vec;
  for (int i = 0; i < S.size(); ++i) {
    for (int j = 1; j <= K; ++j) {
      string tmp = S.substr(i, j);
      vec.push_back(tmp);
    }
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  cout << vec[K-1] << endl;
}