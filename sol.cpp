#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	// count the frequnecy of the characters: {A, G, C, T, ?}
	int m = 5;
	vector<int> counter(m, 0);
	for (int i = 0; i < n; i++) {
		counter[0] += (s[i] == 'A');
		counter[1] += (s[i] == 'G');
		counter[2] += (s[i] == 'C');
		counter[3] += (s[i] == 'T');
		counter[4] += (s[i] == '?');
	}
	// find the highest frequency among the characters
	int mx = INT_MIN;
	for (int i = 0; i < m - 1; i++) {
		mx = max(mx, counter[i]);
	}
	// find the difference between the frequencies of all the characters and highest frequency
	int sum = 0;
	vector<int> diff(m - 1, 0);
	for (int i = 0; i < m - 1; i++) {
		int d = mx - counter[i];
		diff[i] = d;
		sum += d;
	}
	// if the sum of all the differences is greater than or equal to the no. of
	// questions marks present, then the answer does not exist
	if (sum > counter.back()) {
		cout << "===" << '\n';
		return 0;
	}
	// otherwise, replace the question marks with the needed characters (varying amount) 
	int id = 0;
	vector<char> letters = {'A', 'G', 'C', 'T'};
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			while (diff[id] == 0 && id < m - 1) {
				id++;
			}
			if (id < m - 1) {
				s[i] = letters[id];
				diff[id]--;
			}
		}
	}
	// count the remaining occurrences of the question mark
	counter[m - 1] = 0;
	for (int i = 0; i < n; i++) {
		counter[m - 1] += (s[i] == '?');
	}
	// check if the remaining question marks can be divided by 4 (A, G, C, T)
	if (counter[m - 1] % 4 != 0) {
		cout << "===" << '\n';
		return 0;
	}
	// divide the frequency of question mark among the letters
	diff.clear();
	for (int i = 0; i < m - 1; i++) {
		diff[i] = counter[m - 1] / 4;
	}
	// repeat the process of replacing the question marks with the needed letters (equal amount)
	id = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			while (diff[id] == 0 && id < m - 1) {
				id++;
			}
			if (id < m - 1) {
				s[i] = letters[id];
				diff[id]--;
			}
		}
	}
	cout << s << '\n';
	return 0;
}
