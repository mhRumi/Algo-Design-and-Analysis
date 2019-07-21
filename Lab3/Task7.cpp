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
    return rad_sum ;
}



int Hash1(int k)
{
    return k % token.size();
}

int Hash2(int k)
{

    return 1+(k %1000);
}

void Insert( string hashTable[])
{
    int j;
    for(int i= 0; i<token.size(); i++){
    int k = radix(token[i]);
    int hash1 = Hash1(k);
    int hash2 = Hash2(k);

    for( j=0; j<token.size(); j++)
    {
        int index=(hash1+j*hash2)%token.size();
        if(hashTable[index] == "")
        {

            hashTable[index]= token[i];
            break;
        }
    }
    }
}

void Search(string text, string hashTable[])
{
    int j;
    for(int i= 0; i<token.size(); i++){
    int k = radix(text);
    int hash1 = Hash1(k);
    int hash2 = Hash2(k);

    for( j=0; j<token.size(); j++)
    {
        int index=(hash1+j*hash2)%token.size();
        if(hashTable[index] == text)
        {
            cout<<"found at "<<index<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
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
    string hashTable[1001];

    for(int i=0; i<token.size(); i++)
    {
        hashTable[i] == "";
    }
    Insert(hashTable);
    Search("bangla",hashTable);

}




