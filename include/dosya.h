/**
* @file dosya.h
* @description Dosya üzerinden okuma ve kuyruğa aktarma işlemlerini barındırır.
* @course 2A
* @assignment 4
* @date 6.12.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/


#ifndef DOSYA_H
#define DOSYA_H


#include "hata.h"
#include "sayi.h"

class Dosya {
private:
    const char *_dosyaAdi;

    int _satirSayisi;

    std::string _dosyaIcerigi;

    bool rakamMi(char karakter);

    void sayiyaAktar(Sayi &sayi, const std::string &katar);

public:
    Dosya(const char *dosyaAdi);

    int satirSayisi() const;

    void dosyayiOku() throw(DosyaAcmaHatasi);

    void satirEkle(const std::string &satir);

    void dosyayaKaydet() throw(DosyaAcmaHatasi);

    void sayiDizisineAktar(Sayi sayiDizisi[]) throw(DosyaUygunDegilHatasi);
};


#endif //DOSYA_H
