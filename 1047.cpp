#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
double sum(int n, vector<double> c);
int main() {
	int n;
	double k, azero, an, a1;
	cin >> n >> azero >> an;
	vector<double> c;
	int i = n;
	for (; i; --i) {
		cin >> k;
		c.push_back(k);
	}
	a1 = (an + n * azero - sum(n, c)) / (n + 1);
	printf("%.2f\n", a1);
	return 0;
}
double sum(int n, vector<double> c) {
	double summ = 0;
	for (int i = 0; i < n; i++) {
		summ += 2 * c[i] * (1 + (n - (i + 1)));
	}
	return summ;
}