#include<bits/stdc++.h>
using namespace std;
int coinChange(int ara[],int n,int val)
{
    int tb[n+1][val+1];
    tb[0][0] = 1;
    for(int i = 1; i < val+1;i++)
    {
        tb[0][i] = 0;
    }
    for(int i = 1; i < n+1;i++)
    {
        for(int j = 0; j < val+1;j++)
        {
            if(j >= ara[i-1] ) //coin =ara[i-1]
            {
                tb[i][j] = tb[i-1][j]+tb[i][j-ara[i-1]];
            }
            else
            {
                tb[i][j] = tb[i-1][j];
            }
        }
    }
    cout << endl;
    for(int i= 0; i < n+1;i++)
    {
        for(int j = 0; j < val+1;j++)
        {
            cout << tb[i][j] << " ";
        }
        cout << endl;
    }
    return tb[n][val];
}

int main()
{
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n;i++)
    {
        cin >> ara[i];
    }
    int val;
    cin >> val;
    cout << "Number of values you can chage " << val << " : " << coinChange(ara,n,val) << endl;
}
