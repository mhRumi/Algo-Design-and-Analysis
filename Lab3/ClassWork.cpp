#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector < pair<int , int > > v;
    vector < pair<int,int > > unit_price;
    vector<pair<int , int > > taking_amount;

    cout<<"Input size: ";
    int n, bag_size, profit=0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int item_value, item_amount;
        cin>>item_value>>item_amount;
        //v.push_back(make_pair(item_value,item_amount));
        unit_price.push_back(make_pair(item_value/item_amount,item_amount));
    }

    sort(unit_price.begin(),unit_price.end());
    reverse(unit_price.begin(),unit_price.end());

    cout<<"bag size :";
    cin>>bag_size;

    for(int i=0; i<unit_price.size(); i++)
    {
        //cout<<unit_price[i].first<<"   "<<unit_price[i].second<<endl;

        if(unit_price[i].second <= bag_size)
        {
            profit += unit_price[i].second * unit_price[i].first;
            bag_size -= unit_price[i].second;

            taking_amount.push_back(make_pair(unit_price[i].second,unit_price[i].second ));
        }
        else if(bag_size >0)
        {
            profit += bag_size * unit_price[i].first;

            taking_amount.push_back(make_pair(unit_price[i].second, bag_size ));
            bag_size = 0;
        }

        if(bag_size <= 0)
        {
            break;
        }


    }

    cout<<"profit  "<<profit<<endl;

    for(int i=0; i<taking_amount.size(); i++)
    {
        cout<<taking_amount[i].first<<"   "<<taking_amount[i].second<<endl;
    }
}
