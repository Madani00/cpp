#include <iostream>

tell me the real difference when using static cast and reinterpret cast in c++ in detail
int main() {

int* a = new int();
void* b = static_cast<void*>(a);
int* c = static_cast<int*>(b);


int* a = new int();
void* b = reinterpret_cast<void*>(a);
int* c = reinterpret_cast<int*>(b);


}