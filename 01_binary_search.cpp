#include <iostream>
#include <unordered_map>

// 二叉查找

using namespace std;

class Slotion{
public:
  int binarySearch(int a[100], int x){
      int left = 0;
      int right = x - 1;
      while(left <= right){
	  int mid = (left+right) / 2;
	  if(a[mid]==x){
	    return mid;
	  }
	  else if(a[mid] > x){
	    right = mid - 1; //待查找的值在区间左侧
	  }
	  else{
	    left = mid + 1; //待查找的值在区间右侧
	  }
	}
      return -1; //未找到
  }
};

int main(){
  int a[100] = {4,10,11,30,69,70,96,100};
  Slotion ss;
  int ret = 0;
  ret = ss.binarySearch(a,30);
  cout <<"结果：" <<ret<< endl;
}
