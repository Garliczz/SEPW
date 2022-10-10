#include<bits/stdc++.h>
using namespace std;

struct Student{
	
	int index,absence,state;
	
	bool operator<(const Student &it)const{
		return absence>it.absence;
	}
	
}; 

vector<Student>vec;

int main(){
	Student st;
	while((scanf("%d %d %d",&st.index,&st.absence,&st.state))!=EOF)
		vec.push_back(st);
	sort(vec.begin(), vec.end());
	int lim=8,ask=0,absence=0;
	for(int i=0;i<lim;i++){
		printf("%d %d %d\n",vec[i].index,vec[i].absence,vec[i].state);
		ask++;absence += vec[i].state;
		if(absence>2)break;
	}
	printf("%.6lf%%\n",absence*1.0/ask*100);
	return 0;
}
