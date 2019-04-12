#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>

#define MAX 0x7f7f7f

using namespace std;
int a[MAX], b[MAX];
queue <int> q;
int maxn = -1;
double x;
double sum = 0,sumx,sumx_;

void do1()
{
    sumx = double(sum) / x;
    printf("总和：%f\n", sum);
    printf("平均数：%f\n", sumx);
    return;
}

void zhong_shu()
{
    for (register int i = 0; i < MAX; ++i)
    {
        if (b[i] > maxn)
        {
            while (!q.empty())
            {
                q.pop();
            }
            q.push(i);
            maxn = b[i];
        }
        else if (b[i] == maxn)
        {
            q.push(i);
        }
    }
    printf("众数：");
    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
}

void fang_cha()
{
    double d=0;
    for (int i = 0; i < x; i++)
    {
        d += pow((sumx - a[i]), 2);
    }
    sumx_ = d / x;
    printf("方差：%f\n", sumx_);
    return;
}

int main()
{
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++;
        sum += a[i];
    }
    printf("\n");
    do1();
    zhong_shu();
    fang_cha();
}
