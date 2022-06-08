#include <iostream>
#include "code_hamming.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int a[] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1};
    int b[] = {0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1};
    int count_array = 16;
    for (int i = 0; i < count_array; i++){
        cout << a[i] << " : ";
    }
    cout << endl;
    int *after = code_hamming(a, count_array);
    for (int i = 0; i < number_control_bit(count_array); i++){
        cout << after[i] << ", ";
    }
    cout << endl;

    int c[] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1};
    after = code_hamming(c, count_array + 1);
    for (int i = 0; i < number_control_bit(count_array+1); i++){
        cout << after[i] << ", ";
    }
    cout << endl;


    int f = check_exception(b, 21);
    cout << f << endl;
    return 0;
}


