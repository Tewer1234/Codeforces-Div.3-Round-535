#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int par[1000000];
map <int,int> mp;
struct node{
  int u,v,w;
};
node ary[1000000];
bool comp(node a,node b){
  return a.w<b.w;
}
int findRoot(int n){
  if (par[n]==-1) return n;
  else return par[n]=findRoot(par[n]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y,w,l=1;
  int epicked=0;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y>>w;
    ary[i].u=x;
    ary[i].v=y;
    ary[i].w=w;
  }
  
  sort(ary+1,ary+m+1,comp);
  
  for (int i=1;i<=n;i++) par[i]=-1;
  for (int i=1;i<=m;i++){
    
    x=ary[i].u;
    y=ary[i].v;
    w=ary[i].w;
    
    if (findRoot(x)!=findRoot(y)) epicked++;
    
    if (i+1<=m and ary[i].w!=ary[i+1].w){
      for (int j=l;j<=i;j++){
        int s1=findRoot(ary[j].u);
        int s2=findRoot(ary[j].v);
        
        if (s1!=s2){
          par[s2]=s1;
        }
      }
      l=i+1;
    }
  }
  
  int ans=epicked-(n-1);
  cout<<ans;
  return 0; 
}
