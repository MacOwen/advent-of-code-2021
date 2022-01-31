#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Process each line, count number of segments in each output number
	int ans = 0;
	string s;
	while (cin >> s) {
		// Skip signal patterns
		for (int i=0;i<10;i++)
			cin >> s;
		for (int i=0;i<4;i++) {
			cin >> s;
			int l = s.length();
			// Segment count matches segment counts of 1,4,7,8
			if (l == 2 || l == 4 || l == 3 || l == 7)
				ans++;
		}
	}

	cout << "Result: " << ans << '\n';
}
