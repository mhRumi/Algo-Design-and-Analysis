#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cout<<"Enter string 1 : ";
    cin>>s1;

    cout<<"Enter string 2 : ";
    cin>>s2;

    int m = 0,n = 0;
    n = s1.size()+1;
    m = s2.size()+1;
    s1 = " "+s1;
    s2 = " "+s2;
    int arr[m][n];
    string result= "";

    for(int i=0; i<n; i++){
        arr[0][i] = 0;
    }

     for(int i=0; i<m; i++){
        arr[i][0] = 0;
    }

    for(int i=1; i<s2.size(); i++)
    {
        for(int j=1; j<s1.size(); j++)
        {
            if(s2[i] == s1[j]){
                arr[i][j] = arr[i-1][j-1]+1;
                result += s2[i];
            }
            else{
                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
            }

        }
    }

    int lenght = arr[m-1][n-1];
    cout<<"lenght "<<lenght<<endl;
    cout<<result<<endl;


}
