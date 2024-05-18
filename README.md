# v1.0

## Pakeitimai:
- Optimizavimo strategijų testavimas
- Konteinerių studentams testavimas (deque, vector, list)
- Dauguma strategijų testavimo kodo sudėtos į funkcijas, dėl optimizavimo
- Makefile
- Paleidžiami .exe failai
- Apvalyta repozitorija

## Kompiuterio Specifikacijos:
- CPU: Intel Core i5-12450H
- GPU: NVIDIA RTX 4060 Laptop GPU
- RAM: 16 GB DDR5
- SSD: 2TB NVMe KINGSTON SKC3000

## Ankstesnių versijų aprašymai:
### [v0.4.1](https://github.com/Skirmantux/objektinis1/releases/tag/v0.4.1)
- Galimybė generuoti atsitiktinius studentų failus.
- Galimybė pasirinkti kokio dydžio studentų failų norite.
- Galimybė sugeneruotus failus atidaryti.
- Galimybė sugeneruotus failus skirstyti į "normalius" ir "nenormalius" studentus, t.y studentus kurių vidurkiai yra daugiau arba lygūs 5 arba mažesni nei 5.
- Galimybė skirstytus studentus išspausdinti į atskirus failus.
- Galimybė matuoti programos veikimo ir procesų trukmę.

### [v0.3.1](https://github.com/Skirmantux/objektinis1/releases/tag/v0.3.1)

- Kodas perkeltas į header ir .cpp implementavimo failus;
- Naudojamas exception handling neteisingų įvesčių atveju; 
- Teksto failų tikrinimas;

Source failas - ConsoleApplication1, jį turime atidaryti norint pažiūrėti kodą. Norint kompiliuoti kodą per Visual Studio, reikia atidaryti .sln failą /ConsoleApplication1 aplanke ir paspausti "Local Windows Debugger" mygtuką viršuje. Tada tereikia sekti instrukcijas ekrane norint naudoti programą.

DĖMĖSIO!!! - studentų (studentai10000.txt...) iš ankščiau sugeneruoti failai nėra įkeliami į repozitoriją, nes jų dydžiai yra per dideli. Prašome juos užsipildyti patiems arba atsisiųsti iš interneto.

### [v0.2.1](https://github.com/Skirmantux/objektinis1/releases/tag/v.0.2)
- Skaitymas/rašymas į failus;
- Chronometras matuojantis, kiek laiko užima kiekviena operacija (read/write, process);
- Optimizuotas kodas;
- Galimybė užbaigti darbą per meniu;
- Mokinių rikiavimas pagal balus, vardus, pavardes;

### [v0.1.2](https://github.com/Skirmantux/objektinis1/releases/tag/v0.1.2)
- Pridėta naujų random skaičių generavimo funkcija.
- Pridėtas vektoriaus patikrinimas, neišeis vietoj skaičiaus įrašyti raidės ir užcrashinti programą.
- Vietoj bubble sort naudojama sort() funkcija.
- Vietoj for ciklo naudojama accumulate() funkcija.
- Pakeistos ciklo ribos, dabar ciklas baigsis tik tada, kai vartotojas įves -1. Neprašoma vartotojo įvesti namų darbų ir studentų skaičiaus.

### [v.pradinė](https://github.com/Skirmantux/objektinis1/releases/tag/subrelizas-v.pradin%C4%97)
pirmoji prototipinė mokinių įvertinimo skaičiavimo ir spausdinimo versija. Ji ateityje bus tobulinama ir naudojama kaip pagrindas kitoms versijoms. Kaip atidaryti programą ir ją kompiliuoti yra aprašyta readme.md faile.

## Testavimo Duomenys ir Rezultatai

### Klasė
| Klasė | # Studentų  | Skaitymas (s) | 1 strategija | 2 strategija | 3 strategija |
|-------|-------------|---------------|--------------|--------------|--------------|
|       | 100k        | 9.66472       | 9.72976      | 9.68985      |
|       | 1m          | 95.5213       | 95.874       | 95.6021      |

| Klasė  | Rūšiavimas (s) | 1 strategija | 2 strategija | 3 strategija |
|--------|----------------|--------------|--------------|--------------|
| 100k   |                | 0.0102049    | 0.013882     | 0.157393     |
| 1m     |                | 0.157121     | 0.157262     | 0.157393     |

| Klasė  | Skaidymas (s) | 1 strategija | 2 strategija | 3 strategija |
|--------|---------------|--------------|--------------|--------------|
| 100k   |               | 0.203648     | 0.0147951    | 0.0119351    |
| 1m     |               | 0.172753     | 0.125434     | 0.0313055    |

### Struktūros 
| Struktūros | # Studentų | Skaitymas (s) | 1 strategija | 2 strategija | 3 strategija |
|------------|------------|---------------|--------------|--------------|--------------|
|            | 100k       | 9.75101       | 9.66977      | 9.69309      |
|            | 1m         | 97.2001       | 97.1917      | 97.3941      |

