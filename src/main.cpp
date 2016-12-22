#include <iostream>
#include <dosya.h>
#include <cstdlib>
#include <ikiliHeap.h>

using namespace std;

int main() {
    Dosya sayilarDosyasi(
            "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-dorduncu-odev\\Sayilar.txt");
    sayilarDosyasi.dosyayiOku();

    Sayi *sayiDizisi = new Sayi[sayilarDosyasi.satirSayisi()];

    sayilarDosyasi.sayiDizisineAktar(sayiDizisi);

    Dosya siraliDosya(
            "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-dorduncu-odev\\Sirali.txt");

    IkiliHeap ikiliHeap;

    for (int i = 0, len = sayilarDosyasi.satirSayisi(); i < len; ++i) {
        ikiliHeap.Ekle(sayiDizisi[i]);
    }

    for (int i = 0, len = sayilarDosyasi.satirSayisi(); i < len; ++i) {
        cout << ikiliHeap.getirEnKucuk();
        cout << endl;
        ikiliHeap.enKucuguSil();
    }

    delete[] sayiDizisi;
    system("PAUSE");
    return 0;
}