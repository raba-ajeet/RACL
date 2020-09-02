const int N=5*(1e5)+10;
int par[N],ran[N];
void make_set(int n){
    for(int i=0;i<n;i++) par[i]=i,ran[i]=0;
}
int find_set(int u){
    if(par[u]==u) return u;
    return par[u]=find_set(par[u]);
}
void union_set(int u,int v){
    int x=find_set(u);
    int y=find_set(v);
    if(x==y) return ;
    if(ran[x]<ran[y]) swap(x,y);
    par[y]=x;
    if(ran[x]!=ran[y]) ran[x]++;
}
