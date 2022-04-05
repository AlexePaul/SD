#include <stack>
#include <fstream>
#define FILE "paranteze"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

int n;
stack< pair<char,int> > s;
char c;
int count;
int maxCount = -1;
int mx = 0;

int main(){
	fin >> n;
	s.push({'c',0});
	for(int i = 0; i < n; ++i){
		fin >> c;
		if(c == '(' || c == '[' || c=='{')
			s.push({c, i});
		else if(!s.empty()){
			if(s.top().first == '(' && c == ')')
				s.pop();
			else if(s.top().first == '[' && c == ']')
				s.pop();
			else if(s.top().first == '{' && c == '}')
				s.pop();
			else
				s.push({c,i});
			mx = max(mx, i-s.top().second);
		}
	}
	fout << mx;
}