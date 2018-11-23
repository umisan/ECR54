#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

typedef long long int ll;

ll find_smallest(ll n)
{
  for(ll i = 2; i * i <= n; i++)
  {
    if(n % i == 0)
    {
      return i;
    }
  }
  return n;
}


int main()
{
  ll n;
  cin >> n;
  ll count = 0;
  if(n % 2 == 0)
  {
    count = n / 2;
  }else{
    ll smallest = find_smallest(n);
    count = 1;
    n -= smallest;
    count += n / 2;
  }
  cout << count << endl;
	return 0;
}

