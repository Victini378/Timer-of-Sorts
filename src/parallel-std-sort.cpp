/*
* Compiled with parameters: g++ parallel-std::sort.cpp -std=gnu++17 -Ofast -fopenmp -D_GLIBCXX_PARALLEL
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;

int main(){
	int n, r1, r2;

	cout<< "Insert element number of vector: ";
	cin>>n;
	while(n<1){
		cerr<< "Please enter values greater than 0: ";
		cin>>n;
	}

	cout<< "Insert range of numbers of vector: ";
	cin>>r1>>r2;

	int* vet = new int[n];

	default_random_engine e(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distr(r1,r2);
	auto rnd = bind(distr,e);

	generate(vet, vet+n, rnd);

	cout<< "\033c";

	cout<< "Timer of execution of sort: ";
	cout<< "\nInput size: "<<n<<"\tInput range: From "<<r1<<" to "<<r2
		<< "\n\nSorting Algorithm\t\t    time taken(s)"<<endl;

	auto start = high_resolution_clock::now();

	sort(vet, vet+n);

    auto stop = high_resolution_clock::now();

    duration<long double> duration = stop - start;

    cout << "std::sort: \t\t\t    "
         << duration.count()<<endl;

    clog<< "\nPress ENTER to close";
    cin.clear();
    cin.sync();
		cin.ignore();
    cin.get();
}
