#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// sregex_iterator 사용법
int main() {
	fastio;
    regex r(R"((^\w+)://([^:/]+)(:\d+)?(/.+$)?)");
	int n; cin >> n;
	for (int cnt = 1; cnt <= n; cnt++) {
		string s, ans[4]; cin >> s;
		auto it = *sregex_iterator(s.begin(), s.end(), r);
		for (int i = 0; i < 4; i++) {
			ans[i] = it[i + 1];
			if (ans[i].empty()) ans[i] = "<default>";
		}
		if (ans[2][0] == ':') ans[2] = ans[2].substr(1);
		if (ans[3][0] == '/') ans[3] = ans[3].substr(1);
		cout << "URL #" << cnt << '\n';
		cout << "Protocol = " << ans[0] << '\n';
		cout << "Host     = " << ans[1] << '\n';
		cout << "Port     = " << ans[2] << '\n';
		cout << "Path     = " << ans[3] << '\n' << '\n';
	}
}

//regex_match 사용법
int main() {
	fastio;
	int N; cin >> N;
	regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
	while (N--) {
		string s; cin >> s;
		regex_match(s, r) ? cout << "Infected!\n" : cout << "Good\n";
	}
}
// regex_match: 주어진 문자열이 정규표현식 패턴을 만족하면 true를 반환
// s = regex_replace(s, r, t): 바꿀 문자열 s, 적용할 정규표현식 r, 치환할 패턴 t