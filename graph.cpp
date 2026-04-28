#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> v(n);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x > n || y > n) continue;
		else v[x].push_back(y);
	}
	for (int i = 0; i < n; i++){
		cout << i << " - " << v[i].size() << endl;
	}
}
