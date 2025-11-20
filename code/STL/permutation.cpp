#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v{ 1, 2, 3, 4 };
	do {
		for (auto& i : v) cout << i << ' '; cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

    string s = "dcba";
	do cout << s << '\n';
	while (prev_permutation(s.begin(), s.end()));
}