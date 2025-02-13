#include <bits/stdc++.h>
using namespace std;

vector<int> Seive(int limit) {
	if (limit < 2) return {};
	vector<bool> primes(limit + 1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i * i <= limit; ++i) {
		if (primes[i]) {
			for (int j = i * i; j <= limit; j += i) {
				primes[j] = false;
			}
		}
	}

	vector<int> result;
	for (int i = 2; i <= limit; ++i) {
		if (primes[i]) result.push_back(i);
	}
	return result;
}

vector<int> primefactor(int n) {
	vector<int> spf(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		spf[i] = i;
	}
	for (int i = 2; i * i <= n; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	vector<int> answer;
	while (n != 1) {
		answer.push_back(spf[n]);
		n = n / spf[n];
	}
	return answer;
}

set<int> uniqeprimefactor(int n) {
	vector<int> fac = primefactor(n);
	set<int> answer;
	for (auto& i : fac) {
		answer.insert(i);
	}
	return answer;
}
map<int, int> primepower(int n) {
	vector<int> vi = primefactor(n);
	map<int, int> mp;
	for (auto& i : vi) {
		mp[i]++;
	}
	return mp;
}

int main() {
	int n;
	cin >> n;
	map<int, int> mp = primepower(n);
	for (const auto& element : mp) {
		int f = element.first;
		int s = element.second;
		cout << f << " " << s << endl;
	}
	return 0;
}
