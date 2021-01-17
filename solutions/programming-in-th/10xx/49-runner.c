#include <stdio.h>

int n, m;

int blockCount[10001] = {}; // count how many players is in a block
int seqBestPlayer[1000001] = {}; // best player running ith time
int seqBestSpeed[1000001] = {}; // best speed of player running ith time
int seqBestBlock[1000001] = {}; // block of best player running ith time

int main(void)
{
    scanf("%d%d", &n, &m);

    int maxPlace = 0;
    while (n--)
    {
        int id, block, speed;
        scanf("%d%d%d", &id, &block, &speed);

        int seq = ++blockCount[block];
        if (speed > seqBestSpeed[seq]
        || (speed == seqBestSpeed[seq]
        && (seqBestBlock[seq] == 0 || block < seqBestBlock[seq])))
        {
            seqBestSpeed[seq] = speed;
            seqBestPlayer[seq] = id;
            seqBestBlock[seq] = block;
        }

        if (seq > maxPlace)
            maxPlace = seq;
    }

    for (int i = 1; i <= maxPlace; i++)
        printf("%d\n", seqBestPlayer[i]);

    return 0;
}