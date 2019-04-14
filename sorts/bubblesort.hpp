void bubbleSort(vector<int>* arr, const int n){
   bool swapped;
   for (int i = 0; i < n-1; i++){
     swapped = false;
     for (int j = 0; j < n-i-1; j++){
        if (arr->at(j) > arr->at(j+1)){
           swap(arr->at(j), arr->at(j + 1));
           swapped = true;
        }
     }

     if (swapped == false)
        break;
   }
}