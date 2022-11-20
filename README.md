# IF2110-BNMO-The-Game
 Project ini merupakan salah satu pemenuhan Tugas besar I IF2110 Algoritma dan Struktur Data:
<h2 align="center">
  BNMO The Game<br/>
</h2>

<p align="center">
<img src="https://user-images.githubusercontent.com/73476678/202867644-d271e61e-397f-412c-a36e-760ae835f16e.png">
</p>

<p> Program berbasis Command-Line Interface (CLI) yang dibuat dalam bahasa C. Program ini memproyeksikan sebuah gim mini memasak dengan BNMO sebagai karakter utama. Pada program ini, BNMO dapat melakukan beberapa perintah sesuai masukan user, seperti berjalan dan aksi memasak. </p>
<hr>

## Table of Contents
1. [Getting Started](#getting-started)
2. [How to Run](#how-to-run)
3. [Pembagian Tugas](#pembagian-tugas)
4. [Daftar Fitur](#daftar-fitur)
5. [Struktur](#struktur)
6. [Author](#author)

<a name="getting started"></a>

## Getting Started!

Berikut merupakan cara untuk build project atau menginstall program

1. Clone repo menggunakan command berikut

```
git clone https://github.com/alishalistyaa/IF2110-BNMO-The-Game.git
```

2. Jalankan makefile pada folder main menggunakan command berikut untuk compile program utama, driver, atau keduanya

```
make main
```

```
make driver
```

```
make all
```

3. Jalankan main.exe untuk memulai program utama
4. Jalankan .exe driver pada folder sesuai dengan nama modul untuk memulai driver

<a name="how-to-run"></a>

## How-to-Run

Bagaimana cara menjalankan program? Gunakan command berikut pada folder src untuk menjalankan program utama

```
./main
```

<a name="pembagian-tugas"></a>

## Pembagian Tugas

| Nama / NIM                            | Pembagian Tugas                                                                                                                                            |
| ------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  Jeremya Darmawan Raharjo / 13521131  | <li>ADT Point</li><li>ADT Tree</li><li>Membuat driver</li><li>Alur Utama Program</li>  |
|  Brigita Tri Carolina / 13521156      | <li>ADT Time</li><li>ADT Matriks</li><li>ADT Stack</li><li>ADT Prioqueue</li><li>Membuat driver</li><li>Alur Utama Program</li>|
|  Alisha Listya Wardhani / 13521171    | <li>ADT Makanan</li><li>ADT Charmacine</li><li>ADT Building</li> <li>ADT i_o</li><li>Membuat driver</li><li>Alur Utama Program</li><li>Laporan</li>|
|  Sulthan Dzaky Alfaro / 13521159      | <li>ADT List</li> <li>ADT Queue</li><li>Membuat driver</li><li>Laporan</li>|
|  Mohammad Rifqi Farhansyah / 13521166 | <li>ADT Simulator</li><li>ADT Wordmachine</li> <li>ADT Map</li><li>ADT Notifikasi</li><li>Alur utama program</li><li>Membuat driver</li>

<a name="daftar-fitur"></a>

## Daftar Fitur

| Fitur                          | Status Pengerjaan |
| ------------------------------ | ----------------- |
| `START`                        | &#10004;          |
| `EXIT`                         | &#10004;          |
| `MOVE NORTH`                   | &#10004;          |
| `MOVE SOUTH`                   | &#10004;          |
| `MOVE WEST`                    | &#10004;          |
| `MOVE EAST`                    | &#10004;          |
| `HELP`                         | &#10004;          |
| `INVENTORY`                    | &#10004;          |
| `BUY`                          | &#10004;          |
| `DELIVERY`                     | &#10004;          |
| `WAIT <X> <Y>`                 | &#10004;          |
| `COOKBOOK`                     | &#10004;          |
| `CATALOG`                      | &#10004;          |
| `MIX`                          | &#10004;          |
| `BOIL`                         | &#10004;          |
| `CHOP`                         | &#10004;          |
| `FRY`                          | &#10004;          |
| `UNDO`                         | &#10004;          |
| `REDO`                         | &#10004;          |
| `EXIT`                         | &#10004;          |

<a name="struktur"></a>

## Struktur
```bash
│   log.txt
│   README.md
│
├───.vscode
│       c_cpp_properties.json
│       launch.json
│       settings.json
│       tasks.json
│
└───src
    │   main.c
    │   main.exe
    │   mainsaya.exe
    │   mainsaya1.exe
    │
    ├───config
    │       makanan.txt
    │       makanan2.txt
    │       peta.txt
    │       resep.txt
    │       resep2.txt
    │
    └────modules
        │   .DS_Store
        │
        ├───boolean
        │       boolean.h
        │
        ├───building
        │       building.c
        │       building.h
        │       driver_building.c
        │       driver_building.exe
        │
        ├───charmachine
        │       charmachine.c
        │       charmachine.h
        │       driver_charmachine.c
        │
        ├───i_o
        │       driver_i_o_makanan.c
        │       driver_i_o_tree.c
        │       driver_i_o_tree.exe
        │       i_o.c
        │       i_o.h
        │
        ├───list
        │       driver_liststatik.c
        │       liststatik.c
        │       liststatik.h
        │
        ├───makanan
        │       driver_makanan.c
        │       makanan.c
        │       makanan.h
        │
        ├───map
        │       driver_map.c
        │       map.c
        │       map.h
        │
        ├───matriks
        │       driver_matriks.c
        │       matriks.c
        │       matriks.h
        │
        ├───notification
        │       driver_notification.c
        │       notification.c
        │       notification.h
        │
        ├───point
        │       driver_point.c
        │       driver_point.exe
        │       point.c
        │       point.h
        │
        ├───prioqueue
        │       driver_prioqueue.c
        │       driver_prioqueue.exe
        │       prioqueue.c
        │       prioqueue.h
        │
        ├───resep
        │       driver_resep.c
        │       driver_resep.exe
        │       resep.c
        │       resep.h
        │
        ├───set
        │       driver_set.c
        │       driver_set.exe
        │       set.c
        │       set.h
        │
        ├───simulator
        │       driver_simulator.c
        │       simulator.c
        │       simulator.h
        │
        ├───stack
        │       driverstack.exe
        │       driver_stack.c
        │       stack.c
        │       stack.h
        │
        ├───time
        │       driver_time.c
        │       time.c
        │       time.h
        │
        ├───tree
        │       driver_tree
        │       driver_tree.c
        │       driver_tree.exe
        │       tree.c
        │       tree.h
        │
        └───wordmachine
                driver_wordmachine.c
                wordmachine.c
                wordmachine.h
   
```

<a name="author"></a>

## Author
<h4 align="center">
    Created by Kelompok K02/J<br/>
    2022
</h4>
<hr>
