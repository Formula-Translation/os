#include <iostream>

// Global variables
int globalVar1 = 10;
int globalVar2 = 20;
int globalVar3 = 30;

// Recursive function to demonstrate call stack
void recursiveFunction(int n) {
    int localVar = n;
    std::cout << "Recursive call with n = " << n << ", localVar address: " << &localVar << std::endl;

    if (n > 0) {
        recursiveFunction(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Enter a value for n: ";
    std::cin >> n;

    // Demonstrate call stack
    recursiveFunction(n);

    // Demonstrate heap memory allocation
    int* heapVar1 = new int(40);
    int* heapVar2 = new int(50);
    int* heapVar3 = new int(60);

    std::cout << "Heap variables: " << *heapVar1 << ", " << *heapVar2 << ", " << *heapVar3 << std::endl;

    // Free heap memory
    delete heapVar1;
    delete heapVar2;
    delete heapVar3;

    // Ask user if they want to trigger a stack overflow
    int choice;
    std::cout << "Do you want to trigger a stack overflow? (Enter 1 for yes, 0 for no): ";
    std::cin >> choice;

    if (choice == 1) {
        recursiveFunction(10000);
    }

    return 0;
}
