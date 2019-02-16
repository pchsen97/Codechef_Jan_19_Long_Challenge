#include <iostream>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int n,p;
        cin>>n>>p;
        if(n==1 or n==2)
        cout<<p*p*p<<"\n";
        else if(n==p)
        cout<<((p/2)+1)*((p/2)+1)<<"\n";
        else
        {
            long int mx=(n-1)/2;
            long int b,c,a;
            b=p-mx;
            c=p-n;
            a=b+c;
            long long int ans=a*a-b*c;
            cout<<ans<<"\n";
        }
        
    }
return 0;
}