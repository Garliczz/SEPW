#include<bits/stdc++.h>
using namespace std;

//记录每个学生的编号，历史缺席次数，本次课是否缺席
struct Student{
	
	int index,absence,state;
	
    //基于历史缺席次数进行排序：缺席越多越应该被点到
	bool operator<(const Student &it)const{
		return absence>it.absence;
	}
	
}; 

vector<Student>vec;

int main(){
	Student st;
    //读入本次名单数据
	while((scanf("%d %d %d",&st.index,&st.absence,&st.state))!=EOF)
		vec.push_back(st);
    //按照历史缺勤次数排序
	sort(vec.begin(), vec.end());
    //设置抽点次数上界
	int lim=8,ask=0,absence=0;
    //输出抽点名单
	for(int i=0;i<lim;i++){
		printf("%d %d %d\n",vec[i].index,vec[i].absence,vec[i].state);
		ask++;absence += vec[i].state;
        //如果已经点到3人缺席，直接停止
		if(absence>2)break;
	}
    //计算E并输出
	printf("%.6lf%%\n",absence*1.0/ask*100);
	return 0;
}