| Struktūros | Rūšiavimas (s) | 1 strategija | 2 strategija | 3 strategija |
|------------|----------------|--------------|--------------|--------------|
| 100k       |                | 0.0149406    | 0.0158391    | 0.0101099    |
| 1m         |                | 0.158945     | 0.168172     | 0.169934     |

| Struktūros | Skaidymas (s)  | 1 strategija | 2 strategija | 3 strategija |
|------------|----------------|--------------|--------------|--------------|
| 100k       |                | 0.0157576    | 0.0091265    | 0.00004261   |
| 1m         |                | 0.180168     | 0.111448     | 0.0352132    |

## Veikimo Analizė

### Duomenų Skaitymas:
- Skaitymas naudojant list konteinerį yra greičiausias, tačiau mažesniuose failuose jo naudotojas neturėtų pastebėti skirtumo.

### Duomenų Rūšiavimas:
- Vektorių konteineris rūšiuoja studentus greičiausiai, nes jis gali prieiti įrašus atsitiktinai, kas yra labai padeda rūšiavimo algoritmui.
- List lėtesnis, nes jame elementus reikia prieiti iš eilės.
- Deque lėčiausias, nes nėra tam sukurtas.

### Studentų Skaidymas:
- List konteineris yra efektyviausias, nes gali įterpti ir pašalinti elementus be kitų perkėlimo.
- Deque yra antras, o vector konteineris yra lėčiausias, nes reikalauja daugiausia elementų perkėlimo.

> [!WARNING]  
> Jei atliksite benchmark'us patys, prašome kartoti testus kuo daugiau ir imti vidurkį, nes dauguma laiko skirtumo atidarant/uždarant ir modifikuojant elementus failuose užima operacinė sistema, taip pat ji užima resursus, kuriuos galima būtų naudoti atidarant failus, todėl tai yra nenuspėjama. Testuojant pirmą kartą buvo išrinkta greičiausia universali strategija ir su ja testuojami skirtingi konteineriai!!!

## Konteinerių Palyginimas
Remiantis vidutiniais laikais, pastebima, kad vektorius yra labiausiai efektyvus skaitymo procesas, tačiau jis reikalauja daugiau laiko rūšiuojant palyginus su list ir deque. List, priešingai, rūšiuojasi greičiau, bet skaitymo procesas užtrunka ilgiau lyginant su vektoriumi ir dvipusiu sąrašu. Dvipusis sąrašas pasižymi tarpiniu elgesiu, kai skirstymas į "nenormalius" ir "normalius" nevyksta dažnai. Studentų klasifikavimas į nenormalius trunka trumpiausiai naudojant deque, o ilgiausiai naudojant list. Padidėjus duomenų kiekiui, studentų klasifikavimas į nenormalius trunka ilgiau visuose konteineriuose, tačiau dvipusis sąrašas pasirodo greitesnis nei vektorius ir list. Didžiausias studentų skaidymo laikas yra su 10000000 duomenų, o mažiausias su 1000 duomenų. Vektorius gali patirti didelį veikimo spartos sumažėjimą dėl papildomo atminties kopijavimo. List gali būti geriau tinkamas pasirinkimas, jei didelės atminties reikalavimai, bet veikimo greitis nėra kritiškai svarbus. Deque gali būti efektyvesnis pasirinkimas nei vektorius dėl jo efektyvaus atminties manipuliavimo.

# Kaip paleisti kodą?

> [!NOTE]  
> Šią instrukciją Windows OS reikia sekti tik tada, kai neturite iš repozitorijos atsiųstų .exe failų!

## Makefile

> [!WARNING]  
> Makefile nėra palaikomas Windows sistemose, todėl yra atskiri žingsniai kaip jį įsidiegti.

### Windows

1. Nueikite į šią svetainę: [GNU Make for Windows](https://sourceforge.net/projects/gnuwin32/files/make/3.81/)
2. Atsisiųskite naujausią versiją.
3. Susikonfigūruokite. Jei sunku suprasti, kaip ką daryti, gali padėti YouTube vaizdo įrašas: [Makefile Installation Tutorial](https://www.youtube.com/watch?v=taCJhnBXG_w)
4. Atsisiunčiame projekto .zip failą, jį išskleidžiame.
5. Atidarius projekto aplankalą, jame paspaudžiame dešinįjį pelės mygtuką ir paspaudžiame "Atidaryti terminalą" (CMD)
6. Parašome "make"
7. Atsiras .exe failai, kuriuos paleidus galite naudotis programa.

> [!WARNING]  
> 10000000 Studentų failas nėra įdedamas į GitHub repozitoriją. Prašome jį susigeneruoti naudojantis programa!
