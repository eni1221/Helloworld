#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int> ao;
int main() {
	scanf("%d",&n);
	
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (ao.empty()) printf("0\n");
			else {
				printf("%d\n", ao.top());
				ao.pop();
			}
		}
		else {
			ao.push(x);
		}

	}
	return 0;
}