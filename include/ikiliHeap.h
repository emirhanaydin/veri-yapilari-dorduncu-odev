/**
* @file gezici.h
* @description İlişkili düğümler arasında ileriye doğru taramayı kolaylaştırmak için kullanılır.
* @course 2A
* @assignment 4
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef IKILIHEAP_H
#define IKILIHEAP_H


#include "sayi.h"

class IkiliHeap {
private:
    Sayi **_icerik;
    int _kapasite;
    int _uzunluk;

    void AsagiFirlat(int indeks);

    void YukariFirlat(int indeks);

    void IcerigiAyarla();

    void Genislet();

public:
    IkiliHeap();

    void Ekle(Sayi &sayi);

    Sayi &getirEnKucuk();

    void enKucuguSil();

    ~IkiliHeap();
};


#endif //IKILIHEAP_H
