#include <iostream>
#include <algorithm>

using namespace std;

string hexValues[] = {"#e0def4", "#286983", "#9ccfd8", "#ebbcba", "#eb6f92",
    "#907aa9", "#b4637a", "#393552", "#6e6a86", "#9893a5",
    "#56949f", "#ea9a97", "#d7827e", "#c4a7e7", "#f6c177",
    "#191724"
	};

void rgbtotos(string hexValue, size_t lineNumber) {
	string format = "0x";
	if (!hexValue.empty() && hexValue[0] == '#') {
		hexValue.erase(0, 1);
		string result;
		for (size_t i = 0; i < hexValue.size(); i += 2) {
			string pair = hexValue.substr(i ,2);
			transform(pair.begin(), pair.end(), pair.begin(), ::toupper);
			result += pair + pair;
		};
		format += result;
		cout << lineNumber << ": " << "Hex -> "<< hexValue << "; TOS format -> " << format << endl;
	} else {
		cout << "The value is not a hex value." << endl;
	}
}

int main() {
	size_t lineNumber = 1;
	for (const string& hexValue : hexValues) {
		rgbtotos(hexValue, lineNumber);
		lineNumber++;
	}
	return 0;
}
