#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n)
{
    int lis[n];

    lis[0] = 1;
    for(int i=1; i<n; i++)
    {
        lis[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j]+1 && arr[i] == arr[j]+1 )//&& ((arr[i] % 2 == 0 && arr[j] % 2 != 0) || (arr[i] % 2 != 0 && arr[j] % 2 == 0))
            {
                lis[i] = lis[j] +1;
            }
        }
    }

    cout<<endl;
    int lis_value = *max_element(lis, lis+n);

    for(int i=n; i>=0; i--)
    {
        if(lis_value == lis[i])
        {
            cout<<arr[i]<<" ";
            lis_value--;
        }
    }
    cout<<endl;

    return *max_element(lis, lis+n);
}

int main()
{
    int arr[] = { 10, 22, 9,11, 33 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
}
