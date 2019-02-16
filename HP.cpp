#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int both=0,onlya=0,onlyb=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%a==0 && arr[i]%b==0)
                {
                    arr[i]=0;
                    both++;
                }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=1)
            {
                if(arr[i]%a==0 && arr[i]%b!=0)
                onlya++;
                else if(arr[i]%a!=0 && arr[i]%b==0)
                onlyb++;
            }
        }
        bool ans;
        if(both==0)
        {
            if(onlya>onlyb)
            ans=1;
            else
            ans=0;
        }
        else
        {
            if(onlya>=onlyb)
            ans=1;
            else if(onlya<onlyb)
            ans=0;
        }
        if(ans)
        cout<<"BOB"<<endl;
        else
        cout<<"ALICE"<<endl;
    }
}
