#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>

using namespace std;

typedef pair<double, double> ans;

ans solve(int d)
{
  double temp1 = pow(d, 2) / 4.0;
  if(temp1 < double(d))
  {
    return {-1, -1};
  }else{
    double a = sqrt(temp1 - d) + d * 0.5;
    double b = 0.0;
    if(a != 0.0) {
      b = d / a;
    }
    return {a, b};
  }
}

int main()
{
  int t;
  cin >> t;
  vector<int> d(t);
  for(int i = 0; i < t; i++)
  {
    cin >> d[i];
  }
  for(int i = 0; i < t; i++)
  {
    ans result = solve(d[i]);
    if(result.first == -1 && result.second == -1)
    {
      cout << "N" << endl;
    }else{
      cout << fixed << setprecision(9);
      cout << "Y " << result.first << " " << result.second << endl;
    }
  }
  return 0;
}

