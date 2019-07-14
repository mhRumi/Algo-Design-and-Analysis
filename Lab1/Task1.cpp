#include<bits/stdc++.h>
using namespace std;
int radix_size;
vector < string > token;

int radix(string text)
{
    long long rad_sum = 0;
    for(int i=0; i<text.size(); i++)
    {
        int rads = text[i]*pow(radix_size,i);
        rad_sum += rads;
    }
    return rad_sum % token.size();
}
void Hashfunction(int output[])
{
    for(int i=0; i<token.size(); i++)
    {
        int r = radix(token[i]);
        output[r] = 1;

    }
}
int main()
{

    string input, temp;
    getline(cin,input);
    cin>>radix_size;

    stringstream s(input);

    while(s >> temp)
    {
        token.push_back(temp);
    }
     int output[token.size()];
    Hashfunction(output);
    int cnt = 0;
    for(int i=0; i<token.size(); i++)
    {
        if(output[i] == 1)
            cnt++;
    }
    cout<<cnt<<endl;
}
