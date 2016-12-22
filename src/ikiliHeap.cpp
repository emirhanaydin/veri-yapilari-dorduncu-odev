#include "ikiliHeap.h"

void IkiliHeap::AsagiFirlat(int indeks) {
    int solYavruIndeks = 2 * indeks + 1;
    int sagYavruIndeks = 2 * indeks + 2;

    if (solYavruIndeks >= _uzunluk)
        return; // Yavru yapraktır.

    int enKucukIndeks = indeks;
    if (*_icerik[indeks] > *_icerik[solYavruIndeks])
        enKucukIndeks = solYavruIndeks;
    if (sagYavruIndeks < _uzunluk && *_icerik[enKucukIndeks] > *_icerik[sagYavruIndeks])
        enKucukIndeks = sagYavruIndeks;
    if (enKucukIndeks == indeks)
        return;

//    Yer değiştirme yapılır.
    Sayi *gecici = _icerik[indeks];
    _icerik[indeks] = _icerik[enKucukIndeks];
    _icerik[enKucukIndeks] = gecici;
    AsagiFirlat(enKucukIndeks);
}

void IkiliHeap::YukariFirlat(int indeks) {
    if (indeks == 0)
        return;

    int ebeveynIndeks = (indeks - 1) / 2;

    if (*_icerik[ebeveynIndeks] > *_icerik[indeks]) {
        Sayi *gecici = _icerik[ebeveynIndeks];
        _icerik[ebeveynIndeks] = _icerik[indeks];
        _icerik[indeks] = gecici;
        YukariFirlat(ebeveynIndeks);
    }
}

void IkiliHeap::Canlandir() {
    for (int i = _uzunluk - 1; i >= 0; --i) {
        AsagiFirlat(i);
    }
}

IkiliHeap::IkiliHeap() {
    _icerik = new Sayi *[20];
    _uzunluk = 0;
}

void IkiliHeap::Ekle(Sayi &sayi) {
    _icerik[_uzunluk] = &sayi;

    YukariFirlat(_uzunluk);
}

Sayi &IkiliHeap::alEnKucuk() {
    return *_icerik[0];
}

IkiliHeap::~IkiliHeap() {
    delete[] _icerik;
}
