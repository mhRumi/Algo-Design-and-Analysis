#include<bits/stdc++.h>
using namespace std;
int n ;
int value;
int coins[] = {2, 3, 4, 5};
int counts[4];
int ways = 0;
void print_coin(int startIndex, int totalValue )
{
    if(startIndex >= n)
    {
        ways ++;
        int i = 0;
        cout<<value<<" : ";

        for(i = 0; i<n; i++)
        {
            if(i == n-1)
            {
                cout<<counts[i]*coins[i]<<endl;
            }
            else
            {
                cout<<counts[i]*coins[i]<<", ";
            }
        }

        return;
    }

    if(startIndex == n-1)
    {
        if(totalValue % coins[startIndex] == 0)
        {
            counts[startIndex] = totalValue/coins[startIndex];
            print_coin(startIndex+1, 0);
        }
    }

    else
    {
        int i= 0;
        for(int i=0; i<= totalValue/coins[startIndex]; i++)
        {
            counts[startIndex] = i;
            print_coin(startIndex+1, totalValue - coins[startIndex]*i);
        }
    }
}

int main()
{
    n = sizeof(coins)/sizeof(coins[0]);
    value = 5;
    print_coin(0,value);

    cout<<"Ways : "<<ways<<endl;
}
