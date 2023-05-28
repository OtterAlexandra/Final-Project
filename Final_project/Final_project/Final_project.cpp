#include <vector>
#include <iostream>

using namespace std;


int line_sg(char arr[], int len) {
	int cnt = 0;
	int maxi = 0;
	bool flag = true;

	for (int i = 0; i < len; i++) {
		if (arr[i] != 'a' && arr[i] != 'o' && arr[i] != 'u' && arr[i] != 'i' && arr[i] != 'e' && arr[i] != 'y') {
			if (flag) cnt++;
			else {
				flag = true;
				cnt++;
			}
		}
		else {
			maxi = max(maxi, cnt);
			cnt = 0;
			flag = false;
		}
	}
	
	return max(maxi, cnt);
}

int line_gl(char arr[], int len) {
	int cnt = 0;
	int maxi = 0;
	bool flag = true;

	for (int i = 0; i < len; i++) {
		if (arr[i] == 'a' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'y') {
			if (flag) cnt++;
			else {
				flag = true;
				cnt++;
			}
		}
		else {
			maxi = max(maxi, cnt);
			cnt = 0;
			flag = false;
		}
	}

	return max(maxi, cnt);
}

int glasnii(char arr[]) {
	char gl[6] = {'a','o','u','i','e','y'};
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < sizeof(arr); j++) {
			if (tolower(arr[j]) == gl[i]) cnt++;
		}
	}

	return cnt;
}


int main()
{
	char word[45], message[45], ch;
	int i, key = 1;
	cin.getline(word, 45);

	int cnt = 0;

	for (key; key < 26; key++) {
		memcpy(message, word, 45);
		int len = 0;

		for (i = 0; message[i] != '\0'; ++i) {
			ch = message[i];
			if (ch >= 'a' && ch <= 'z') {
				ch = ch - key;
				if (ch < 'a') {
					ch = ch + 'z' - 'a' + 1;
				}
				message[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				ch = ch - key;
				if (ch > 'a') {
					ch = ch + 'Z' - 'A' + 1;
				}
				message[i] = ch;
			}
			len = i + 1;
		}
		if (cnt < 5) {
			if ((glasnii(message) >= (int) (len * 0.25)) && (len - glasnii(message) >= (int) (len * 0.25)) && line_gl(message, len) < 5 && line_sg(message, len) < 5) {
				cout << key << " " << message << '\n';
				cnt++;
			}
		}
	}

	return 0;
}

