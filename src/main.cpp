/**
* @file main.cpp
* @description Dosyadan alınan verilere göre sıralama işlemini yapan programın başlangıç noktası.
* @course 2A
* @assignment 4
* @date 22.12.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include <iostream>
#include <dosya.h>
#include <ikiliHeap.h>
#include <cstdlib>
#include <konsol.h>

using namespace std;

string DosyaAdiniAl(std::string);

int main() {
    const char *sayilarYolu = "Sayilar.txt";
    const char *siraliYolu = "Sirali.txt";
    const char *sayilarAdi = DosyaAdiniAl(sayilarYolu).c_str();
    const char *siraliAdi = DosyaAdiniAl(siraliYolu).c_str();

    Dosya sayilarDosyasi(sayilarYolu);

    try {
        sayilarDosyasi.dosyayiOku();
    } catch (DosyaAcmaHatasi) {
        Konsol::renkliYazdir(sayilarAdi, 12);
        cerr << " dosyasi acilamiyor, dosya yolu yanlis olabilir."
             << endl << endl
             << "Program sonlandirilacak...";

        _getch();
        return EXIT_FAILURE;
    }

    int sayilarSatirSay = sayilarDosyasi.satirSayisi();

    Sayi *sayiDizisi = new Sayi[sayilarSatirSay];

    sayilarDosyasi.sayiDizisineAktar(sayiDizisi);

    Dosya siraliDosya(siraliYolu);

    IkiliHeap *ikiliHeap = new IkiliHeap();

    for (int i = 0; i < sayilarSatirSay; ++i) {
        ikiliHeap->Ekle(sayiDizisi[i]);
    }

    system("CLS");

    Konsol::renkliYazdir(sayilarAdi, 12);
    cout << " dosyasindaki tum sayilar ";
    Konsol::renkliYazdir(siraliAdi, 10);
    cout << " dosyasina ";
    Konsol::renkliYazdir("Ikili Heap Agaci", 14);
    cout << " kullanilarak kucukten buyuge dogru sirali olarak aktarildi.";
    cout << endl << endl;

    for (int i = 0; i < sayilarSatirSay; ++i) {
        Sayi *mevcut = &ikiliHeap->getirEnKucuk();
        siraliDosya.satirEkle(mevcut->getirYazdir());
        ikiliHeap->enKucuguSil();

        if (i == sayilarSatirSay - 1) {
            Konsol::renkliYazdir("En buyuk sayi: ", 11);
            Konsol::renkliYazdir(mevcut->getirNoktali().c_str(), 15);
        }
    }

    try {
        siraliDosya.dosyayaKaydet();
    } catch (DosyaAcmaHatasi) {
        Konsol::renkliYazdir(siraliAdi, 12);
        cerr << " dosyasi acilamiyor, dosya kullanimda olabilir."
             << endl << endl
             << "Program sonlandirilacak...";

        _getch();
        return EXIT_FAILURE;
    }

    delete ikiliHeap;
    delete[] sayiDizisi;

    cout << endl << endl
         << "Program sonlandirilacak...";
    _getch();
    return EXIT_SUCCESS;
}

string DosyaAdiniAl(string dosyaYolu) {
    return string(dosyaYolu.substr(dosyaYolu.find_last_of('\\') + 1));
}