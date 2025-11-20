int main() {
	fastio;
	map<string, int> M;
	M["abc"] = 3; // == M.insert({ "abc", 3 })
	cout << M["abc"] << '\n'; // 3
	M["abc"] = 4;
	cout << M["abc"] << '\n'; // 4

	auto it = M.erase("abc"); // M = { }, it == M.end()
	M["hi"] = 123; // M = { { "hi", 123 } }
	auto cnt = M.erase("hi"); // M = { }, cnt == 1

	cout << "M.size() : " << M.size() << '\n'; // 0
	cout << "M.empty() : " << M.empty() << '\n'; // 1
	M.clear();

	vector<string> s{ "ab", "cde", "fghi" };
	vector<int> v{ 3, 1, 4 };
	for (int i = 0; i < 3; i++) M[s[i]] = v[i];
	for (auto& [a, b] : M) cout << '(' << a << ',' << b << ')' << ' '; cout << '\n'; // (ab,3) (cde,1) (fghi,4)

	if (M.count("abc")) cout << "found abc" << '\n'; // x
	if (M.count("cde")) cout << "found cde" << '\n'; // o
}