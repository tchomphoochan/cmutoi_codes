#include <bits/stdc++.h>

const int N = 360;
const int MOD = 29947;

int X, Y, Z;
int dp[N][N][N];
bool calc[N][N][N];

int solve(int x, int y, int z)
{
    if (x > X || y > Y || z > Z)
        return 0;
    if ((x == X && y == Y)
        || (x == X && z == Z)
        || (y == Y && z == Z))
        return 1;
    int &ans = dp[x][y][z];
    if (calc[x][y][z])
        return ans;

    ans = solve(x+1, y, z) + solve(x, y+1, z) + solve(x, y, z+1)
        - solve(x+1, y+1, z) - solve(x+1, y, z+1) - solve(x, y+1, z+1)
        + solve(x+1, y+1, z+1) // inclusive-exclusive
        + solve(x+1, y+1, z)
        + solve(x+1, Y, z+1)
        + (y < Y ? solve(x, Y, z+1) : 0);

    calc[x][y][z] = true;
    return ans;
}

int main()
{
    scanf("%d%d%d", &X, &Y, &Z);
    --X; --Y; --Z;

    for (int x = 0; x <= X; ++x) {
        for (int y = 0; y <= Y; ++y) {
            for (int z = 0; z <= Z; ++z) {
                printf("dp[%d][%d][%d] = %d\n", x, y, z, solve(x,y,z));
            }
        }
    }

    return 0;
}
