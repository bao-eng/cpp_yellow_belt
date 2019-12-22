void PrintStats(vector<Person> persons){
	//female_employed / female_unemployed / male_employed / male_unemployed
	auto fm = partition (persons.begin(), persons.end(), [](Person p){return p.gender==Gender::FEMALE;});
	auto f_empl = partition (persons.begin(), fm, [](Person p){return p.is_employed==true;});
	auto m_empl = partition (fm, persons.end(), [](Person p){return p.is_employed==true;});

	cout << "Median age = "                        << ComputeMedianAge(persons.begin(),persons.end()) << endl;
	cout << "Median age for females = " 		   << ComputeMedianAge(persons.begin(),fm) << endl;
	cout << "Median age for males = " 			   << ComputeMedianAge(fm,persons.end()) << endl;
	cout << "Median age for employed females = "   << ComputeMedianAge(persons.begin(),f_empl) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(f_empl,fm) << endl;
	cout << "Median age for employed males = "     << ComputeMedianAge(fm,m_empl) << endl;
	cout << "Median age for unemployed males = "   << ComputeMedianAge(m_empl,persons.end()) << endl;

}
