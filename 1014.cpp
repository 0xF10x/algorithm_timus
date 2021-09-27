#include <iostream>

using namespace std;


int del(int n);

int main() {
	int n;
	int j = 0;
	cin >> n;
	int* ar = new int[n];
	if (n == 0) {
		cout << 10;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	while (n > 1) {

		if (del(n) == 1) {
			cout << -1;
			return 0;
		}
		ar[j] = del(n);
		n /= ar[j];
		j++;
	}
	

	for (int i = 0; i < j - 1; ++i) 
	{
		for (int k = 0; k < j - 1; ++k)
		{
			if (ar[k + 1] < ar[k])
			{
				swap(ar[k], ar[k+1]);
			}
		}
	}
	for (int i = 0; i < j; i++) {
		cout << ar[i];
	}
	
	
}


int del(int n) {
	int t = 1;
	for (int i = 9; i >= 2; i--) {
		if (n % i == 0) {
			t = i;
			return t;
		}
	}
return t;
}