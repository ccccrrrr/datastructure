#include<bits/stdc++.h>
#define MAX_N 700
using namespace std;
/**
 * 分析问题：如果回答是no，说明两人肯定不是同类。如果是yes，那么就是同类。每回答一次问题两人就建立了一种联系，可以是用并查集去维护，即relation数组存储点和其父亲的关系。
 * 那么对于每一组集合，都会有两类人的不同数量。可以通过动态规划求出是否存在唯一一种方法对应好人人数。
 * 如果有，还需要使用回溯的方法得到这个解。
 */
int N,M,T,X,Y;
int ans;
int parent[MAX_N];
// 与根节点的关系
int relation[MAX_N];
char str[10];
// 储存同类、异类的个数
int data[2*MAX_N];
// dp[i][j]前i个群中拼成j有几种情况
int dp[MAX_N][MAX_N];
int path[MAX_N][MAX_N];
int setname[MAX_N];
int find(int k);
int backpack() {
    int i,j,k,t,m;
    k=0;
    memset(dp,0,sizeof(dp));
    memset(path,0,sizeof(path));
    memset(data,0,sizeof(data));
    memset(setname,0,sizeof(setname));
    for(i=1;i<=X+Y;i++)
        find(i);
    for(i=1;i<=X+Y;i++)
        if(parent[i]==-1)
            setname[k++]=i;//得到各个集合，以根结点标识
    for(i=0;i<k;i++)
        for(j=data[2*i]=1;j<=X+Y;j++)//根与自身定为同类
            if(parent[j]==setname[i])
                if(relation[j]==0)
                    data[2*i]++;//统计与自己同类的元素个数
                else
                    data[2*i+1]++;
    dp[0][data[0]]++;path[0][data[0]]=1;
    dp[0][data[1]]++;path[0][data[1]]=2;
        //这里要求是全部的集合都使用完后再判断（因为每个集合中都是与自己相反或相同的类别）。
       for(i=1;i<k;i++)
        for(j=X;j>=0;j--) {
            if(j>=data[2*i] && dp[i-1][j-data[2*i]] )
                dp[i][j]+=dp[i-1][j-data[2*i]],path[i][j]=1;
            if(j>=data[2*i+1] && dp[i-1][j-data[2*i+1]] )
                dp[i][j]+=dp[i-1][j-data[2*i+1]],path[i][j]=2;
        }
    if(dp[k-1][X]!=1)
        return 0;
    ans=0;
    m=X;
    i=k-1;
    while(i>=0) {
        if(path[i][m]==1) {
            t=0;
            m=m-data[2*i];
        }
        else{
            t=1;
            m=m-data[2*i+1];
        }
        for(j=1;j<=X+Y;j++)
            if(parent[j]==setname[i] || j==setname[i])
                if(relation[j]==t)
                    dp[0][ans++]=j;        
        i--;
    }
    sort(dp[0],dp[0]+ans);
    return 1;  
}

int find(int k) {
    if(parent[k]==-1)
        return k;
    int t=parent[k];
    parent[k]=find(parent[k]);
    relation[k]=(relation[k]+relation[t])%2; // 和食物链一样的处理方法
    return parent[k];
}

int main() {
    int i;
    int e,r,e_root,r_root,cnt;
    while(scanf("%d%d%d",&N,&X,&Y))
    {
        if(X==0 && Y==0 && N==0)
            break;
        memset(parent,-1,sizeof(parent));
        memset(relation, 0,sizeof(relation));
        for(i=0;i<N;i++) {
            scanf("%d%d%s",&e,&r,str);
            if(r<e) swap(r,e);
            e_root=find(e);
            r_root=find(r);
            if(e_root==r_root)
                continue; // 两点已经在一棵树中了，不需要再更新并查集的关系
            if(str[0]=='y')
                parent[r_root]=e_root,relation[r_root]=(relation[e]+relation[r])%2; // 更新关系
            else
                parent[r_root]=e_root,relation[r_root]=(1+relation[r]+relation[e])%2;
        }
        if(backpack()==0)
            printf("no\n");
        else {
            for(i=0;i<ans;i++)
                printf("%d\n",dp[0][i]);
            printf("end\n");
        }
    } 
  return 0;  
}