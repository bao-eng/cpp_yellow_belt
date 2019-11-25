bool operator<(const Region& lhs, const Region& rhs){
	if(tie(lhs.std_name,lhs.parent_std_name,lhs.names,lhs.population)<
			tie(rhs.std_name,rhs.parent_std_name,rhs.names,rhs.population)){
		return true;
	}
	return false;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
	int max=0;
	if(regions.size()!=0){
		map<Region,int> tmp;
		for(auto i: regions){
			++tmp[i];
			if(tmp[i]>max){
				max=tmp[i];
			}
		}
		return max;
	}else{
		return 0;
	}
}
