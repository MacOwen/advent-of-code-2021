#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	string instruction_name;
	int instruction_value;

	int pos_horiz = 0;
	int pos_vert = 0;
	int aim = 0;
	while (cin >> instruction_name >> instruction_value) {
		if (instruction_name == "forward") {
			pos_horiz += instruction_value;
			pos_vert += aim * instruction_value;
		}
		else if (instruction_name == "down") {
			aim += instruction_value;
		}
		else if (instruction_name == "up") {
			aim -= instruction_value;
		}
	}
	
	int pos_product = pos_horiz * pos_vert;
	cout << "Result: " << pos_product << '\n';
}
