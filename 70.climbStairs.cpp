#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
public:
  int climbStairs(int n){
    int p = 0, q = 0, r = 1;
    for (int i=1; i <=n; ++i){
      p = q;
      q = r;
      r = p + q;
      
    }
    return r;

  }

};
int main()
{
  int n = 3;
  Solution ss;
  int ret = 0;
  ret = ss.climbStairs(n);
  cout << ret << endl;
  return 0;
  
}
