#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Cmp {
	bool operator() (const T& a, const T& b) const {
		if (abs(a) != abs(b)) return abs(a) < abs(b);
		return a > b;
	}
};

int main() {
	set<int, greater<int>> S1 = { 1, 2, 3, 4 }; // descending order
	for (auto& i : S1) cout << i << ' '; cout << '\n'; // 4 3 2 1

	set<int, Cmp<int>> S2 = { 3, -1, -4, 1, 5, 1 }; // custom compare function
	for (auto& i : S2) cout << i << ' '; cout << '\n'; // 1, -1, 3, -4, 5
}

int main() {
	set<int> S = { 1, 2 }; // initializer_list
	auto [it1, flag1] = S.insert(2); // S = { 1, 2 }, *it1 == 2, flag1 == 0
	auto [it2, flag2] = S.insert(3); // S = { 1, 2, 3 }, *it2 == 3, flag2 == 1
	it1 = S.erase(it1); // S = { 1, 3 }, *it1 == 3
	auto cnt = S.erase(3); // S = { 1 }, cnt == 1

	cout << "S.size() : " << S.size() << '\n'; // 1
	cout << "S.empty() : " << S.empty() << '\n'; // 0
	S.clear();

	for (auto& i : { 3, 1, 4, 1, 5 }) S.insert(i); // S = { 1, 3, 4, 5 }
	for (auto& i : S) cout << i << ' '; cout << '\n'; // 1 3 4 5

	if (S.count(2)) cout << "found 2" << '\n'; // x
	if (S.count(3)) cout << "found 3" << '\n'; // o

	auto lo = S.lower_bound(3); // *lo == 3, *prev(lo) < 3 <= *lo
	auto hi = S.upper_bound(3); // *lo == 4, *prev(lo) <= 3 < *lo
}