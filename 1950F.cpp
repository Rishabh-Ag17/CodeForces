#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;


#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int t;


int main() {
		ios::sync_with_stdio(false);
		
		cin >> t;

		while (t--) {
				int a, b, c;
				cin >> a >> b >> c;

				if (c != a + 1) {
						cout << "-1\n";
						continue;
				}

				int h = 0;

				while (a >= (1 << h)) {
						a -= (1 << h);
						h++;
				}

				if (!a && !b) {
						cout << h << '\n';
						continue;
				}

				if (a + b >= (1 << h)) {
						b -= (1 << h) - a;
						h++;
				}
				else {
						cout << h + 1 << '\n';
						continue;
				}

				int k = (b + c - 1) / c;
				cout << h + k << '\n';

		}
}
