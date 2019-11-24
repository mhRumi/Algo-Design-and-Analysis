#include<bits/stdc++.h>
using namespace std;

void longestIncreasingOddEvenSequence(int arr[], int n){
    int lioes[n];
    for(int i=0; i<n; i++)
        lioes[i] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j] && (arr[i]+arr[j]) % 2 != 0 && lioes[i] < lioes[j] +1)
            {
                lioes[i] = lioes[j]+1;
            }
        }
    }

    int lioes_length = *max_element(lioes,lioes+n);
    vector< int> v;
    for(int i=n-1; i>=0; i--)
    {
        if(lioes[i] == lioes_length)
        {
            v.push_back(arr[i]);
            lioes_length--;
        }
    }

    for(int i=v.size()-1; i>= 0; i--)
    {
        cout<<v[i]<< " ";
    }
}

int main()
{
   int arr[] = { 1, 12, 2, 22, 5, 30, 31, 14, 17, 11 };
   int n = sizeof(arr)/sizeof(arr[0]);
   longestIncreasingOddEvenSequence(arr, n);
}
