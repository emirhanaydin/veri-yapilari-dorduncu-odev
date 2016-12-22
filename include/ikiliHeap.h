#ifndef IKILIHEAP_H
#define IKILIHEAP_H


#include "sayi.h"

class IkiliHeap {
private:
    Sayi **_icerik;
    int _uzunluk;

    void AsagiFirlat(int indeks);

    void YukariFirlat(int indeks);

    void Canlandir();

public:
    IkiliHeap();

    void Ekle(Sayi &sayi);

    Sayi &alEnKucuk();

    ~IkiliHeap();
};


#endif //IKILIHEAP_H
