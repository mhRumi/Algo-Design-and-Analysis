#include<bits/stdc++.h>
using namespace std;

void LIS(int arr[], int n)
{
    int lis[n];
    lis[0]=1;

    vector < int > v;

    for(int i=1; i<n; i++)
    {
        lis[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j] +1;
            }
        }
    }

    int i =n;
    int lis_length = *max_element(lis,lis+n);
    cout<<"lis length : "<<lis_length<<endl;
    while(lis_length != 0 && i>= 0){
        if(lis[i-1] == lis_length)
        {
            v.push_back(arr[i-1]);
            lis_length--;
        }
        i--;
    }
    for(int i=v.size()-1; i>= 0; i--)
    {
        cout<<v[i]<< " ";
    }
}
int main()
{
    int arr[10] = { 10, 22, 9, 33, 21, 50, 41, 60,80, 90};
    //LIS(arr);
    int n = sizeof(arr)/sizeof(arr[0]);
    LIS(arr, n);
}
