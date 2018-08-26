// segment tree finding the min query problem


#include<bits/stdc++.h>
using namespace std;

 // build the segment tree
 void build(int *segtree,int *a,int low,int high , int pos)
 {
     if(low==high)
     {
         segtree[pos]=a[low];

     }
    else{
            int mid=(low+high)/2;
     build(segtree,a,low,mid,2*pos+1);
     build(segtree,a,mid+1,high,2*pos+2);

     segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }

 }

// query
int  query(int * segtree,int low,int high,int l,int r,int pos)
{
    if(l<=low && r>=high)
        return segtree[pos];
    if(l>high || r<low)
        return 1000000;

    int mid=(low+high)/2;
    return min(query(segtree,low,mid,l,r,2*pos+1),query(segtree,mid+1,high,l,r,2*pos+2));
}

// update
void update(int *segtree,int * a,int low,int high,int index,int value,int pos)
{
    if(low==high)
    {
        a[index]=value;
        segtree[pos]=value;
    }
    else{
        int mid=(low+high)/2;
        if(index>=low && index<=mid)
        update(segtree,a,low,mid,index,value,2*pos+1);
        else
        update(segtree,a,mid+1,high,index,value,2*pos+2);

        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
int main()
{
    int n,q;
    int segtree[1000000];
    cin>>n>>q;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

        build(segtree,a,0,n-1,0);

       // for(int i=0;i<15;i++)
         //   cout<<segtree[i]<<" ";
    while(q--)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='q')
        {
            cout<<query(segtree,0,n-1,x-1,y-1,0)<<endl;
        }
        if(c=='u')
        {
            update(segtree,a,0,n-1,x-1,y,0);
        }
    }
     //for(int i=0;i<15;i++)
           //cout<<segtree[i]<<" ";
return 0;
}
