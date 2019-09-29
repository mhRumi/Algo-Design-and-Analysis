#include<bits/stdc++.h>
using namespace std;

int minimum_num_coin(int coin[],int m, int v)
{
    int table[v+1];
    table[0] = 0;
    for(int i=1; i<= v; i++)
        table[i] = INT_MAX;

    for(int i=1; i<=v; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(coin[j] <= i)
            {
                int sub_res = table[i - coin[j]];

                if(sub_res != INT_MAX && sub_res +1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }

    return table[v];
}

int main()
{
    int coin[] = {2, 3, 5};
    int m = sizeof(coin)/sizeof(coin[0]);

    int v = 6;
    cout<<"Minimum number of coin: "<<minimum_num_coin(coin, m, v)<<endl;
}
