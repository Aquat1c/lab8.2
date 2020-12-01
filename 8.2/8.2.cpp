
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int FindindexFirst(string& s) {
	int indexFirst = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			indexFirst = i;
			break;
		}
	}
	return indexFirst;
}

int FindindexLast(string& s) {
	int indexLast = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			indexLast = i;
		}
	}
	return indexLast;
}

bool FindToDo(string& s) {
	int k = 0;
	bool answer;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '(' || s[i] == ')') {
			k++;
		}

	if (k > 2) {
		answer = false;
	}
	else
		answer = true;

	return answer;
}

void Delete(string& s) {
	size_t pos = 0;

	string first = "(";
	string last = ")";

	int indexFirst = FindindexFirst(s);
	int indexLast = FindindexLast(s);
	int k = 0;

	bool answer = FindToDo(s);

	if (answer == false) {
		cout << "Error." << endl;
	}
	else {
		int length = indexLast - indexFirst + 1;
		pos = indexFirst;
		s = s.erase(pos, length);
		cout << "Modified string: " << s << endl;
	}
}

int main()
{
	string s;

	cout << "Enter the string: ";
	getline(cin, s);

	Delete(s);

	return 0;
}