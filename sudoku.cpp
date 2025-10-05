#include<bits/stdc++.h>
#define int long long

using namespace std;

int s[15][15];
vector<pair<int,int>> slot;
int status = false;
int cube[15][15];

bool check(int d, int c, int value){
	for (int i=0;i<9;i++){
		if (s[d][i] == value && s[d][i] != 0)
			return false;
		if (s[i][c] == value && s[i][c] != 0)
			return false;
	}
	int index = cube[d][c];
	if (index == 1){
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 2){
		for (int i=0;i<3;i++){
			for (int j=3;j<6;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 3){
		for (int i=0;i<3;i++){
			for (int j=6;j<9;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 4){
		for (int i=3;i<6;i++){
			for (int j=0;j<3;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 5){
		for (int i=3;i<6;i++){
			for (int j=3;j<6;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 6){
		for (int i=3;i<6;i++){
			for (int j=6;j<9;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 7){
		for (int i=6;i<9;i++){
			for (int j=0;j<3;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 8){
		for (int i=6;i<9;i++){
			for (int j=3;j<6;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	if (index == 9){
		for (int i=6;i<9;i++){
			for (int j=6;j<9;j++){
				if (s[i][j] == value && s[i][j] != 0)
					return false;
			}
		}
	}
	return true;
}

bool BT(int cur){
	if (cur == slot.size()){
		return true;
	}
	pair<int,int> val = slot[cur];
	
	for (int i=1;i<=9;i++){
		
		if (check(val.first, val.second, i) == true){
			s[val.first][val.second] = i;
			bool res = BT(cur+1);
			if (res == true){
				return true;
			}
			s[val.first][val.second] = 0;
		}
	}
	return false;
}

signed main(){
	int d,c;
	d = 9;
	c = 9; 
	int index = 0;
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				cube[i][j] = 1;
			}
		}
		for (int i=0;i<3;i++){
			for (int j=3;j<6;j++){
				cube[i][j] = 2;
			}
		}
		for (int i=0;i<3;i++){
			for (int j=6;j<9;j++){
				cube[i][j] = 3;
			}
		}
		for (int i=3;i<6;i++){
			for (int j=0;j<3;j++){
				cube[i][j] = 4;
			}
		}
		for (int i=3;i<6;i++){
			for (int j=3;j<6;j++){
				cube[i][j] = 5;
			}
		}
		for (int i=3;i<6;i++){
			for (int j=6;j<9;j++){
				cube[i][j] = 6;
			}
		}
		for (int i=6;i<9;i++){
			for (int j=0;j<3;j++){
				cube[i][j] = 7;
			}
		}
	
		for (int i=6;i<9;i++){
			for (int j=3;j<6;j++){
				cube[i][j] = 8;
			}
		}
	
		for (int i=6;i<9;i++){
			for (int j=6;j<9;j++){
				cube[i][j] = 9;
			}
		}
	
	for (int i=0;i<d;i++){
		for (int j=0;j<c;j++){
			cin>>s[i][j];
			if (s[i][j] == 0){
				slot.push_back({i,j});
			}
			
		}
	}
	
	bool res = BT(0);
	//cout<<"\n===============================\n";
	for (int i=0;i<d;i++){
		for (int j=0;j<c;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<"\n";
	}
	//cout<<res;
}
