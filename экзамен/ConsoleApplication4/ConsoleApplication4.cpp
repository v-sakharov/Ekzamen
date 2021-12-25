#include <iostream>

int getLength(char buff[]) {
	int length = 0;
	for (;; length++) {
		if (buff[length] == '\0') break;
	}
	return length;
}

char* del(char bigStr[], int Start, int Len) {
	char result[512];

	int lenOfBigStr = getLength(bigStr);

	int start = Start;
	int len = Len;
	if (start < 0) start = 0;
	if (len <= 0) return bigStr;
	if (start > lenOfBigStr) return bigStr;
	if (len + start > lenOfBigStr) len = lenOfBigStr - start;

	int pos = 0;

	for (int i = 0; i < lenOfBigStr; i++) {
		if (i < start || i > start + len - 1)
			result[pos++] = bigStr[i];
		else
			i = start + len - 1;
	}
	result[pos] = '\0';

	return result;
}

int main() {
	char text[256];
	std::cin >> text;
	char bad[] = "-(){}[]";

	int i = 0;
	int j = 0;
	char* res = text;
	int len = getLength(text);
	while (i < len) {
		j = 0;
		while (bad[j] != '\0') {
			if (res[i] == bad[j]) {
				char copy[256];
				j = 0;
				while (res[j] != '\0') {
					copy[j] = res[j];
					j++;
				}
				copy[j] = '\0';
				res = del(copy, i, 1);
				len--;
				i--;
				break;
			}
			j++;
		}
		i++;
	}

	char copy[256];
	i = 0;
	while (res[i] != '\0') {
		copy[i] = res[i];
		i++;
	}
	copy[i] = '\0';
	std::cout << copy;
}