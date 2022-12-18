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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int l1,l2,r1,r2,num1,num2;
  cin>>n;
  for (int i=1;i<=n;i++){
    num1=num2=-1;
    cin>>l1>>r1>>l2>>r2;
    cout<<l1<<" ";
    if (l1==l2) cout<<l1+1<<"\n";
    else cout<<l2<<"\n";
  }
  return 0; 
}
