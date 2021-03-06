/**
* @file hata.h
* @description Hata tanımlamalarının yapıldığı başlık dosyası.
* @course 2A
* @assignment 4
* @date 11.12.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/


#ifndef HATA_H
#define HATA_H


#include <iostream>
#include <exception>

using namespace std;

class DosyaAcmaHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Belirtilen dosyaya erisilemiyor.";
    }
};

class DosyaUygunDegilHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Belirtilen dosya icerigi uygun degil veya dosya bos.";
    }
};

class ElemanBulunamadiHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Belirtilen eleman bulunamadi.";
    }
};

class ElemanZatenVarHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Belirtilen eleman zaten mevcut.";
    }
};

class KuyrukBosHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Kuyrukta eleman bulunmuyor.";
    }
};

class IndeksAralikDisindaHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Girilen deger dizi sinirlari disinda.";
    }
};

class SayiBosHatasi : public exception {
public:
    virtual const char *what() const throw() {
        return "Sayida eleman yok.";
    }
};


#endif //HATA_H
