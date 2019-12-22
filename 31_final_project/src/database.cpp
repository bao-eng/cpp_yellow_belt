#include "database.h"

void Database::Add(const Date date, string event){
	if( db[date].ev_set.insert(event).second ){
		db[date].ev_vect.push_back(event);
	}
}

void Database::Print(ostream& stream) const{
	for(const auto& i: db){
		for(const auto& j: i.second.ev_vect){
			stream << i.first << " " << j << endl;
		}
	}
}

int Database::RemoveIf(const function<bool(const Date&, const string&)> lambda){
	int rem_count=0;
	auto i = db.begin();
	while (i != db.end()){
		for(auto j=i->second.ev_vect.begin(); j!=i->second.ev_vect.end(); j++){
			if(lambda(i->first, *j)){
				i->second.ev_set.erase(*j);
				*j="";
				rem_count++;
			}
		}
		auto it = stable_partition(i->second.ev_vect.begin(), i->second.ev_vect.end(),
		[](string str){return !str.empty();});
		i->second.ev_vect.erase(it,i->second.ev_vect.end());
		if(i->second.ev_vect.size()==0){
			i = db.erase(i);
		}else {
			++i;
		}
	}
	return rem_count;
}

vector<event> Database::FindIf(const function<bool(const Date&, const string&)> lambda) const{
	vector<event> v;
	for(auto i=db.begin();i!=db.end();i++){
		for(auto j=i->second.ev_vect.begin();j!=i->second.ev_vect.end();j++){
			if(lambda(i->first, *j)){
				v.push_back({i->first,*j});
			}
		}
	}
	return v;
}

event Database::Last(Date date) const{
	auto it=db.upper_bound (date);
	if(it==db.begin()){
		throw invalid_argument("");
	}else{
		it--;
	}
	return {it->first,it->second.ev_vect[it->second.ev_vect.size()-1]};
}

ostream& operator << (ostream& stream, const event& event) {
	stream << event.date << " " << event.str;
	return stream;
}

bool operator != (const event& lhs, const event& rhs) {
	return lhs.date!=rhs.date && lhs.str != rhs.str;
}
