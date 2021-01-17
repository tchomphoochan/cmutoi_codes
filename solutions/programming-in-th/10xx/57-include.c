#include <stdio.h>
#include <stdbool.h>

int adjacent[1001][1001] = {};
int adjCount[1001] = {};

bool nodesChecked[1001] = {};
bool nodesChecking[1001] = {};
bool nodesReach[1001][1001] = {}; // index 0 true indicates problem

int n;

void check(int start)
{
    if (nodesChecked[start])
        return;
    
    nodesChecking[start] = true;

    bool pass = true;
    for (int i = 0; i < adjCount[start]; i++)
    {
        if (nodesChecking[adjacent[start][i]])
        {
            pass = false;
            break;
        }

        check(adjacent[start][i]);
        if (nodesReach[adjacent[start][i]][0])
        {
            pass = false;
            break;
        }
        for (int j = 1; j <= n; j++)
        {
            if (nodesReach[adjacent[start][i]][j])
            {
                if (nodesReach[start][j])
                {
                    pass = false;
                    break;
                }
                nodesReach[start][j] = true;
            }
        }
        if (!pass)
            break;
    }

    nodesChecking[start] = false;
    nodesChecked[start] = true;
    nodesReach[start][start] = true;
    if (!pass)
        nodesReach[start][0] = true;
}

int main(void)
{
    // input
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++)
        {
            int to;
            scanf("%d", &to);
            adjacent[i][adjCount[i]++] = to;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        check(i);
        if (nodesReach[i][0])   
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}