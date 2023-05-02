#include <iostream>
#include <fstream>
using namespace std;


void shiftArray(int arr[], int size, bool direction) {
    if (direction) {
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
    else {
        int first = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first;
    }
}


void reverseArrays(int arr1[], int size1, int arr2[], int size2) {
    int* newArr1 = new int[size1];
    int* newArr2 = new int[size2];
    for (int i = 0; i < size1; i++) {
        newArr1[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        newArr2[i] = arr2[i];
    }
    shiftArray(newArr1, size1, false);
    shiftArray(newArr2, size2, true);

    ofstream out("out.txt");
    out << size2 << " " << endl;
    for (int i = 0; i < size2; i++) {
        out << newArr2[i] << " ";
    }
    out << endl;
    out << size1 << " " << endl;
    for (int i = 0; i < size1; i++) {
        out << newArr1[i] << " ";
    }
    out.close();

    delete[] newArr1;
    delete[] newArr2;
}

int main() {
    ifstream in("in.txt");
    int size1, size2;
    in >> size1;
    int* arr1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        in >> arr1[i];
    }
    in >> size2;
    int* arr2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        in >> arr2[i];
    }
    in.close();

    reverseArrays(arr1, size1, arr2, size2);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
