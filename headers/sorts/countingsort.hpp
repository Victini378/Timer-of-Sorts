void countingSort(vector<int>* arr) {
    const int max = *max_element(arr->begin(), arr->end());
    const int min = *min_element(arr->begin(), arr->end());
    const int range = max - min + 1;

    vector<int> count(range), output(arr->size());
    for(unsigned int i = 0; i < arr->size(); i++)
        count[arr->at(i)-min]++;

    for(unsigned int i = 1; i < count.size(); i++)
           count.at(i) += count[i-1];

    for(int i = arr->size()-1; i >= 0; i--){
         output[ count[arr->at(i)-min] -1 ] = arr->at(i);
              count[arr->at(i)-min]--;
    }

    for(unsigned int i=0; i < arr->size(); i++)
            arr->at(i) = output.at(i);
}

void countingSort(vector<int>* arr, const int min, const int max) {
    const int range = max - min + 1;

    vector<int> count(range), output(arr->size());
    for(unsigned int i = 0; i < arr->size(); i++)
        count[arr->at(i)-min]++;

    for(unsigned int i = 1; i < count.size(); i++)
           count.at(i) += count[i-1];

    for(int i = arr->size()-1; i >= 0; i--){
         output[ count[arr->at(i)-min] -1 ] = arr->at(i);
              count[arr->at(i)-min]--;
    }

    for(unsigned int i=0; i < arr->size(); i++)
            arr->at(i) = output.at(i);
}