#include <iostream>
#include <string>

using namespace std;

bool check(const string& w) {
	return equal(w.begin(), w.end(), w.rbegin());
}
void resforpal(string word, int k);
int main() {
	int k, i, j, t, max;
	string word, ans;
	ans = "";
	cin >> word;
	k = word.length();
	if (k == 1) cout << word[0] << word[0] << "\n";
	else {
		if (check(word)) resforpal(word, k);
		else {
			i = 0;
			t = 0;
			max = INT32_MIN;
			for (int i = 0; i < k; ++i) {
				i = i - t;
				j = k - 1;
				t = 0;
				while (word[j] == word[i]) {
					i++;
					j--;
					t++;
					if (t > max) max = t;
					if (i != k) max = 0;
				}
			}
			for (int i = k - max - 1; i >= 0; i--) {
				ans += word[i];
			}
			cout << word + ans;
		}
	}


}
void resforpal(string word, int k) {
	int b, x, y;
	b = (k - 1) * 2;
	for (int i = k; i <= b; i++) {
		x = i / 2;
		y = (i + 1) / 2;
		while (word[x] == word[y] && x < k) {
			x--;
			y++;
		}
		if (y == k) {
			for (int j = 0; j <= i / 2; j++) {
				cout << word[j];
			}
			for (int j = (i - 1) / 2; j >= 0; j--) {
				cout << word[j];
			}
			break;
		}
	}
}