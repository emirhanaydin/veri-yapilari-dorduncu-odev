/**
* @file sayi.h
* @description Bir liste kullanarak sınırlandırılmamış boyutta bir sayıyı tutar. Her bir eleman bir rakamı temsil eder.
 * Başka bir sayı ile toplanabilecek şekilde tasarlanmıştır.
* @course 2A
* @assignment 4
* @date 5.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef SAYI_H
#define SAYI_H


#include <iostream>
#include <conio.h>
#include "bagilliste.h"
#include "hata.h"

class Sayi {
private:
    BagilListe *_liste;
    int _boyut;
public:
    Sayi();

    Sayi(BagilListe *);

    friend std::ostream &operator<<(std::ostream &, const Sayi &);

    friend bool operator==(const Sayi &, const Sayi &);

    friend bool operator>(const Sayi &, const Sayi &);

    friend Sayi operator+(const Sayi &, const Sayi &);

    /**
     * @return Sayıda kaç adet rakam bulunduğunu döndürür.
     */
    int boyut() const;

    /**
     * @return Verilen konumdaki rakam karakterini döndürür.
     */
    char getir(int indeks) const;

    std::string getirYazdir() const;

    std::string getirNoktali() const;

    std::string getirAyrik() const;

    /**
     * Konsoldan alınan değerlerin sayıya uygun olarak işlenip aktarılmasını sağlar.
     */
    void sayiGir();

    /**
     * Verilen rakamı sayıya dahil eder.
     * @param rakam Verilen karakter bir rakam olmalıdır.
     * @param indeks [OPSİYONEL] Rakamın ekleneceği indeks. Varsayılan olarak sayının sonuna eklenir.
     */
    void ekle(char rakam, int indeks = -1);

    /**
     * Listenin son elemanını, yani tutulan son rakamı siler.
     */
    void rakamSil() throw(SayiBosHatasi);

    /**
     * Listedeki tüm düğümler bellekten silinir ve boyut sıfırlanır. Eğer listede eleman yoksa işlem yapılmaz.
     */
    void temizle();

    ~Sayi();
};


#endif