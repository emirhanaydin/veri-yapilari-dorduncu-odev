cmake_minimum_required(VERSION 3.6)
project(veri_yapilari_dorduncu_odev)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
set(SOURCE_FILES
        src/main.cpp
        src/ikiliHeap.cpp include/ikiliHeap.h
        src/konsol.cpp include/konsol.h
        src/dugum.cpp include/dugum.h
        src/gezici.cpp include/gezici.h
        src/bagilListe.cpp include/bagilListe.h
        src/sayi.cpp include/sayi.h
        src/islem.cpp include/islem.h
        src/dosya.cpp include/dosya.h
        src/hata.cpp include/hata.h)
add_executable(veri_yapilari_dorduncu_odev ${SOURCE_FILES})