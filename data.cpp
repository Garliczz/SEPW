#include<bits/stdc++.h>
using namespace std;
#define int long long

int times=20;

struct Student{
	
	int index,absence,state;
	
	bool operator<(const Student &it)const{
		return absence>it.absence;
	}
	
}; 

int rd(int R){
	return ((rand()<<12)%R+rand())%R;
}

int rd_(int R){
	int x=((rand()<<12)%R+rand())%R;
	if(rd(1e6)&1)x = -x;
	return x;
}

vector<Student>vec;
bool vis[1000];

signed main(){
	srand(time(0));
	int n=90,top=times*10;
	Student st={0,-1,0};
	for(int i=1;i<=n;i++){
		st.index = i;
		vec.push_back(st);
	}
	int absence_num=5+rd(4);
	set<int>s;
	while(s.size()<absence_num)
		s.insert(rd(n)+1);
	while(!s.empty()){
		int idx=(*s.begin())-1;s.erase(s.begin());
		vec[idx].absence = min((int)(times*(0.8)+rd_(3)), top);
		top -= vec[idx].absence;
		vis[idx+1] = true;
	}
	for(int i=0;i<vec.size();i++){
		if(vec[i].absence!=-1)continue;
		vec[i].absence = min(rd(times*0.3), top);
		top -= vec[i].absence; 
	}
	int now_absence=rd(4);
	int out=0,in=now_absence;
	int tmp=rd(100);
	if(now_absence==1){
		if(tmp<10){out = 1;in = 0;}
	}
	else if(now_absence==2){
		if(tmp<5){out = 2;in = 0;}
		else if(tmp<10){out = in = 1;}
	}
	else if(now_absence==3){
		if(tmp<3){out = 3;in = 0;}
		else if(tmp<10){out = 2;in = 1;}
		else if(tmp<20){out = 1;in = 2;}
	}
	vector<int>veci,veco;
	for(int i=1;i<=n;i++)
		if(vis[i])veci.push_back(i);
		else veco.push_back(i);
	random_shuffle(veci.begin(), veci.end());
	random_shuffle(veco.begin(), veco.end());
	for(int i=0;i<in;i++)
		vec[veci[i]-1].state = 1;
	for(int i=0;i<out;i++)
		vec[veco[i]-1].state = 1;
	for(int i=0;i<vec.size();i++)
		printf("%d %d %d\n",vec[i].index,vec[i].absence,vec[i].state);
	return 0;
}
