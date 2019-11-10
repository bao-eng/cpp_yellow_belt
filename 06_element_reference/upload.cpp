template<typename key, typename value>
value& GetRefStrict(map<key, value>& m,key k){
	if(m.count(k)==1){
		return m[k];
	}
	throw runtime_error("");
}
