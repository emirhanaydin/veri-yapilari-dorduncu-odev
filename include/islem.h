/**
* @file islem.h
* @description Sayı sınıfı üzerinden yapılacak işlemleri gerçekleştirir. Bir listenin istenilen formatta bir sayı olarak
 * dışarıdan alınması ve aynı şekilde üzerinde toplama işlemi yapılması burada gerçekleştirilir.
* @course 2A
* @assignment 4
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef ISLEM_H
#define ISLEM_H

#include <iostream>
#include "sayi.h"

class Islem {
public:
    static short karsilastir(const Sayi &, const Sayi &);

    static void sayiGir(Sayi &sayi);

    static std::string getirYazdir(const Sayi &sayi);

    /**
     * Sayi'nın, sağdan sola doğru her üç rakamda bir nokta olacak şekilde yazdırılmış halini döndürür.
     */
    static std::string getirNoktali(const Sayi &sayi);

    /**
     * Sayi'yi her rakamının arasına kısa çizgi koyarak yazdırır.
     */
    static std::string getirAyrik(const Sayi &sayi);

    /**
     * İki Sayi'yi tüm rakamlarını tek tek karşılaştırarak toplama işlemine tabi tutar.
     * @return İki sayının toplamını tutan yeni bir Sayi nesnesi döndürür.
     */
    static Sayi topla(const Sayi &, const Sayi &);
};

#endif