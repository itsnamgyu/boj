#include <cstdio>
#include <vector>

int main(void) {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		auto ways_to = std::vector<int>(5, 0);
		ways_to[2] = 1;

		int n;
		scanf("%d", &n);

		for (int j = 0; j < n; ++j) {
			ways_to[3] = ways_to[0] + ways_to[1] + ways_to[2];

			for (int k = 0; k < 4; ++k)
				ways_to[k] = ways_to[k + 1];
		}

		printf("%d\n", ways_to[2]);
	}
}
