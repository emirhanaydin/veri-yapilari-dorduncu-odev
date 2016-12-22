#include "heapAgac.h"

void HeapAgac::AsagiFirlat(int indeks) {
    int yavruKonumu = 2 * indeks;
    int solYavruIndeks = yavruKonumu + 1;
    int sagYavruIndeks = yavruKonumu + 2;

    if (solYavruIndeks >= _uzunluk)
        return; // Yavru yapraktır, durma noktası.

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

void HeapAgac::YukariFirlat(int indeks) {
    if (indeks == 0)
        return; // Kök düğüm, durma noktası

    int ebeveynIndeks = (indeks - 1) / 2;

    if (*_icerik[ebeveynIndeks] > *_icerik[indeks]) {
        Sayi *gecici = _icerik[ebeveynIndeks];
        _icerik[ebeveynIndeks] = _icerik[indeks];
        _icerik[indeks] = gecici;
        YukariFirlat(ebeveynIndeks);
    }
}

void HeapAgac::IcerigiAyarla() {
    for (int i = _uzunluk - 1; i >= 0; --i) {
        AsagiFirlat(i);
    }
}

void HeapAgac::Genislet() {
    int yeniKapasite;
    if (_kapasite > 0) {
        yeniKapasite = 2 * _kapasite;

        Sayi **gecici = new Sayi *[yeniKapasite];

        for (int i = 0; i < _kapasite; ++i) {
            gecici[i] = _icerik[i];
        }

        delete[] _icerik;
        _icerik = gecici;
    } else {
        yeniKapasite = 1;
        _icerik = new Sayi *[yeniKapasite];
    }
    _kapasite = yeniKapasite;
}

HeapAgac::HeapAgac() {
    _icerik = NULL;
    _kapasite = 0;
    _uzunluk = 0;
}

void HeapAgac::Ekle(Sayi &sayi) {
    if (_uzunluk >= _kapasite) {
        Genislet();
    }

    _icerik[_uzunluk] = &sayi;

    YukariFirlat(_uzunluk);
    _uzunluk++;
}

Sayi &HeapAgac::getirEnKucuk() {
    return *_icerik[0];
}

void HeapAgac::enKucuguSil() {
    if (_uzunluk <= 0)
        return;

    _icerik[0] = _icerik[_uzunluk - 1];
    _uzunluk--;

    AsagiFirlat(0);
}

HeapAgac::~HeapAgac() {
    delete[] _icerik;
}
