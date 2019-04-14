#include "pch.hpp"
#include "main.hpp"

int main(){
	int n, r1, r2;
	bool slowSort = false;

	cout<< "Insert element number of vector: ";
	cin>>n;
	while(n<1){
		cerr<< "Please enter values greater than 0: ";
		cin>>n;
	}

	cout<< "Insert range of numbers of vector: ";
	cin>>r1>>r2;

	cout<< "Do you also want slower sortings? (0, 1): ";
	cin>>slowSort;

	vector<int> *vet1 = new vector<int>(n), *vet2 = new vector<int>(n), *vet3 = new vector<int>(n), *vet4 = new vector<int>(n), *vet5 = new vector<int>(n), *vet6 = new vector<int>(n), *vet7 = new vector<int>(n), *vet8 = new vector<int>(n), *vet9 = new vector<int>(n), *vet10 = new vector<int>(n);

	fillvectors(vet1, vet2, vet3, vet4, vet5, vet6, vet7, vet8, vet9, vet10, n, r1, r2);

	if (slowSort == false) {
		delete vet7, vet8, vet9, vet10;
	}

	system("cls");

	cout<< "Timer of execution of sort: ";
	cout<< "\nInput size: "<<n<<"\tInput range: From "<<r1<<" to "<<r2
		<< "\n\nSorting Algorithm\t\t    time taken(s)";

	auto start = high_resolution_clock::now();

	sort(vet1->begin(), vet1->end());

    auto stop = high_resolution_clock::now();

    duration<long double> duration = stop - start;

    cout << "\nstd::sort: \t\t\t    "
         << duration.count();
	delete vet1;

    start = high_resolution_clock::now();

	stable_sort(vet2->begin(), vet2->end());

    stop = high_resolution_clock::now();

    duration = stop - start;

    cout << "\nstd::stable_sort: \t\t    "
         << duration.count();
	delete vet2;

    start = high_resolution_clock::now();

	countingSort(vet3);

    stop = high_resolution_clock::now();

    duration = stop - start;

    cout << "\nCounting Sort (without pre-range):  "
         << duration.count();
	delete vet3;

    start = high_resolution_clock::now();

	countingSort(vet4, r1, r2);

    stop = high_resolution_clock::now();

    duration = stop - start;

    cout << "\nCounting Sort (with pre-range):     "
         << duration.count();
	delete vet4;

    start = high_resolution_clock::now();

    quickSort(vet5, 0, n-1);

    stop = high_resolution_clock::now();

    duration = stop - start;

    cout << "\nQuick Sort (recursive):\t\t    "
	         << duration.count();
	delete vet5;

    start = high_resolution_clock::now();

	quickSortIterative(vet6, n);

    stop = high_resolution_clock::now();

    duration = stop - start;

    cout << "\nQuick Sort (iterative):\t\t    "
         << duration.count();
	delete vet6;

    if(slowSort){

        start = high_resolution_clock::now();

        mergeSort(vet7, 0, n-1);

        stop = high_resolution_clock::now();

        duration = stop - start;

        cout << "\nMerge Sort (recursive):\t\t    "
             << duration.count();

        start = high_resolution_clock::now();

        bubbleSort(vet8, n);

        stop = high_resolution_clock::now();

        duration = stop - start;

        cout << "\nBubble Sort: \t\t\t    "
             << duration.count();

	    start = high_resolution_clock::now();

		exchangeSort(vet9, n);

	    stop = high_resolution_clock::now();

	    duration = stop - start;

	    cout << "\nExchange Sort: \t\t\t    "
	         << duration.count();

		start = high_resolution_clock::now();

		selectionSort(vet10);

		stop = high_resolution_clock::now();

		duration = stop - start;

		cout << "\nSelection Sort: \t\t    "
			<< duration.count();

    }

    cout<<flush<< "\n\nPress ENTER to close";
    cin.ignore();
    cin.get();
}
