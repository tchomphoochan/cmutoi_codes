#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int data[1000000];
long long sum = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    int middle = n / 2;
    nth_element(data, data + middle, data + n);
    int med = data[middle];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] <= med)
            count++;
    }
    count = count - middle;

    for (int i = 0; i < n; i++)
    {
        if (data[i] > med || (data[i] == med && count-- > 0))
            sum += data[i];
        else
            sum -= data[i];
    }

    printf("%lld", sum);

    return 0;
}