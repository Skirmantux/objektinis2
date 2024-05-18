# v1.1

## Pakeitimai:
- Vietoje struktūrų tipų naudojame klases, kurios veikia truputį efektyviau, ypač esant dideliam studentų skaičiui.
- Nauji testavimo tyrimai.

## Kompiuterio Specifikacijos:
- CPU: Intel Core i5-12450H
- GPU: NVIDIA RTX 4060 Laptop GPU
- RAM: 16 GB DDR5
- SSD: 2TB NVMe KINGSTON SKC3000

## Ankstesnių versijų aprašymai:
### [v1.0](https://github.com/Skirmantux/objektinis1/releases/tag/v1.0)
- Daug įvairių atnaujinimų.

## Testavimo Duomenys ir Rezultatai (matuojami sekundėmis)

### Klasė
Skaitymas

|Studentų sk. | 1 strategija  | 2 strategija | 3 strategija |
|-------------|---------------|--------------|--------------|
| 100k        | 9.66472       | 9.72976      | 9.68985      |
| 1m          | 95.5213       | 95.874       | 95.6021      |

Rūšiavimas

| Studentų sk. | 1 strategija | 2 strategija | 3 strategija |
|--------------|--------------|--------------|--------------|
| 100k         | 0.0102049    | 0.013882     | 0.157393     |
| 1m           | 0.157121     | 0.157262     | 0.157393     |

Skaidymas

| Studentų sk.  | 1 strategija | 2 strategija | 3 strategija |
|---------------|--------------|--------------|--------------|
| 100k          | 0.203648     | 0.0147951    | 0.0119351    |
| 1m            | 0.172753     | 0.125434     | 0.0313055    |

### Struktūros 

Skaitymas

| Studentų sk. | 1 strategija  | 2 strategija | 3 strategija |
|--------------|---------------|--------------|--------------|
| 100k         | 9.75101       | 9.66977      | 9.69309      |
| 1m           | 97.2001       | 97.1917      | 97.3941      |

Rūšiavimas

| Studentų sk. | 1 strategija | 2 strategija | 3 strategija |
|--------------|--------------|--------------|--------------|
| 100k         | 0.0149406    | 0.0158391    | 0.0101099    |
| 1m           | 0.158945     | 0.168172     | 0.169934     |

Skaidymas

| Studentų sk. | 1 strategija | 2 strategija | 3 strategija |
|--------------|--------------|--------------|--------------|
| 100k         | 0.0157576    | 0.0091265    | 0.00004261   |
| 1m           | 0.180168     | 0.111448     | 0.0352132    |

## Veikimo Analizė

### Duomenų Skaitymas:
- Skaitymas naudojant klases yra pastebimai geresnis tik esant didesniam studentų skaičiui.

### Duomenų Rūšiavimas:
- Rūšiavimas su klasėmis veikia panašiai kaip ir su struktūromis.
- Esant didesniam studentų skaičiui, klasės matavimai yra daug stabilesni, t.y. laikas surūšiuoti elementus klasėje mažai kito.

### Studentų Skaidymas:
- Esant didesniam mokinių skaičiui, klasės veikia greičiau ir stabiliau.
- Struktūros greitesnės tik tada, kai mažesnis studentų skaičius ir tik naudojantis tam tikromis, letesnemis strategijomis.

> [!WARNING]  
> Jei atliksite benchmark'us patys, prašome kartoti testus kuo daugiau ir imti vidurkį, nes dauguma laiko skirtumo atidarant/uždarant ir modifikuojant elementus failuose užima operacinė sistema, taip pat ji užima resursus, kuriuos galima būtų naudoti atidarant failus, todėl tai yra nenuspėjama. Testuojant pirmą kartą buvo išrinkta greičiausia universali strategija ir su ja testuojami skirtingi konteineriai!!!

## Klasių/struktūrų Palyginimas
- Klasės leidžia mums saugoti elementus nuo neleistino pakeitimo, taip išsaugodami duomenis. Taip pat jos minimaliai greitesnės.

## Kompiliatoriaus flag'ų palyginimas programos veikime

### Be flag'ų




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
