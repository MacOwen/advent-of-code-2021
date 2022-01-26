#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Process crab data
	vector<int> data;
	while (cin) {
		int fish;
		cin >> fish;
		data.push_back(fish);
		// Ignore next character (comma)
		getchar();
	}
	data.pop_back();

	sort(data.begin(),data.end());

	int target = data[data.size()/2]; // Target position for crabs to align on (median position)

	int ans = 0;
	for (int pos : data)
		ans += abs(target-pos);

	cout << "Result: " << ans << '\n';
}
