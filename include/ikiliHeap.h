#ifndef IKILIHEAP_H
#define IKILIHEAP_H


class IkiliHeap {
private:
    char *_icerik;
    int _uzunluk;

    void AsagiFirlat(int indeks);

    void YukariFirlat(int indeks);

    void Canlandir();

public:
    IkiliHeap();

    void Ekle(char karakter);

    char alEnKucuk();

    ~IkiliHeap();
};


#endif //IKILIHEAP_H
