# Arduino sketches

... pliki pisane na Arduino i kompatybilne z nim platformy (m.in. ESP)

## Co to właściwie jest?

Szkic to kod źródłowy programu w języku C++, z rozszerzeniem `.ino`. Kilka szkiców będących w jednym folderze to projekt - głównym plikiem jest ten, o nazwie takiej, jak nazwa folderu. Pozostałe pliki `.ino` są automatycznie dołączane, co daje ten sam efekt, co kompilacja jednego dużego pliku. Różnica polega na tym, że w ten sposób jest po prostu czytelniej: projekt dzieli się na części, a te z kolei na poszczególne funkcje. A w głównym pliku są tylko wywołania funkcji, bez dyrektyw `#include` :D

## A na co mnie to?

Mikrokontrolery nas otaczają - klawiatura, mysz, telefon, pilot, wszystkie te urządzenia muszą być jakoś zaprogramowane. Nie przekonałem? No to dalej: pralki, lodówki, telewizory, systemy infotainment w samochodach. Wszystko elektroniczne.

## Łatwe to?

Łatwe ;)