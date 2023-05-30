#include <bits/stdc++.h>
using namespace std;

int t,l;
string com;
char ch;
char i;
string x,y;
struct{
	char type;
	char i;
	string x,y;
}sto[100];
int len;

void f(){
	stack<array<int,2>>vars;//i & max exponentiality
	vars.push({-1,0});
	unordered_set<char>seen;
	for(int j=0;j<len;++j){
		if(sto[j].type=='F'){
			if(seen.count(sto[j].i)){
				cout<<"ERR\n";
				return;
			}
			vars.push({j,0});
			seen.insert(sto[j].i);
		}else{
			int k=vars.top()[0];
			seen.erase(sto[k].i);
			int tmp=vars.top()[1];
			if(sto[k].y=="n"){
				tmp+=sto[k].x!="n";
			}else if(sto[k].x=="n"||stoi(sto[k].x)>stoi(sto[k].y)){
				tmp=0;
			}
			vars.pop();
			
			vars.top()[1]=max(vars.top()[1],tmp);
		}
	}
	int exp=vars.top()[1];
	if(exp){
		cout<<(com==("O(n^"+to_string(exp)+")")?"Yes":"No");
	}else{
		cout<<(com=="O(1)"?"Yes":"No");
	}
	cout<<'\n';
} 

int main()
{
	cin>>t;
	while(t--){
		cin>>l>>com;
		int bal=0,err=0;
		len=0;
		for(int j=0;j<l;++j){
			cin>>ch;
			if(ch=='F'){
				cin>>i>>x>>y;
				sto[len++]={'F',i,x,y};
				++bal;
			}else{
				sto[len++]={'E',0,"",""};
				--bal;
			}
			if(bal<0){
				err=1;
			}
		}
		if(err||bal){
			cout<<"ERR\n";
			continue;
		}
		f();
	}
    return 0;
}
