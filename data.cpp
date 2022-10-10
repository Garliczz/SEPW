#include<bits/stdc++.h>
using namespace std;
#define int long long

int times=20;

//记录每个学生的编号，历史缺席次数，本次课是否缺席
struct Student{
	
	int index,absence,state;
	
    //基于历史缺席次数进行排序：缺席越多越应该被点到
	bool operator<(const Student &it)const{
		return absence>it.absence;
	}
	
}; 

//随机生成0~R-1的自然数
int rd(int R){
	return ((rand()<<12)%R+rand())%R;
}

//随机生成-R+1~R-1的整数
int rd_(int R){
	int x=((rand()<<12)%R+rand())%R;
	if(rd(1e6)&1)x = -x;
	return x;
}

//存放学生数据
vector<Student>vec;
//记录是否为那5~8名同学
bool vis[1000];

signed main(){
	srand(time(0));
    //设置课堂人数，以及历史缺勤次数总和上限
	int n=90,top=times*10;
	Student st={0,-1,0};
    //读入学生数据
	for(int i=1;i<=n;i++){
		st.index = i;
		vec.push_back(st);
	}
    //随机缺席80%课程的人数
	int absence_num=5+rd(4);
	set<int>s;
    //随机具体的编号
	while(s.size()<absence_num)
		s.insert(rd(n)+1);
    //设置这部分人的历史缺勤次数
	while(!s.empty()){
		int idx=(*s.begin())-1;s.erase(s.begin());
        //标准：基于20*0.8并有-2~2的浮动（总缺勤次数不能超过top）
		vec[idx].absence = min((int)(times*(0.8)+rd_(3)), top);
		top -= vec[idx].absence;
        //标记该学生
		vis[idx+1] = true;
	}
    //随机生成剩下的人的缺勤次数
	for(int i=0;i<vec.size();i++){
		if(vec[i].absence!=-1)continue;
		vec[i].absence = min(rd(times*0.3), top);
		top -= vec[i].absence; 
	}
    //随机生成本次课缺席人数0~3
	int now_absence=rd(4);
    //in,out表示5～8人内/外
	int out=0,in=now_absence;
	int tmp=rd(100);
    //分类讨论缺席人数的分布情况
    //总缺席人数为1时:1/0(90%),0/1(10%)
	if(now_absence==1){
		if(tmp<10){out = 1;in = 0;}
	}
    //总缺席人数为2时:2/0(90%),1/1(5%),0/2(5%)
	else if(now_absence==2){
		if(tmp<5){out = 2;in = 0;}
		else if(tmp<10){out = in = 1;}
	}
    //总缺席人数为3时:3/0(80%),2/1(10%),1/2(7%),0/3(3%)
	else if(now_absence==3){
		if(tmp<3){out = 3;in = 0;}
		else if(tmp<10){out = 2;in = 1;}
		else if(tmp<20){out = 1;in = 2;}
	}
    //将缺席最多的5~8人分离出来
	vector<int>veci,veco;
	for(int i=1;i<=n;i++)
		if(vis[i])veci.push_back(i);
		else veco.push_back(i);
    //随机打乱两部分学生
	random_shuffle(veci.begin(), veci.end());
	random_shuffle(veco.begin(), veco.end());
    //各自设置本次课是否缺席
	for(int i=0;i<in;i++)
		vec[veci[i]-1].state = 1;
	for(int i=0;i<out;i++)
		vec[veco[i]-1].state = 1;
    //输出学生名单
	for(int i=0;i<vec.size();i++)
		printf("%d %d %d\n",vec[i].index,vec[i].absence,vec[i].state);
	return 0;
}
