#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
  typedef long long int ll;
  ll n;
  int count = 0;
  cin >> n;
  for(int i = 2; i * i <= n; i++)
  {
    while(n % i == 0)
    {
      n /= i;
      count++;
    }
  }
  if(n != 1)
  {
    count++;
  }
  cout << count << endl;
	return 0;
}

