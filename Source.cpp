#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int searchWord(string inputLine, int start) {
	int endOfWord=0;
	int FEnd;
	int width = inputLine.length();
	for (int k = start; k < width; k++) {
		if (inputLine[k] == ' ') {
			endOfWord = k - 1;
			break;
		}
		FEnd = k+1;
	}
	if (FEnd == width) { endOfWord = FEnd-1; }
	return endOfWord;
}
int getWord(int start,int end, string Line) {
	int word = 0;
	for (int a = start; a <= end; a++) {
		int o = end - a;
		word += (Line[a]%48) * pow(10, o);
	}
	return word;
}
int wait(string input, int start) {
	int endLine = input.length();
	int end = start;
	while (input[end] == ' ') {
		if (input[end] == ' ') { end++; }
	}
	return end;
}
int sumOfString(string str) {
	int length = str.length();
	int sum = 0;
	int start = 0;
	int last;
	while (start < length) {
		start = wait(str, start);
		last = searchWord(str, start);
		sum += getWord(start, last, str);
		start = last;
		start++;
	}
	return sum;
}

int main() {
	string str;
	cout << "Enter your sentence: "; getline(cin, str);
	int sum = sumOfString(str);
	cout <<"your sum: "<< sum <<"\n";
	system("pause");
	return 0;
}
