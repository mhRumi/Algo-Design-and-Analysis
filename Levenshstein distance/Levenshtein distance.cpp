#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cout<<"src : ";
    cin>>s2;

    cout<<"destn : ";
    cin>>s1;

    int m = 0,n = 0;

    n = s1.size();
    m = s2.size();
    int arr[m+1][n+1];
    string src = "";
    string destn = "";

    for(int i=0; i<=n; i++){
        arr[0][i] = i;
    }
    for(int i=0; i<=m; i++){
        arr[i][0] = i;
    }

    for(int i=1; i<=s2.size(); i++)
    {
        for(int j=1; j<=s1.size(); j++)
        {
            if(s2[i-1] == s1[j-1]){
                // small is the samllest between up and left
                    int small = min(arr[i-1][j]+1,arr[i][j-1]+1);
                arr[i][j] = min(arr[i-1][j-1],small);


            }
            else{
                int small = min(arr[i-1][j]+1,arr[i][j-1]+1);
                arr[i][j] = min(arr[i-1][j-1]+2,small);
            }

        }
    }


     for(int i=0; i<=s2.size(); i++)
    {
        for(int j=0; j<=s1.size(); j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    int i=m;
    int j=n;

        while( i > 0 && j > 0)
        {
            int small = min(arr[i-1][j],arr[i][j-1]);
            if(arr[i-1][j-1] < small){
                src = s2[i-1]+src;
                destn = s2[i-1]+destn;
                i--;
                j--;
            }else{
                if(arr[i-1][j]<arr[i][j-1]){
                    src = s2[i-1]+src;
                    i--;
                    destn = "-"+destn;
                }else{
                    src = "-"+src;
                    destn = s1[j-1]+destn;
                    j--;
                }
            }

        }


    int lenght = arr[m][n];
    cout<<"lenght "<<lenght<<endl;
    cout<<"src :   "<<src<<endl;
    cout<<"destn : "<<destn<<endl;



}

