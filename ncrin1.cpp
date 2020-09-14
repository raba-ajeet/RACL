const int N=5*(1e5)+10;
int inv[N];
int fac[N];
int invfac[N];
void infac(){
    fac[0]=fac[1]=1;
    for(int i=2;i<N;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
}
void ininv(){
   inv[0]=inv[1]=1;
   for(int i=2;i<N;i++){
       inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
   } 
}
void ininvfac(){
   invfac[0]=invfac[1]=1;
   for(int i=2;i<N;i++){
       invfac[i]=(inv[i]*invfac[i-1])%mod;
   } 
}
int ncr(int n,int r){
    int ans=(((fac[n]*invfac[r])%mod)*invfac[n-r])%mod;
    return ans;
}
int main(){
    infac();
    ininv();
    ininvfac();
}
