#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime> 
using namespace std;



template <typename InIt> void myfunction(InIt str) {
	cout<<str<<" ";
}


struct myclass {           // function object type:
	template <typename InIt> void operator() (InIt i) {
		cout << i << " ";
	}
} myobject;


class Solution {
public:
	void Smallfork(int A[], int length, int k) {
		int first = 0, last = length - 1;
		int inode = partion(A, first, last);
		while (inode != k - 1) {
			if (inode > k -1)
			{
				last = inode - 1;
				inode = partion(A, first, last);
			} 
			else
			{
				first = inode + 1;
				inode = partion(A, first, last);
			}
		}

		for_each(A, A + k, myobject);
        for_each(A, A+k, myfunction);

	}
	int partion(int A[], int first, int last) {
		srand(time(0));
		int irand = first + rand()%(last-first);
		swap(A[irand], A[last]);
		int small = first - 1;
		int index = first;
		for (; index != last; index++) {
			if (A[index] < A[last]) {
				small++;
				if (small != index){
					swap(A[small], A[index]);
				}
			}
			/*if (A[index] >= A[last]) {
				continue;
			}
			else {
				small++;
				if (small != index){
					swap(A[small], A[index]);
				}
			}*/
		}
		small++;
		swap(A[small], A[last]);
		return small;
	}
};



int main(void)
{
	Solution s;
	int A[8] = {4,5,1,6,2,7,3,8};
	s.Smallfork(A, 8, 4);
	return 0;
}

