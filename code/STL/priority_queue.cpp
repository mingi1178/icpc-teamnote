#include <queue>
using namespace std;
// 최대 힙 우선순위 큐
priority_queue<int, vector<int>> q1;
priority_queue<int, vector<int>, less<int>> q2;
// 최소 힙 우선순위 큐
priority_queue<int, vector<int>, greater<int>> q;
// 멤버 함수: push, pop, top, size, empty

// priority_queue의 정렬 기준을 지정하는 여러 가지 방법
struct Info {
	int val;
	bool operator< (const Info& i) const {
		return val > i.val; // val이 가장 작은게 최댓값
	}
};
priority_queue<Info> PQ;

struct Cmp {
	bool operator() (const int& a, const int& b) const {
		return a > b; // 가장 작은게 최댓값
	}
};
priority_queue<int, vector<int>, Cmp> PQ;

auto Cmp = [](const int& a, const int& b) { return a > b; }; // 가장 작은게 최댓값
priority_queue<int, vector<int>, decltype(Cmp)> PQ(Cmp);

bool Cmp(const int& a, const int& b) {
	return a > b; // 가장 작은게 최댓값
}
priority_queue<int, vector<int>, decltype(&Cmp)> PQ(Cmp);