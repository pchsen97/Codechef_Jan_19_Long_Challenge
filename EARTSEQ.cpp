#include <iostream>
#include<vector>
#define d 800
using namespace std;

int main()
{
    long int i=1,p=2,f,count;
    vector<long int> V;
    while(i<=1668)
    {
        f=1;
        for(count=2;count<=p-1;count++)
        {
            if(p%count==0)
            {f=0;break;}
        }
        if(f==1)
        {
            V.push_back(p);
	        i++;
        }
        p++;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int N,n;
        cin>>N;
        if(N==3)
        cout<<6<<" "<<10<<" "<<15<<"\n";
        else if(N==4)
        cout<<6<<" "<<15<<" "<<35<<" "<<154<<"\n";
        else if(N==5)
        cout<<6<<" "<<15<<" "<<35<<" "<<77<<" "<<286<<"\n";
        else if(N<=3333)
        {
            if(N%2==1)
            n=((N-1)/2)+2;
            else
            n=((N-1)/2)+3;
            for(i=0;i<n-2;i++)
            {
                if((N%2==0) and i==n-3)
                cout<<V[i]*V[i+1]<<" "<<(3*V[i]*V[i+2])<<" ";
                else
                cout<<V[i]*V[i+1]<<" "<<V[i]*V[i+2]<<" ";
            }
            if(N&1)
            cout<<V[n-2]*V[n-1]*3<<"\n";
            else
            cout<<"\n";
        }
        else{
            vector<long int> v;
            for(int j=0;j<d;j++)
            {
                v.push_back(V[j]);
            }
            n=N;
            int a=1,pre,pos;
            vector<long int> ans;
            for(int i=0;n!=0;i+=a)
            {
                pre=i%d;
                pos=(i+a)%d;
                if(n==1)
                {
                    if((v[pre]*v[pos])%3!=0)
                    {
                        bool chk=(ans.back()%2==0 and (v[pre]*v[pos])%2==0);
                        if(chk==false)
                        {
                            ans.push_back((v[pre]*v[pos]*2));
                            n--;
                        }
                    }
                }
                else
                {
                    ans.push_back(v[pre]*v[pos]);
                    n--;
                }
                if(pos==0)
                {
                    ++a;
                    i=(0-a);
                }
            }
            for(int j=0;j<N;j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
