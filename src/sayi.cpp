/**
* @file sayi.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 4
* @date 5.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include "sayi.h"
#include "islem.h"

Sayi::Sayi() {
    _liste = new BagilListe();
    _boyut = 0;
}

Sayi::Sayi(BagilListe *liste) {
    _liste = liste;
    _boyut = liste->boyut();
}

std::ostream &operator<<(std::ostream &os, const Sayi &sayi) {
    if (sayi._boyut > 0)
        os << *sayi._liste;
    else
        os << "";

    return os;
}

bool operator==(const Sayi &sayi, const Sayi &sayi1) {
    return &sayi == &sayi1;
}

bool operator>(const Sayi &sayi, const Sayi &sayi1) {
    return Islem::karsilastir(sayi, sayi1) > 0;
}

Sayi operator+(const Sayi &sayi, const Sayi &sayi1) {
    return Islem::topla(sayi, sayi1);
}

int Sayi::boyut() const {
    return _boyut;
}

char Sayi::getir(int indeks) const {
//    TODO if (indeks >= _boyut || indeks < 0) throw Exception();

    return _liste->getir(indeks);
}

std::string Sayi::getirYazdir() const {
    return Islem::getirYazdir(*this);
}

std::string Sayi::getirNoktali() const {
    return Islem::getirNoktali(*this);
}

std::string Sayi::getirAyrik() const {
    return Islem::getirAyrik(*this);
}

void Sayi::sayiGir() {
    Islem::sayiGir(*this); // Islem sınıfının, konsoldan alınan değerleri Sayi'nın listesine uygun biçimde aktaracak
//    olan ilgili metot çağrılır.
}

void Sayi::ekle(char rakam, int indeks) {
    _liste->ekle(rakam, indeks);
    _boyut++;
}

void Sayi::rakamSil() throw(SayiBosHatasi) {
    if (_boyut <= 0) throw SayiBosHatasi();

    _liste->sil(); // En son eleman diziden silinir.
    _boyut--;
}

void Sayi::temizle() {
    if (_boyut < 1)
        return;

    _liste->temizle();
    _boyut = 0;
}

Sayi::~Sayi() {
    delete _liste;
}