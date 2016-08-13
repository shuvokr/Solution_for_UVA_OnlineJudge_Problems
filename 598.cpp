#include<cstdio>
#include<iostream>

using namespace std;

int M, a, b, n;
string line;
string names[20];

void generate(int size, int k, int l, string ans) {
	if(k == size) {
		for(int i = l; i < n; i++)
			cout << ans << names[i] << endl;
		return;
	}
	for(int i = l; i < n; i++) {
		generate(size, k + 1, i + 1, ans + names[i] + ", ");
	}
}

int main() {
	scanf("%d\n\n", &M);
	while(M--) {
		getline(cin, line);
		if(line != "*") {
			if(sscanf(line.c_str(), "%d %d\n", &a, &b) == 1)
				b = a;
		} else a = 0, b = 0;

		for(int i = 0;; i++) {
			n = i;
			getline(cin, line);
			if(line.length() == 0) break;
			names[i] = line;
		}

		if(a == 0 && b == 0) a = 1, b = n;
		if(a != 0 && b == 0) b = a;
		for(int i = a - 1; i < b; i++) {
			cout << "Size " << i + 1 << endl;
			generate(i, 0, 0, "");
			cout << endl;
		}

		if(M) cout << endl;
	}
}
