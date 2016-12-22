#include <iostream>
#include <dosya.h>
#include <cstdlib>

using namespace std;

int main() {
    Dosya dosya(
            "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-dorduncu-odev\\Sayilar.txt");

    Sayi sayilar[5];

    dosya.sayiDizisineAktar(sayilar, 5);

    for (int i = 0, len = dosya.satirSayisi(); i < len; ++i) {
        cout << sayilar[i];
        cout << endl;
    }

    system("PAUSE");
    return 0;
}