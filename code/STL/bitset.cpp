int main() {
	bitset<10> B1;         // B1 = "0000000000"
	bitset<10> B2(13);     // B2 = "0000001101"
	bitset<10> B3("1011"); // B3 = "0000001011"
	cout << B1 << '\n' << B2 << '\n' << B3 << '\n';

    bitset<5> B4("01011");
	bitset<5> B5("00111");
	cout << (B4 & B5) << '\n'; // 00011
	cout << (B4 | B5) << '\n'; // 01111
	cout << (B4 ^ B5) << '\n'; // 01100
	cout << (B4 << 2) << '\n'; // 01100
	cout << (B4 >> 2) << '\n'; // 00010
	cout << ~B4 << '\n';       // 10100

    bitset<100> B;
	B.set(); cout << B.count() << '\n'; // 100
	B.reset(); cout << B.count() << '\n'; // 0
	cout << B.size() << '\n' << '\n'; // 100

	B[2] = 1; // B = "...100"
	cout << B.count() << '\n'; // 1
	cout << B.any() << '\n'; // 1
	cout << B.all() << '\n'; // 0
	cout << B.none() << '\n' << '\n'; // 0

	B[2].flip(); // B = "...000"
	cout << B.count() << '\n'; // 0
	cout << B.any() << '\n'; // 0
	cout << B.all() << '\n'; // 0
	cout << B.none() << '\n' << '\n'; // 1

	B[1] = B[3] = B[4] = 1;
	string s = B.to_string();
	cout << s << '\n'; // ...11010
}