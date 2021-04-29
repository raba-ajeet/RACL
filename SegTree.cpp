int a[200001],b[200001];
int seg[4*N],lazy[4*N];
int build(int s,int e,int i){
    if(s==e) {
        seg[i]=a[s];
        lazy[i]=0;
        return seg[i];
    }
    int m=s+(e-s)/2;
    seg[i]=build(s,m,2*i)+build(m+1,e,2*i+1);
    lazy[i]=0;
    return seg[i];
}
void upd(int s=0,int e=N-1,int i,int idx,int val){
    if(s==e) {
        seg[i]=val;
        a[idx]=val;
        return;
    }
    int m=s+(e-s)/2;
    if(idx<=m){
        upd(s,m,2*i,idx,val);
    }
    else upd(m+1,e,2*i+1,idx,val);
    seg[i]=seg[2*i]+seg[2*i+1];
}
//! lazy upd
void lupd(int s,int e,int i,int x){
    lazy[i]+=x;
    seg[i]+=(e-s+1)*x;
}
void shift(int s,int e,int i){
        int m=s+(e-s)/2;
        lupd(s,m,2*i,lazy[i]);
        lupd(m+1,e,2*i+1,lazy[i]);
        lazy[i]=0;
}
void rupd(int s,int e,int i,int l,int r,int val){
    if(s>r || l>e) return ;
    if(l<=s && r>=e){
        lupd(s,e,i,val);
        return;
    }
    shift(s,e,i);
    int m=s+(e-s)/2;
    rupd(s,m,2*i,l,r,val);
    rupd(m+1,e,2*i+1,l,r,val);
    seg[i]=seg[2*i]+seg[2*i+1];
}
//! upto here 
int query(int s,int e,int l,int r,int i){
    if(s>r || l>e){
        return 0;
    }
    if(l<=s && r>=e) return seg[i];
    shift(s,e,i);
    int m=s+(e-s)/2;
    return query(s,m,l,r,2*i)+query(m+1,e,l,r,2*i+1);
}
