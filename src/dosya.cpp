/**
* @file dosya.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#include <fstream>
#include "dosya.h"

Dosya::Dosya(const char *dosyaAdi) {
    _dosyaAdi = dosyaAdi;
    dosyayiOku();
}

bool Dosya::rakamMi(char karakter) {
    return karakter >= '0' && karakter <= '9';
}

void Dosya::sayiyaAktar(Sayi &sayi, const std::string &katar) {
    for (int i = 0, len = katar.length(); i < len; i++) {
        if (rakamMi(katar[i]))
            sayi.ekle(katar[i]);
    }
}

int Dosya::satirSayisi() const {
    return _satirSayisi;
}

void Dosya::dosyayiOku() throw(DosyaAcmaHatasi) {
    std::ifstream dosyaOku(_dosyaAdi);

    if (!dosyaOku.is_open()) throw DosyaAcmaHatasi();

    std::string satir;

    _dosyaIcerigi = std::string();
    _satirSayisi = 0;

    while (std::getline(dosyaOku, satir)) {
        _dosyaIcerigi += _satirSayisi > 0 ? "\n" + satir : satir;
        _satirSayisi++;
    }

    _dosyaIcerigi += "\n";

    dosyaOku.close();
}

void
Dosya::sayiDizisineAktar(Sayi *sayiDizisi, int diziUzunlugu) throw(DosyaUygunDegilHatasi, IndeksAralikDisindaHatasi) {
    if (diziUzunlugu < _satirSayisi) throw IndeksAralikDisindaHatasi();
    if (_dosyaIcerigi == std::string()) throw DosyaUygunDegilHatasi();

    std::string satir = std::string();
    char simdikiKar;

    for (int i = 0, j = 0, len = _dosyaIcerigi.length(); i < len; ++i) {
        simdikiKar = _dosyaIcerigi[i];

        if (simdikiKar != '\n') {
            satir += simdikiKar;
        } else {
            sayiyaAktar(sayiDizisi[j], satir);
            satir = std::string();
            ++j;
        }
    }
}
