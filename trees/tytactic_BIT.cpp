    #include <iostream>
    #include <stdio.h>
    #include <string.h>
    #include <vector>
    #include <math.h>
    #include <algorithm>
    using namespace std;
    #define ULL unsigned long long int
    #define SC(n) scanf("%d",&n)
    vector<int> g1[100005],g2[100005];
    int position=0;
    int noe[100010]={0};
    int pos[100010]={0};
    ULL wt[100010]={0};
    ULL map_wt[100010]={0};
    ULL bit[100010]={0};
     
    int mapping(int u)
    {
    if(pos[u]>0)
    return 0;
    pos[u]=++position;
    int count=0;
    for(int i=0;i<g1[u].size();i++)
    {
    if(pos[g1[u][i]]==0)
    {
    count+=mapping(g1[u][i]);;
    }
    }
    noe[u]=count;
    return ++count;
    }
    void update(int i,int size,int val)
    {
    // cout<<"pos= "<<i<<endl;
    while(i<=size)
    {
    bit[i]+=val;
    // cout<<i<<" ";
    i+=(i & (-i));
    }
    // cout<<endl;
    }
    ULL getSum(int i)
    {
    ULL sum=0;
    // cout<<"pos= "<<i<<endl;
    while(i>0)
    {
    sum+=bit[i];
    // cout<<i<<" ";
    i-=(i & (-i));
    }
    // cout<<endl;
    return sum;
    }
    int main()
    { int n,q,a,b;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    scanf("%d",&wt[i]);
    int k=n-1;
    while(k--)
    {
    scanf("%d%d",&a,&b);
    g1[a].push_back(b);
    g1[b].push_back(a);
    }
    mapping(1);
    for(int i=1;i<=n;i++)
    {
    map_wt[pos[i]]=wt[i];
    }
    // for(int i=1;i<=n;i++)
    // {
    // cout<<map_wt[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
    update(i,n,map_wt[i]);
    }
    // for(int i=1;i<=n;i++)
    // {
    // cout<<bit[i]<<" ";
    // }
    // cout<<endl;
    char ch;int x,y;
    while(q--)
    {
    cin>>ch>>x;
    if(ch=='Q')
    {
    cout<<getSum(pos[x]+noe[x])-getSum(pos[x]-1)<<endl;
    }
    else
    { cin>>y;
    
    update(pos[x],n,y-wt[x]);
    wt[x]=y;
    }
    }
    //system("pause");
    return 0;
    } 
