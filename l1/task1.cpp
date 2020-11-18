#include <iostream>
#include <clocale>
#include <omp.h>
using namespace std;
int main() {

    #ifdef _OPENMP
        cout << "Поддержка OpenMP включена" << endl;
    #elif
        cout << "OpenMP не поддерживается" << endl;
    #endif

    int count_of_threads;
    long sum = 0;
    cout << "Введите число потоков" << endl;
    cin >> count_of_threads;

    omp_set_num_threads(count_of_threads);

    double wtime;
    wtime = omp_get_wtime();

    #pragma omp parallel for reduction (+:sum)
    for(int i=2; i<100001; i++) {
        sum += i;
    }

    wtime = omp_get_wtime() - wtime;
    cout << "Time is: " << wtime << endl;
    cout << "Sum is: " << sum << endl;

}