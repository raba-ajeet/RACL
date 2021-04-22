// prime factors of given number using sieve 
// O(nloglog(n)) for precomputtions 
// now we can simply calculate primes for number in logn 
//  we are using sieve concept and we are just updating the value for number using its smalles prime divsior 
// then for given number we can use that spf and divide the given nuber 
int spf[N];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++) spf[i] = i;
    for (int i=4; i<N; i+=2)  spf[i] = 2;
    for (int i=3; i*i<N; i++){
        if (spf[i] == i){
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int main(){
  int x; cin>>x;
  while(x!=1){
    cout<<spf[x]<<"\n";
    x=spf[x];
  }
}
