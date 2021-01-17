#include <iostream>
#include <string>
#include <algorithm>

#define TEAM 4
#define WIN 3
#define DRAW 1
#define LOSE 0

using namespace std;

int score[TEAM] = {}; // total scores
int game[TEAM][TEAM]; // score in each game
int shoot[TEAM] = {}; // number of balls shoot to other team
int shot[TEAM] = {}; // number of balls lost

bool compare(int a, int b)
{
    if (score[a] > score[b])
        return true;
    if (score[a] < score[b])
        return false;
    
    if (shoot[a] - shot[a] > shoot[b] - shot[b])
        return true;
    if (shoot[a] - shot[a] < shoot[b] - shot[b])
        return false;
    
    return shoot[a] > shoot[b];
}

int main()
{
    string teamName[TEAM];

    // input
    for (int i = 0; i < TEAM; i++)
        cin >> teamName[i];
    for (int i = 0; i < TEAM; i++)
    {
        for (int j = 0; j < TEAM; j++)
            cin >> game[i][j];
    }

    // check scoreboard
    for (int i = 0; i < TEAM; i++)
    {
        for (int j = 0; j < TEAM; j++)
        {
            if (i == j)
                continue;

            // add score for wins
            if (game[i][j] > game[j][i])
                score[i] += WIN;
            else if (game[i][j] == game[j][i])
                score[i] += DRAW;
            else
                score[i] += LOSE;
            
            // add own shoots and other lost
            shoot[i] += game[i][j];
            shot[j] += game[i][j];
        }
    }

    // sort
    int rank[TEAM];
    for (int i = 0; i < TEAM; i++)
        rank[i] = i;
    sort(rank, rank + TEAM, compare);

    for (int i = 0; i < TEAM; i++)
        cout << teamName[rank[i]] << " " << score[rank[i]] << endl;

    return 0;
}