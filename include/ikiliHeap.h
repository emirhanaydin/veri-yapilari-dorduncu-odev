#ifndef IKILIHEAP_H
#define IKILIHEAP_H


#include "sayi.h"

class IkiliHeap {
private:
    Sayi **_icerik;
    int _kapasite;
    int _uzunluk;

    void AsagiFirlat(int indeks);

    void YukariFirlat(int indeks);

    void IcerigiAyarla();

    void Genislet();

public:
    IkiliHeap();

    void Ekle(Sayi &sayi);

    Sayi &getirEnKucuk();

    void enKucuguSil();

    ~IkiliHeap();
};


#endif //IKILIHEAP_H
