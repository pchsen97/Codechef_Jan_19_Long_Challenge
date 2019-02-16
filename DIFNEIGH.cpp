#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,s,j,mx=1;
        cin>>n>>m;
        int a[n][m];
        if(n==1 and m==1)
        {
            a[0][0]=1;
        }
        else if(n==1 and m==2)
        {
            a[0][0]=1;
            a[0][1]=1;
        }
        else if(n==2 and m==1)
        {
            a[0][0]=1;
            a[1][0]=1;
        }
        else if(n==2 and m==2)
        {
            mx=2;
            a[0][0]=1;
            a[0][1]=1;
            a[1][0]=2;
            a[1][1]=2;
        }
        else if(n==1 and m>2)
        {
            s=0;
            mx=2;
            for(i=0;i<m/2;i++)
            {
                if(i&1)
                {
                    a[0][s]=2;
                    a[0][s+1]=2;
                    s+=2;
                }
                else
                {
                    a[0][s]=1;
                    a[0][s+1]=1;
                    s+=2;
                }
            }
            if(m&1)
            {
                if(a[0][m-2]==1)
                a[0][m-1]=2;
                else
                a[0][m-1]=1;
            }
        }
        else if(n>2 and m==1)
        {
            s=0;
            mx=2;
            for(i=0;i<n/2;i++)
            {
                if(i&1)
                {
                    a[s][0]=2;
                    a[s+1][0]=2;
                    s+=2;
                }
                else
                {
                    a[s][0]=1;
                    a[s+1][0]=1;
                    s+=2;
                }
            }
            if(n&1)
            {
                if(a[n-2][0]==1)
                a[n-1][0]=2;
                else
                a[n-1][0]=1;
            }
        }
        else if(n==2 and m>2)
        {
            mx=3;
            for(int i=1;i<=m;i++)
            {
                if(i%3==0)
                {
                    a[0][i-1]=3;
                    a[1][i-1]=3;
                }
                else
                {
                    a[0][i-1]=i%3;
                    a[1][i-1]=i%3;
                }
            }
        }
        else if(n>2 and m==2)
        {   
            mx=3;
            for(int i=1;i<=n;i++)
            {
                if(i%3==0)
                {
                    a[i-1][0]=3;
                    a[i-1][1]=3;
                }
                else
                {
                    a[i-1][0]=i%3;
                    a[i-1][1]=i%3;
                }
            }
        }
        else
        {
            mx=4;
            int p,q;
            for(i=0;i<n;i++)
            {
                if(i%4==0)
                {p=1;q=2;}
                else if(i%4==1)
                {p=3;q=4;}
                else if(i%4==2)
                {p=2;q=1;}
                else if(i%4==3)
                {p=4;q=3;}
                s=0;
                for(j=0;j<m/2;j++)
                {
                    if(j&1)
                    {a[i][s]=q;a[i][s+1]=q;s+=2;}
                    else
                    {a[i][s]=p;a[i][s+1]=p;s+=2;}
                }
                if(m&1)
                {
                    if(a[i][m-2]==p)
                        a[i][m-1]=q;
                    else
                        a[i][m-1]=p;
                }
            }   
        }
        cout<<mx<<"\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
return 0;
}