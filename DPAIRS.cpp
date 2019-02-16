#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long int n,m,t;
    cin>>n>>m;
    long int a[n],b[m];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    long int p,q;
    p=std::max_element(a,a+n)-a;
    q=std::min_element(b,b+m)-b;
    for(long int i=0;i<n;i++)
    {
        cout<<i<<" "<<q<<"\n";
    }
    for(long int i=0;i<m;i++)
    {
        if(i!=q)
        cout<<p<<" "<<i<<"\n";
    }
}