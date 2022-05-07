#include <bits/stdc++.h>

#define FILE "zeap"
#define type  pair<int,pair<int,int>>

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

priority_queue<type, vector<type>, greater<type> > pq;
set<int> s;

int main(){
	char c;
	int x;
	while(fin >> c){
		if(c == 'I'){
			fin >> x;
			s.insert(x);
			set<int>::iterator it = s.find(x);
			if(it != s.begin()){
				--it;
				pq.push({x-*it,{*it, x}});
				++it;
			}
			if(++it != s.end()){
				pq.push({*it -x,{*it, x}});
			}
		}
		if(c == 'S'){
			fin >> x;
			if(s.find(x) != s.end()){
				set<int>::iterator it = s.find(x);
				set<int>::iterator it1 = ++it;
				--it;
				set<int>::iterator it2 = --it;
				pq.push({*(it1) - *(it2), {*(it1), *(it2)}});
				s.erase(x);
			}
			else{
				fout << -1 << '\n';
			}
		}
		if(c == 'C'){
			fin >> x;
			if(s.find(x) == s.end())
				fout << 0 << '\n';
			else
				fout << 1 << '\n';
		}
		if(c == 'M'){
			fin >> c;
			fin >> c;
			if(c == 'N'){
				while(!pq.empty() && (s.find(pq.top().second.first) == s.end() || s.find(pq.top().second.second) == s.end())){
					pq.pop();
				}
				fout << pq.top().first << '\n'; 
			}
			if(c == 'X'){
				if(s.size() < 2)
					fout << -1 << '\n';
				fout << *(--s.end()) - *(s.begin()) << '\n';
			}
		}
	}
	return 0;
}