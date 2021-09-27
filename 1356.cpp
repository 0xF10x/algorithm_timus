#include <iostream>

using namespace std;

bool prime(int a);

int main() {
	int T, a,b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a;
			if (prime(a)) cout << a << "\n";
			else {
				if (a % 2 != 0) {
					b = a - 2;
					if (prime(b)) cout << 2 << " " << b <<"\n";
					else {
						b -= 2;
						while (!prime(b)) {
							b -= 2;
						}
						cout << b << " ";
						a -= b;
						if (a == 4) { 
							cout << 2 << " " << 2 << "\n"; 
							continue;
						}
						b = a - 3;
						while (!(prime(b) && prime(a - b))) {
							b -= 2;
						}
						cout << b << " " << a - b <<"\n";

					}
				}
				else {
					b = a - 3;
					while (!(prime(b) && prime(a - b))) {
						b -= 2;
					}
					cout << b << " " << a - b << "\n";
				}
			}
		
	}
		
}

bool prime(int a) {
	int f = 0;
	for (int j = 2; j*j <= a; j++) {
		if (a % j == 0) return(false);
	}
	return(true);
}