#include <cstdio>
#include <vector>
#include <cstdlib>
#include <array>

inline int max(int a, int b);

int main(void) {
	int n;
	int temp;
	std::vector<int> steps;
	std::vector<int> old;

	int dp[4][2] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		steps.reserve(n);
		scanf("%d", &temp);
		steps.push_back(temp);
	}
	steps.push_back(0);
	steps.push_back(0);

	dp[1][0] = steps[0];
	for (int i = 0; i < n; ++i) {
		dp[2][0] = max(dp[0][0] + steps[i + 1], dp[2][0]);
		dp[2][0] = max(dp[0][1] + steps[i + 1], dp[2][0]);
		dp[1][1] = max(dp[0][0] + steps[i], dp[1][1]);
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 2; ++k)
				dp[j][k] = dp[j + 1][k];
		for (int j = 0; j < 2; ++j)
			old.push_back(dp[0][j]);
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%3d ", old[j * 2 + i]);
		}
		printf("\n");
	}

	int answer = 0;
	for (int i = 0; i < 2; ++i)
		answer = max(answer, dp[0][i]);
	
	printf("%d\n", answer);
	
	return 0;
}

inline int max(int a, int b) {
	return a < b ? b : a;
}
