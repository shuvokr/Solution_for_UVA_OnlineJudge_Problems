/*
 * Sai Cheemalapati
 * UVA 11413: Fill the containers
 *
 */

#include<cstdio>

using namespace std;

int n, m, c[1100];

bool simul(int cap) {
	int tot = 0, cur = 0;
	for(int i = 0; i < n; i++) {
		if(c[i] > cap) return false;
		if(cur + c[i] > cap) cur = 0;
		if(cur == 0) tot++;
		cur += c[i];
		if(tot > m) return false;
	}
	return true;
}

int main() {

	while(scanf("%d %d", &n, &m) == 2) {
		for(int i = 0; i < n; i++)
			scanf("%d", &c[i]);

		int high = 1000000000, low = 0;
		while(high - low > 0) {
			if(simul(high)) {
				high = low + (high - low) / 2;
			} else {
				low = high;
				high = high + high / 2;
			}
		}
		printf("%d\n", high + 1);
	}
	return 0;
}
