#include<iostream>
#include<vector>
#include<algorithm>
#define d 1000000001
using namespace std;
int main()
{
    int n,m,tmp;
    cin>>n>>m;
    int x,y;
    long int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<2*m;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        a[x][y]=d;
    }

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>tmp;
            if(a[i][j]==0)
            a[i][j]=tmp;
        }
    }
    vector<int> px1,px2,px3,px4,px5,px6,py1,py2,py3,py4,py5,py6;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
               if(a[i][j]==d)
                {
                    px1.push_back(-1);
                    px1.push_back(i);
                    py1.push_back(-1);
                    py1.push_back(j);
                }
                else
                {
                    px1.push_back(i);
                    py1.push_back(j); 
                }
                
                if(a[j][i]==d)
                {
                    px2.push_back(-1);
                    px2.push_back(j);
                    py2.push_back(-1);
                    py2.push_back(i);
                }
                else
                {
                    px2.push_back(j);
                    py2.push_back(i); 
                }
            }
            
            
            for(int j=n-1;j>=0;j--)
            {
               if(a[i][j]==d)
                {
                    px5.push_back(-1);
                    px5.push_back(i);
                    py5.push_back(-1);
                    py5.push_back(j);
                }
                else
                {
                    px5.push_back(i);
                    py5.push_back(j); 
                }
                
                if(a[j][i]==d)
                {
                    px6.push_back(-1);
                    px6.push_back(j);
                    py6.push_back(-1);
                    py6.push_back(i);
                }
                else
                {
                    px6.push_back(j);
                    py6.push_back(i); 
                }
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]==d)
                {
                    px1.push_back(-1);
                    px1.push_back(i);
                    py1.push_back(-1);
                    py1.push_back(j);
                }
                else
                {
                    px1.push_back(i);
                    py1.push_back(j); 
                }
                
                if(a[j][i]==d)
                {
                    px2.push_back(-1);
                    px2.push_back(j);
                    py2.push_back(-1);
                    py2.push_back(i);
                }
                else
                {
                    px2.push_back(j);
                    py2.push_back(i); 
                }
            }
            
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==d)
                {
                    px5.push_back(-1);
                    px5.push_back(i);
                    py5.push_back(-1);
                    py5.push_back(j);
                }
                else
                {
                    px5.push_back(i);
                    py5.push_back(j); 
                }
                
                if(a[j][i]==d)
                {
                    px6.push_back(-1);
                    px6.push_back(j);
                    py6.push_back(-1);
                    py6.push_back(i);
                }
                else
                {
                    px6.push_back(j);
                    py6.push_back(i); 
                }
            }
        }
    }
    
    int rs=0,rl=n-1,cs=0,cl=n-1;
    while(rs<=rl and cs<=cl)
    {
        for(int i=rs;i<=cl;i++)
        {
            if(a[rs][i]==d)
            {
                px3.push_back(-1);
                px3.push_back(rs);
                py3.push_back(-1);
                py3.push_back(i);
            }
            else
            {
                px3.push_back(rs);
                py3.push_back(i);
            }
            
            if(a[i][rs]==d)
            {
                px4.push_back(-1);
                px4.push_back(i);
                py4.push_back(-1);
                py4.push_back(rs);
            }
            else
            {
                px4.push_back(i);
                py4.push_back(rs);
            }
        }
        for(int j=rs+1;j<=rl;j++)
        {
            if(a[j][cl]==d)
            {
                px3.push_back(-1);
                px3.push_back(j);
                py3.push_back(-1);
                py3.push_back(cl);
            }
            else
            {
                px3.push_back(j);
                py3.push_back(cl);
            }
            
            if(a[cl][j]==d)
            {
                px4.push_back(-1);
                px4.push_back(cl);
                py4.push_back(-1);
                py4.push_back(j);
            }
            else
            {
                px4.push_back(cl);
                py4.push_back(j);
            }
        }
        if(rs+1<=rl)
        {
            for(int k=cl-1;k>=cs;k--)
            {
                if(a[rl][k]==d)
                {
                    px3.push_back(-1);
                    px3.push_back(rl);
                    py3.push_back(-1);
                    py3.push_back(k);
                }
                else
                {
                    px3.push_back(rl);
                    py3.push_back(k);
                }
                
                if(a[k][rl]==d)
                {
                    px4.push_back(-1);
                    px4.push_back(k);
                    py4.push_back(-1);
                    py4.push_back(rl);
                }
                else
                {
                    px4.push_back(k);
                    py4.push_back(rl);
                }
            }
        }
        if(cs+1<=cl)
        {
            for(int k=rl-1;k>rs;k--)
            {
                if(a[k][cs]==d)
                {
                    px3.push_back(-1);
                    px3.push_back(k);
                    py3.push_back(-1);
                    py3.push_back(cs);
                }
                else
                {
                    px3.push_back(k);
                    py3.push_back(cs);
                }
                
                if(a[cs][k]==d)
                {
                    px4.push_back(-1);
                    px4.push_back(cs);
                    py4.push_back(-1);
                    py4.push_back(k);
                }
                else
                {
                    px4.push_back(cs);
                    py4.push_back(k);
                }
            }
        }
        rs++;
        rl--;
        cs++;
        cl--;
    }
    
    vector<vector<int>> final1,final2,final3,final4,final5,final6;
    vector<int> tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
    int actv1=0,actv2=0,actv3=0,actv4=0,actv5=0,actv6=0;
    int cnt1=-1,cnt2=-1,cnt3=-1,cnt4=-1,cnt5=-1,cnt6=-1;
    
    for(int i=0;i<px1.size();i++)
    {
        if(px1[i]==-1 and py1[i]==-1)
        {
            ++cnt1;
            
            if(cnt1%2==0)
            actv1=1;
            else
            {
                actv1=0;
                tmp1.push_back(px1[i+1]);
                tmp1.push_back(py1[i+1]);
                final1.push_back(tmp1);
                tmp1.clear();
            }
        }
        else if(actv1==1)
        {
            tmp1.push_back(px1[i]);
            tmp1.push_back(py1[i]);
        }
    }
    
    for(int i=0;i<px2.size();i++)
    {
        if(px2[i]==-1 and py2[i]==-1)
        {
            ++cnt2;
            
            if(cnt2%2==0)
            actv2=1;
            else
            {
                actv2=0;
                tmp2.push_back(px2[i+1]);
                tmp2.push_back(py2[i+1]);
                final2.push_back(tmp2);
                tmp2.clear();
            }
        }
        else if(actv2==1)
        {
            tmp2.push_back(px2[i]);
            tmp2.push_back(py2[i]);
        }
    }
    
    for(int i=0;i<px3.size();i++)
    {
        if(px3[i]==-1 and py3[i]==-1)
        {
            ++cnt3;
            
            if(cnt3%2==0)
            actv3=1;
            else
            {
                actv3=0;
                tmp3.push_back(px3[i+1]);
                tmp3.push_back(py3[i+1]);
                final3.push_back(tmp3);
                tmp3.clear();
            }
        }
        else if(actv3==1)
        {
            tmp3.push_back(px3[i]);
            tmp3.push_back(py3[i]);
        }
    }
    
    for(int i=0;i<px4.size();i++)
    {
        if(px4[i]==-1 and py4[i]==-1)
        {
            ++cnt4;
            
            if(cnt4%2==0)
            actv4=1;
            else
            {
                actv4=0;
                tmp4.push_back(px4[i+1]);
                tmp4.push_back(py4[i+1]);
                final4.push_back(tmp4);
                tmp4.clear();
            }
        }
        else if(actv4==1)
        {
            tmp4.push_back(px4[i]);
            tmp4.push_back(py4[i]);
        }
    }
    
    for(int i=0;i<px5.size();i++)
    {
        if(px5[i]==-1 and py5[i]==-1)
        {
            ++cnt5;
            
            if(cnt5%2==0)
            actv5=1;
            else
            {
                actv5=0;
                tmp5.push_back(px5[i+1]);
                tmp5.push_back(py5[i+1]);
                final5.push_back(tmp5);
                tmp5.clear();
            }
        }
        else if(actv5==1)
        {
            tmp5.push_back(px5[i]);
            tmp5.push_back(py5[i]);
        }
    }
    
    for(int i=0;i<px6.size();i++)
    {
        if(px6[i]==-1 and py6[i]==-1)
        {
            ++cnt6;
            
            if(cnt6%2==0)
            actv6=1;
            else
            {
                actv6=0;
                tmp6.push_back(px6[i+1]);
                tmp6.push_back(py6[i+1]);
                final6.push_back(tmp6);
                tmp6.clear();
            }
        }
        else if(actv6==1)
        {
            tmp6.push_back(px6[i]);
            tmp6.push_back(py6[i]);
        }
    }
    
    long total1=0,total2=0,total3=0,total4=0,total5=0,total6=0;
    int tmpx,tmpy;
    
    for(int i=0;i<final1.size();i++)
    {
        for(int j=0;j<final1[i].size();j+=2)
        {
            tmpx=final1[i][j];
            tmpy=final1[i][j+1];
            total1+=a[tmpx][tmpy];
        }
    }
    
    for(int i=0;i<final2.size();i++)
    {
        for(int j=0;j<final2[i].size();j+=2)
        {
            tmpx=final2[i][j];
            tmpy=final2[i][j+1];
            total2+=a[tmpx][tmpy];
        }
    }
    
    for(int i=0;i<final3.size();i++)
    {
        for(int j=0;j<final3[i].size();j+=2)
        {
            tmpx=final3[i][j];
            tmpy=final3[i][j+1];
            total3+=a[tmpx][tmpy];
        }
    }
    
    for(int i=0;i<final4.size();i++)
    {
        for(int j=0;j<final4[i].size();j+=2)
        {
            tmpx=final4[i][j];
            tmpy=final4[i][j+1];
            total4+=a[tmpx][tmpy];
        }
    }
    
    for(int i=0;i<final5.size();i++)
    {
        for(int j=0;j<final5[i].size();j+=2)
        {
            tmpx=final5[i][j];
            tmpy=final5[i][j+1];
            total5+=a[tmpx][tmpy];
        }
    }
    
    for(int i=0;i<final6.size();i++)
    {
        for(int j=0;j<final6[i].size();j+=2)
        {
            tmpx=final6[i][j];
            tmpy=final6[i][j+1];
            total6+=a[tmpx][tmpy];
        }
    }
    long int finalans=std::max({total1,total2,total3,total4,total5,total6});
    
    if(finalans==total1)
    {
        for(int i=0;i<final1.size();i++)
        {
            cout<<final1[i].size()/2<<" ";
            for(int j=0;j<final1[i].size();j++)
            {
                cout<<final1[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
    else if(finalans==total2)
    {
        for(int i=0;i<final2.size();i++)
        {
            cout<<final2[i].size()/2<<" ";
            for(int j=0;j<final2[i].size();j++)
            {
                cout<<final2[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
    else if(finalans==total3)
    {
        for(int i=0;i<final3.size();i++)
        {
            cout<<final3[i].size()/2<<" ";
            for(int j=0;j<final3[i].size();j++)
            {
                cout<<final3[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
    else if(finalans==total4)
    {
        for(int i=0;i<final4.size();i++)
        {
            cout<<final4[i].size()/2<<" ";
            for(int j=0;j<final4[i].size();j++)
            {
                cout<<final4[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
    else if(finalans==total5)
    {
        for(int i=0;i<final5.size();i++)
        {
            cout<<final5[i].size()/2<<" ";
            for(int j=0;j<final5[i].size();j++)
            {
                cout<<final5[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
    else if(finalans==total6)
    {
        for(int i=0;i<final6.size();i++)
        {
            cout<<final6[i].size()/2<<" ";
            for(int j=0;j<final6[i].size();j++)
            {
                cout<<final6[i][j]+1<<" ";
            }
            cout<<"\n";
        }
    }
}