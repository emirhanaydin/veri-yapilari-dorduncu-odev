/**
* @file dosya.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 4
* @date 6.12.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/


#include <fstream>
#include "dosya.h"

Dosya::Dosya(const char *dosyaAdi) {
    _dosyaAdi = dosyaAdi;
    _dosyaIcerigi = std::string();
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

void Dosya::satirEkle(const std::string &satir) {
    if (_dosyaIcerigi != std::string() && _dosyaIcerigi[_dosyaIcerigi.length() - 1] != '\n')
        _dosyaIcerigi += '\n';

    _dosyaIcerigi += satir;
}

void Dosya::dosyayaKaydet() throw(DosyaAcmaHatasi) {
    std::ofstream dosyaYaz(_dosyaAdi);

    if (!dosyaYaz.is_open()) throw DosyaAcmaHatasi();

    dosyaYaz << _dosyaIcerigi;

    dosyaYaz.close();
}

void
Dosya::sayiDizisineAktar(Sayi *sayiDizisi) throw(DosyaUygunDegilHatasi) {
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
