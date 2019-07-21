
#include<bits/stdc++.h>
using namespace std;
vector < string > token;
int radix_size = 128;
int c1 = 29, c2 = 19;

int radix(string text)
{
    long long rad_sum = 0;
    for(int i=0; i<text.size(); i++)
    {
        int rads = text[i]*pow(radix_size,i);
        rad_sum += rads;
    }
    return rad_sum% token.size() ;
}



void Insert( string hashTable[])
{
    int j;
    for(int i= 0; i<token.size(); i++){
    int k = radix(token[i]);

    for( j=0; j<token.size(); j++)
    {
        int index=(k+ c1 * j + c2 * (i*i))%token.size();
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
    int k = radix(text);

    for( j=0; j<token.size(); j++)
    {
        int index=(k+ c1 * j + c2 * (j*j))%token.size();
        if(hashTable[index] == text)
        {
            cout<<"found at "<<index<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
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




