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
int ary[100000],d[100000],used[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i],d[ary[i]]++;
  
  for (int i=1;i<=n;i++){
    int check=1,x=0,y=0,out=0;
    for (int j=1;j<=n;j++){
      x=0,y=0;
      check=1;
      memset(used,0,sizeof(used));
      for (int k=1;k<=n;k++){
        if (d[ary[k]]==2){
          if (!used[ary[k]]){
            used[ary[k]]=1;
            if ((ary[i]%ary[k]) or (ary[j]%ary[k])){
              check=0;
              break;
            }else{
              x++;
              y++;
            }
          }
        }else{
          if ((ary[i]%ary[k]) and (ary[j]%ary[k])){
            check=0;
            break;
          }else{
            if (ary[i]%ary[k]==0) x++;
            else y++;
          }
        }
      }
      
      int tempx=0,tempy=0;
      for (int k=1;k<=ary[i];k++){
        if (ary[i]%k==0) tempx++;
      }
      for (int k=1;k<=ary[j];k++){
        if (ary[j]%k==0) tempy++;
      }
      // cout<<ary[i]<<" "<<ary[j]<<": "<<x<<" "<<y<<"\n";
       
      if (check and (x+y==n) and tempx==x and tempy==y){
        cout<<ary[i]<<" "<<ary[j];
        out=1;
        break;
      }
    }
    if (check and out) break;
  }
  return 0; 
}
