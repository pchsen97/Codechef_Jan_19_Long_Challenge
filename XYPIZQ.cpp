#include <iostream>
using namespace std;
typedef long int ll;
ll gcd(ll a,ll b) 
{ 
    if(a==0) 
        return b; 
    return gcd(b%a,a); 
} 
int main()
{
    int ts;
    cin>>ts;
    while(ts--)
    {
        int t;
        ll N,x,y,z,m,n;
        cin>>N>>t>>x>>y>>z;
        n=2*N+1;
        if(t==1)
        {
            if(x<y and y<z)
                m=2*N-y;
            else if(x<y and z<y)
                m=y-1;
            else if(x>y and z>y)
                m=y+1;
            else if(x>y and z<y)
                m=2*N-y+2;
        }
        else if(t==2)
        {
            if(x<y and z>y)
            m=2*N-2*y+1;
            else if(x<y and z<y)
            m=2*N-y+2;
            else if(x>y and z==0)
            m=2*N-y;
            else if(x>y and z<y)
            m=2*N-2*y+1;
        }
        else if(t==3)
        {
            if(x>y and z<y)
            m=2*N-y;
            else if(x>y and z>y)
            m=y+1;
            else if(x<y and z<y)
            m=y-1;
            else if(x<y and z>y)
            m=2*N-y+2;
        }
        else if(t==4)
        {
            m=2*N-2*y+1;
        }
        if(gcd(m,n)==1)
        cout<<m<<" "<<n<<"\n";
        else
        {
            ll tmp=gcd(m,n);
            m=m/tmp;
            n=n/tmp;
            cout<<m<<" "<<n<<"\n";
        }
    }
    return 0;
}