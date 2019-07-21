#include<bits/stdc++.h>
using namespace std;
vector < string > token;
int radix_size = 128;

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

void Search(string pattern, string output[])
{
    int r = radix(pattern);
    cout<<r<<endl;
    while(output[r] != pattern && r< token.size())
    {
        r = (r+ 1) ;
        cout<<r<<endl;

    }
    if(output[r] == pattern)
        cout<<"found at position  "<<r<<endl;
    else
    cout<<"Not found"<<endl;

}



void Insert(string output[])
{
    cout<<"At insert"<<endl;
    for(int i=0; i<token.size(); i++)
    {
        int r = radix(token[i]);
        while(output[r] != ""){
                r = (r+1) % token.size();
        }
        cout<<r<<"  "<<token[i]<<endl;

        output[r] = token[i];
    }

    cout<<"end of insert"<<endl;
}

int main()
{
    string text, temp;
    getline(cin,text);

    stringstream s(text);

    while(s >> temp)
    {
        token.push_back(temp);
    }
    string output[token.size()];

    for(int i=0; i<token.size(); i++){
        output[i] == "";
    }
    Insert(output);
    Search("bangla",output);

}
