int maxz=0;
int dfs(int u,int v){
    int p=0;
    int l=0,r=0;
    for(int s:adj[u]){
        if(s!=v){
            int x=1+dfs(s,u);
            if(l>x){
                if(r<x) r=x;
            }
            else{
                r=l;
                l=x;
            }
            p=max(p,x); 
        }
    }
    maxz=max(l+r,maxz);
    maxz=max(maxz,p);
    return p;
}
