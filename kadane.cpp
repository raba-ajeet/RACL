int solve(int a[],int n){
  int best_sum=a[0];
    int curr=a[0];
    fir(i,1,n){
        curr=max(a[i],a[i]+curr);
        best_sum=max(best_sum,curr);
    }
    return best_sum;
}
