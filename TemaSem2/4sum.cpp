#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
int nrAparitii(vector<int> v, int n, int s){
	int st = 0, dr = n-1, mid;
	while(st <= dr){
		mid = (st + dr) / 2;
		if(v[mid] < s){
			st = mid+1;
		}
		else if(v[mid] > s){
			dr = mid-1;
		}
		else if(v[mid] == s){
			break;
		}
	}
	int i = mid, count = 0;
	while(i >= 0){
		if(v[i] != s)
			break;
		count++;
		i--;
	}
	i = mid + 1;
	while(i < n){
		if(v[i] != s)
			break;
		count++;
		i++;
	}
	return count;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	vector<int> tmp1;
	unordered_map<int,int> frecv;
	int count = 0;
	for(int i = 0; i < nums1.size(); ++i){
		for(int j = 0; j < nums1.size(); ++j){
			tmp1.push_back(nums1[i] + nums2[j]);
		}
	}
	for(int i = 0; i < nums1.size(); ++i){
		for(int j = 0; j < nums1.size(); ++j){
			frecv[nums3[i] + nums4[j]]++;
		}
	}
	
	for(int i = 0; i < tmp1.size(); ++i){
			count += frecv[-tmp1[i]];
	}
	return count;
}
}ob1;

int main(){
	vector <int> n1,n2,n3,n4;
	/*n1.push_back(1);
	n1.push_back(2);
	n2.push_back(-2);
	n2.push_back(-1);
	n3.push_back(-1);
	n3.push_back(2);
	n4.push_back(0);
	n4.push_back(2);*/
	n1.push_back(0);
	n2.push_back(0);
	n3.push_back(0);
	n4.push_back(0);
	cout << ob1.fourSumCount(n1,n2,n3,n4);
}