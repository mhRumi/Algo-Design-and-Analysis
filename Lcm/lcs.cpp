#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;

    int m = 0,n = 0;
    n = s1.size();
    m = s2.size();
    int arr[m][n];
    string result= "";

    for(int i=0; i<=s2.size(); i++)
    {
        for(int j=0; j<=s1.size(); j++)
        {
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else if(s2[i-1] == s1[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
            }
        }
    }
    int i = m, j = n;
    while(i >0 && j>0){
        if(s2[i-1] == s1[j-1]){
            result = s2[i-1]+result;
            i--;
            j--;
        }
        else if(arr[i-1][j] > arr[i][j-1])
            i--;
        else
            j--;
    }

    int length = arr[m][n];
    cout<<"length: "<<length<<endl;
    cout<<result<<endl;


}
