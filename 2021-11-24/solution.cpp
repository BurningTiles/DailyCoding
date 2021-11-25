#include <bits/stdc++.h>
using namespace std;

bool valid(string s){
	if(s[0]=='0') return (s.size()==1 ? true : false);
	if(s.size()==1) return true;
	if(s.size()==2) return (s>="10" && s<="99");
	if(s.size()==3) return (s>="100" && s<="255");
	return false;
}

vector<string> ip_addresses(string s){
	vector<string> ans;
	if(s.size()<4 || s.size()>12) return ans;
	string p1, p2, p3, p4;
	for(int i=1; i<4 && i<s.size(); i++){
		p1 = s.substr(0, i);
		if(valid(p1)){
			for(int j=i+1; j<i+4 && j<s.size(); j++){
				p2 = s.substr(i, j-i);
				if(valid(p2)){
					for(int k=j+1; k<j+4 && k<s.size(); k++){
						p3 = s.substr(j, k-j);
						if(valid(p3)){
							p4 = s.substr(k);
							if(valid(p4))
								ans.push_back(p1+"."+p2+"."+p3+"."+p4);
						}
					}
				}
			}
		}
	}
	return ans;
}

void print(vector<string> v){
	cout << "[";
	for(int i=0; i<v.size(); i++)
		cout << v[i] << (i==v.size()-1 ? "" : ", ");
	cout << "]\n";
}

signed main() {
	print(ip_addresses("1592551013"));
	return 0;
}