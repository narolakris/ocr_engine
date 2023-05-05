// Author: Harsh Bardolia

#include<bits/stdc++.h>
using namespace std;

#define endl        "\n"
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void solve() {
	int a, b, d;
	cin >> a >> b >> d;

	if (d > a + b || (d % __gcd(a, b) != 0)) {
		cout << "cannot" << endl;
		return;
	}

	if (a < b) swap(a, b);

	int x = 0, y = 0;

	while (x + y != d) {
		cout << x << " " << y << endl;

		if (x == 0) {
			x = a;
			continue;
		}

		if (y != b) {
			int cap = min(x, b - y);
			x -= cap;
			y += cap;
			continue;
		}

		if (y == b) {
			y = 0;
			continue;
		}
	}

	cout << x << " " << y << endl;
}

int main() {
#ifdef Harsh
	freopen("Error.txt", "w", stderr);
#endif
	fast;
	ll t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}