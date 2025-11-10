# C++ Developer: Refactoring [customer.h] in C++

## C++ Classes: Customer and CustomerArchive classes

### Structure of directory

```
ASSECOR-ASSESSMENT-CPP/
├── include/
│   └── customer.h
├── src/
│   └── customer.cpp
├── test_images/
|   ├── CMakeLists.txt 
│   └── CustomerTest.cpp
├── main.cpp
└── CMakeLists.txt
```

### Customer class

	2. Ein Kundendatenformatierer, der folgendes kann:
		1. Gibt die Kundendaten zu einer gegebenen ID als schön formatierten Ausgabetext aus.

### CustomerArchive class
	1. Ein Kunden-Archiv, das folgende Funktionen hat:
		1. Kunden hinzufügen
		2. Alle Kunden ausgeben
		3. Kundendaten zu einer ID ausgeben

### main.cpp

``` bash
./CustomerData
```

### Test: Googletest

Run test with
``` bash
ctest --output-on-failure
```

4. Schreibe eine Konsolenapplikation mit folgenden Funktionen:
	1. Hinzufügen eines Kunden zum Archiv
	2. Ausgeben der Kundendaten zu einer ID
	3. Ausgeben der Liste aller gespeicherten Kundendaten
	
