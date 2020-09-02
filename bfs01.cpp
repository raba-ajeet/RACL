int dis[N],par[N];
int bfs01(int st,int en,int n){
    for(int i=0;i<n;i++) dis[i]=1e9,par[i]=-1;
    dis[st]=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(auto u:adj[s]){
            if(dis[u]>dis[s]+1){
                dis[u]=dis[s]+1;
                par[u]=s;
                q.push(u); 
            }
        }
    }
    if(par[en]==-1)  return -1;
    else{
        // for adding more 
        return dis[en];
    }
}
