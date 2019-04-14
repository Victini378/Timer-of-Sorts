void selectionSort(vector<int>* arr){
	unsigned int i, j, min_idx;
	unsigned int size = arr->size();

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < size - 1; i++){
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (arr->at(j) < arr->at(min_idx))
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(arr->at(min_idx), arr->at(i));
	}
}