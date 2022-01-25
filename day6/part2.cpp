#include <iostream>
#include <vector>
using namespace std;
#define ll int64_t

int main() {
	freopen("input.txt","r",stdin);

	// Process fish data
	vector<int> data;
	while (cin) {
		int fish;
		cin >> fish;
		data.push_back(fish);
		// Ignore next character (comma)
		getchar();
	}
	data.pop_back();

	// Store fish in array according to which day they replicate
	vector<ll> fish(7); // Maps day to number of fish replicating
	vector<ll> new_fish(7); // Maps day to number of new fish produced

	ll ans = data.size(); // Total number of fish

	// Initialize fish array
	for (int i : data)
		++fish[i];

	// Calculate offspring
	for (int i=0;i<256;i++) {
		int day = i%7;
		int next_day = (i+2)%7; // Day of the week when new fish will replicate
		ans += fish[day];
		new_fish[next_day] = fish[day];
		fish[day] += new_fish[day];
	}

	cout << "Result: " << ans << '\n';
}
