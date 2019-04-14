void fillvectors(vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7, vector<int>* v8, vector<int>* v9, vector<int>* v10, const int n, const int r1, const int r2){
	default_random_engine e(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distr(r1,r2);
	auto rnd = bind(distr,e);

	for(int i=0; i<n; i++){
		v1->at(i) = rnd();
		v2->at(i) = v1->at(i);
		v3->at(i) = v1->at(i);
		v4->at(i) = v1->at(i);
		v5->at(i) = v1->at(i);
		v6->at(i) = v1->at(i);
		v7->at(i) = v1->at(i);
		v8->at(i) = v1->at(i);
		v9->at(i) = v1->at(i);
		v10->at(i) = v1->at(i);
	}
}