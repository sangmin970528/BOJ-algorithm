#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

int map[301][301];
int dp[301][301];

int solve(int x, int y) {
    if (x < 1 || y < 1) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = map[x][y];
    if (x == 1 && y == 1) return dp[x][y];
    return dp[x][y] += max(solve(x - 1, y), solve(x, y - 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> map[i][j];
    cout << solve(N,M) << "\n";
}
