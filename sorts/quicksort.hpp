void quickSort(vector<int>* vet, const int m, const int n){
    int i, j;
    if(m < n){
        swap(vet->at(m), vet->at((m + n) / 2));
        i = m+1;
        j = n;
        while(i <= j){
            while((i <= n) && (vet->at(i) <= vet->at(m)))
                i++;
            while((j >= m) && (vet->at(j) > vet->at(m)))
                j--;
			if (i < j)
				swap(vet->at(i), vet->at(j));
        }

        swap(vet->at(m),vet->at(j));

        quickSort(vet,m,j-1);
        quickSort(vet,j+1,n);
    }
}

void quickSortIterative(vector<int>* a, const int n){
	stack<pair<int, int>> stk;

	int start = 0;
	int end = n - 1;

	stk.push(make_pair(start, end));

	while (!stk.empty()){
		start = stk.top().first, end = stk.top().second;
		stk.pop();

		int pivot = a->at(end);

        int pIndex = start;

        for (int i = start; i < end; i++){
            if (a->at(i) <= pivot){
                swap(a->at(i), a->at(pIndex));
                pIndex++;
            }
        }

        swap (a->at(pIndex), a->at(end));
		pivot = pIndex;

		if (pivot - 1 > start){
			stk.push(make_pair(start, pivot - 1));
		}

		if (pivot + 1 < end){
			stk.push(make_pair(pivot + 1, end));
		}
	}
}