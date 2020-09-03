int vis[N];
int ok=1;
void dfs(int s,int c){
    vis[s]=c;
    c=1-c;
    for(auto u:adj[s]){
        if(vis[u]==-1){
            dfs(u,c);
        }
        else if(vis[u]!=c) ok=0;
    } 
}
void dfs_call(int n){
    for(int i=0;i<n;i++){
        if(vis[i]!=-1) continue;
        dfs(i,0);
    }
}
