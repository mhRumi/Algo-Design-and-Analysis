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

void Search(string pattern, string hashTable[])
{
    int r = radix(pattern);
    while(hashTable[r] != pattern && r< token.size())
    {
        r = (r+ 1) ;
    }
    if(hashTable[r] == pattern)
        cout<<"found at position  "<<r<<endl;
    else
    cout<<"Not found"<<endl;

}



void Insert(string hashTable[])
{
    for(int i=0; i<token.size(); i++)
    {
        int r = radix(token[i]);
        while(hashTable[r] != ""){
                r = (r+1) % token.size();
        }
        cout<<r<<"  "<<token[i]<<endl;

        hashTable[r] = token[i];
    }

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
    string hashTable[token.size()];

    for(int i=0; i<token.size(); i++){
        hashTable[i] == "";
    }
    Insert(hashTable);
    Search("bangla",hashTable);

}
