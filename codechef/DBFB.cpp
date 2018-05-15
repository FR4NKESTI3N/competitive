#include <cstdio>
#include <vector>
#include <utility>

const int MOD = 1000000007;

using namespace std;

pair<int, int> fib(int n){
	long long a = 0, b = 1, temp;
	for(int i = 2; i < n; ++i){
		temp = (a + b)%MOD;
		a = b;
		b = temp;
	}
	return make_pair(a, b);
}

int main(){
	int t, m, n, temp;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &n);
		long long a = 0, b = 0;
		for(int i = 0; i < m; ++i){
			scanf("%d", &temp);
			a+=temp;
		}
		for(int i = 0; i < m; ++i){
			scanf("%d", &temp);
			b+=temp;
		}
		a %= MOD;
		b %= MOD;
		long long res = 0;
		if(n == 1)
			res = (m*a)%MOD;
		else if(n == 2)
			res = (m*b)%MOD;
		else{
			pair<int, int> x = fib(n);
			res += (x.first*a)%MOD;
			res += (x.second*b)%MOD;
			res *= m;
			res %= MOD;
		}
		printf("%lld\n", res);
	}
	return 0;
}
