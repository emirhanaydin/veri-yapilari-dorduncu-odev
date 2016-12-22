#include <iostream>
#include <dosya.h>
#include <ikiliHeap.h>
#include <cstdlib>
#include <konsol.h>

using namespace std;

string DosyaAdiniAl(std::string);

int main() {
    const char *sayilarYolu = "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-dorduncu-odev\\Sayilar.txt";
    const char *siraliYolu = "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-dorduncu-odev\\Sirali.txt";

    Dosya sayilarDosyasi(sayilarYolu);
    sayilarDosyasi.dosyayiOku();

    Sayi *sayiDizisi = new Sayi[sayilarDosyasi.satirSayisi()];

    sayilarDosyasi.sayiDizisineAktar(sayiDizisi);

    Dosya siraliDosya(siraliYolu);

    IkiliHeap ikiliHeap;

    for (int i = 0, len = sayilarDosyasi.satirSayisi(); i < len; ++i) {
        ikiliHeap.Ekle(sayiDizisi[i]);
    }

    system("CLS");

    Konsol::renkliYazdir(DosyaAdiniAl(sayilarYolu).c_str(), 12);
    cout << " dosyasindaki tum sayilar ";
    Konsol::renkliYazdir(DosyaAdiniAl(siraliYolu).c_str(), 10);
    cout << " dosyasina ";
    Konsol::renkliYazdir("Ikili Heap Agaci", 14);
    cout << " kullanilarak kucukten buyuge dogru sirali olarak aktarildi.";
    cout << endl << endl;

    for (int i = 0, len = sayilarDosyasi.satirSayisi(); i < len; ++i) {
        Sayi *mevcut = &ikiliHeap.getirEnKucuk();
        siraliDosya.satirEkle(mevcut->getirKatar());
        ikiliHeap.enKucuguSil();

        if (i == len - 1) {
            Konsol::renkliYazdir("En buyuk sayi: ", 11);
            Konsol::renkliYazdir(mevcut->getirNoktali().c_str(), 15);
        }
    }

    siraliDosya.dosyayaKaydet();

    delete[] sayiDizisi;

    cout << endl << endl;
    system("PAUSE");
    return 0;
}

string DosyaAdiniAl(string dosyaYolu) {
    return string(dosyaYolu.substr(dosyaYolu.find_last_of('\\') + 1));
}