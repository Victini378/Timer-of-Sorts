void merge(vector<int>* a, const int left, const int center, const int right) {
	vector<int> aux (right+1);
	int i,j;
	for (i = center+1; i > left; i--)
		aux[i-1] = a->at(i-1);
	for (j = center; j < right; j++)
		aux[right+center-j] = a->at(j + 1);
	for (int k = left; k <= right; k++)
		if (aux[j] < aux[i])
			a->at(k) = aux[j--];
		else
			a->at(k) = aux[i++];
}

void mergeSort(vector<int>* a, const int left, const int right) {
	if (left<right) {
		int center = (left+right)/2;
		mergeSort(a, left, center);
		mergeSort(a, center+1, right);
		merge(a, left, center, right);
	}
}