#include <iostream>
#include <ikiliHeap.h>

using namespace std;

int main() {
    IkiliHeap ikiliHeap;
    ikiliHeap.Ekle('a');
    ikiliHeap.Ekle('b');
    ikiliHeap.Ekle('c');
    ikiliHeap.Ekle('d');
    ikiliHeap.Ekle('e');

    cout << ikiliHeap.alEnKucuk();

    return 0;
}