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
typedef pair<int,char> pp;
int ary[1000000],le[1000000],ri[1000000];
int lazy[1000000],check[1000];
int t[1000000];
int build(int ind,int l,int r){
  int lc=(ind<<1);
  int rc=(ind<<1)|1;
  if (l==r){
    return t[ind]=ary[l];
  }
  
  int mid=(l+r)>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  return t[ind]=max(t[lc],t[rc]);
}

void push(int ind){
  int lc=(ind<<1);
  int rc=(ind<<1)|1;
  t[lc]+=lazy[ind];
  t[rc]+=lazy[ind];
  lazy[lc]+=lazy[ind];
  lazy[rc]+=lazy[ind];
  lazy[ind]=0;
}

void update(int ind,int tl,int tr,int l,int r,int subtract){
  int lc=(ind<<1);
  int rc=(ind<<1)|1;
  if (l>r) return;
  else if (tl==l and tr==r){
    t[ind]+=subtract;
    lazy[ind]+=subtract;
  }else{
    push(ind);
    int mid=(tl+tr)>>1;
    update(lc,tl,mid,l,min(mid,r),subtract);
    update(rc,mid+1,tr,max(mid+1,l),r,subtract);
    t[ind]=max(t[lc],t[rc]);
  }
}

int queryMax(int ind,int tl,int tr,int l,int r){
  if (l>r) return -inf;
  else if (tl<=l and tr<=r){
    return t[ind];
  }else{
    push(ind);
    int mid=(tl+tr)>>1;
    return max(queryMax(ind*2,tl,mid,l,min(mid,r)),
              queryMax(ind*2+1,mid+1,tr,max(mid+1,l),r));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  int ans=INT_MIN,pos=1;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=m;i++) cin>>le[i]>>ri[i];
  
  build(1,1,n);
  
  // for (int i=1;i<=n*2;i++){
  //   cout<<i<<": "<<t[i]<<"\n";
  // }
  
  for (int i=1;i<=n;i++){
    int cnt=0;
    for (int j=1;j<=m;j++){
      if (le[j]<=i and i<=ri[j]){
        cnt++;
      }
      if (i==le[j]) update(1,1,n,le[j],ri[j],-1);
      if (i==ri[j]+1) update(1,1,n,le[j],ri[j],1);
    }
    
    int maxNum=queryMax(1,1,n,1,n);
    int minNum=ary[i]-cnt;
    
    // for (int j=1;j<=n;j++) cout<<t[j]<<" ";
    // cout<<"\n";
    // cout<<maxNum<<" "<<minNum<<"\n";
    int temp=maxNum-minNum;
    if (ans<temp){
      ans=temp;
      pos=i;
    }
    // for (int j=1;j<=m;j++){
    //   if (le[j]<=i and i<=ri[j]){
    //     update(1,1,n,le[j],ri[j],1);
    //   }
    // }
  }
  
  int seg=0;
  cout<<ans<<"\n";
  for (int i=1;i<=m;i++){
    if (le[i]<=pos and pos<=ri[i]){
      check[i]=1;
      seg++;
    }
  }
  cout<<seg<<"\n";
  for (int i=1;i<=m;i++){
    if (check[i]) cout<<i<<" ";
  }
  return 0; 
}
