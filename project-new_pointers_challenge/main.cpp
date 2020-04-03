#include <iostream>

using namespace std;

// ====== Function prototypes ====== //

int *apply_all (const int *const array1, size_t size1,const int *const array2, size_t size2);
void print (const int *const array, int size);

// ====== Main Function ====== //

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "\nArray 1: " ;
    print(array1,array1_size);
    
    cout << "\nArray 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size); // results is now pointing to new_array memory location
    constexpr size_t results_size {array1_size * array2_size};

    cout << "\nResult: " ;
    print(results, results_size);
    
    delete [] results;
    cout << endl;
    cout << endl;

    return 0;
}

// ====== Function definitions ====== //

int *apply_all (const int *const array1, size_t size1,const int *const array2, size_t size2) { // returns a pointer to an integer
    int *new_array {nullptr};
    new_array = new int [15];
    int sum {0};
    int position {0};
    for (size_t i {0}; i < size2; i++) {
        for (size_t j {0}; j < size1; j++) {
            sum = (array2[i] * array1[j]);
            new_array[position] = sum;
            position++;
        }
    }
    return new_array;
}

void print (const int *const array, int size) {
    cout << "[";
    for (size_t i {0}; i < size; i++) {
        cout << array[i] << ",";
    }
    cout << "]";
    
}
