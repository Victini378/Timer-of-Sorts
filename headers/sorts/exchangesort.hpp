void exchangeSort(vector<int>* v, const int n){
	for(int i=0; i<n-1; i++)
		for(int j=i; j<n; j++)
			if(v->at(i)>v->at(j))
				swap(v->at(i), v->at(j));
}