int st[N],en[N];
int tim=0;
void dfs(int s,int curr){
    st[s]=tim++;
    for(auto u:adj[s]){
        dfs(u,curr+1);
    }
    en[s]=tim++;
}

// euler path, node visiting time (start time and end time )
