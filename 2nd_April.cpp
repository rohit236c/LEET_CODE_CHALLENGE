#include<bits/stdc++.h>
using namespace std;

int sumOfAllDigits(int n) {
	if (n >= 0 && n <= 9) return n * n;
	int sum = 0;
	int digit = n % 10;
	sum += digit * digit + sumOfAllDigits(n / 10);

	return sum;
}
bool isHappy(int n) {


	int curNum = n;
	set<int>s;
	s.insert(n);
	while (curNum > 3) {
		n = curNum;
		int sum = sumOfAllDigits(n);
		curNum = sum;
		if (s.find(curNum) != s.end()) return false;
		s.insert(curNum);
	}

	return (curNum * curNum) == 1 ? true : false;

}
void leet() {
	cout << isHappy(2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	leet();

	return 0;
}