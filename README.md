# praktikum-itp-m5

## Praktikum ITP M5

### No 1

Buatlah permainan blackjack player vs com sederhana.Permainan ini merupakan permainan kartu yang hanya dapat memilih antara hit atau surrend. Jika pemain (player atau com) memilih Hit, maka tambahkan kartu kiri pemain dengan kartu random yang didapatkan (Jika jumlah dari kartu kiri dan kanan lebih dari 21 maka pemain pemilik kartu tersebut akan kalah namun jika jumlah kartu adalah 21 maka pemain tersebut akan jadi pemenang dan permainan berakhir). Jika pemain memilih surrend, maka pemain tersebut akan kalah.

Pada awal permainan, randomlah masing-masing 2 kartu player maupun com (Kartu AS memiliki nilai 11, sedangkan Jack, Queen, King memiliki nilai 10. Pastikan perbandingan kemungkinan random kartu benar!). Jika saat di random salah satu pemain mendapatkan kartu dengan jumlah 21 maka pemain tersebut akan langsung menjadi pemenang, Jika saat di random salah satu pemain mendapatkan kartu dengan jumlah lebih dari 21 maka pemain tersebut kalah. Jika saat di random kedua pemain mendapatkan kartu dengan jumlah 21 atau kedua pemain mendapatkan kartu dengan jumlah diatas 21, maka draw. Kartu kiri milik com tidak dapat dilihat oleh player (akan selalu tanda tanya), jika player ingin melihat kartu kiri com maka player harus menginputkan angka 99 yang merupakan cheat untuk mengintip nilai kartu kiri com, jika player menginputkan 69 maka program akan menampilkan detail nilai semua kartu beserta jumlahnya, jika player menginputkan 1 maka player melakukan hit lalu akan menjadi giliran com, dan jika player menginputkan 2 maka player melakukan surrend. Saat giliran com, maka randomlah pilihan com (surrend atau hit), jika hit dan permainan masih berlanjut maka akan menjadi giliran player. (Jika inputan player bukan 1, 2, 69, 99 program akan meminta inputan terus menerus hingga inputan benar). Berikut merupakan contoh tampilan permainan.

![image](https://github.com/user-attachments/assets/6ce0891f-f24e-4a6f-9cb4-2bb087e1b51a)

```
Turn : Player
1. Hit
2. Surrend
>>> 99
Player is a Cheater!
Kartu Kiri com : 2
Turn : Player
1. Hit
2. Surrend
>>> 69
Player is a Cheater!
Kartu Kanan Com    : 10
Karti Kiri Com     :  2
Jumlah Kartu Com   : 12
Kartu Kanan Player :  2
Karti Kiri Player  :  3
Jumlah Kartu Player: 15
Turn : Player
1. Hit
2. Surrend
>>> 1
Player mendapatkan kartu As!
```

![image](https://github.com/user-attachments/assets/80b46c74-a6e5-4dc5-8e96-9c831991a662)

```
Turn : Com
Com memilih Hit!
Com mendapatkan kartu 3!
```

![image](https://github.com/user-attachments/assets/44b252aa-8d48-470c-aec7-d77cddc9462d)

```
Turn : Player
1. Hit
2. Surrend
>>> 99
Player is a Cheater!
Kartu Kiri com : 5

Turn : Player
1. Hit
2. Surrend
>>> 2
Player Menyerah dengan jumlah kartu 16!
Pemenangnya adalah COM dengan jumlah kartu 15!
```

### Tugas

Buatlah Harvest Moon Mining sederhana yang memiliki arena mining dungeon berukuran 15 x 7 (termasuk dinding, one base). Setiap dungeon pasti berukuran 15 x 7 dan akan selalu memiliki tangga dengan symbol ‘#’ di posisi ( 2 , 2 ) serta memiliki 3 stone mining yang posisinya akan di random setiap kali memasuki arena mining dungeon dan di simbolkan ‘x’ (Pastikan stone tidak menimpa dinding, player, tangga, pintu keluar dungeon dan stone lainnya). Dungeon Lt 1 akan memiliki pintu keluar arena mining yang akan berada di posisi ( 7 , 7 ) – ( 9 , 7 ) seperti pada contoh di bawah.

Pada awal permainan, player akan berada di Dungeon Lv 1 posisi ( 8 , 6) yang di simbolkan ‘P’. Player pada saat ini hanya memiliki 500G dan 100 stamina saja. Berikut merupakan tampilan awal Menu Utama:

MENU UTAMA\
![image](https://github.com/user-attachments/assets/ef8d7b6f-acd5-4777-8353-6abca09f49bb)

MENU 1 : MOVEMENT\
Menu Movement akan muncul ketika player menginputkan 1 pada Menu Utama. Pada menu ini, player dapat bergerak ke atas, ke kiri, ke bawah dan ke kanan serta melakukan mine. Setelah menginputkan movement yang diinginkan maka tampilkan keadaan arena setelah movement dan mintalah inputan movement kembali hingga player menginputkan 0. Jika player menginputkan 0 maka kembalikan ke Menu Utama. Saat player bergerak, pastikan player tidak dapat menembus dinding serta menimpa stone (‘x’), Player dapat menimpa tangga dan ketika player menimpa tangga maka pindahkan player ke dungeon Lt selanjutnya (ukuran dungeon sama, posisi player di tengah dungeon, spawn 3 stone dengan posisi random). Berikut merupakan contoh tampilan menu Movement dan contoh jika bergerak ke atas:

![image](https://github.com/user-attachments/assets/37dd0c4b-e5ca-4db0-81f5-dbd9971bb3f1)

MENU MOVEMENT [1]\
Menu movement ini berfungsi untuk menggerakkan player ke atas.

MENU MOVEMENT [2]\
Menu movement ini berfungsi untuk menggerakkan player ke kiri.

MENU MOVEMENT [3]\
Menu movement ini berfungsi untuk menggerakkan player ke bawah.

MENU MOVEMENT [4]\
Menu movement ini berfungsi untuk menggerakkan player ke kanan.

MENU MOVEMENT [5]\
Menu movement ini berfungsi untuk melakukan mining. Jika player memilih movement ini maka ceklah sekitar player (atas, kanan, kiri, bawah player), jika ada stone maka hilangkan stone tersebut lalu randomlah item apa yang didapatkan dari stone tersebut beserta jumlahnya. Berikut merupakan item yang dapat di dapatkan dari mining stone beserta harga jual nya:

| Name     | Qty Drop Item | Price     |
| -------- | ------------- | --------- |
| Stone    | 5-10          | 10G / pc  |
| Mythrill | 1-2           | 200G / pc |
| Crystal  | 1             | 500G / pc |

Ketika player menimpa pintu keluar yang berada di Dungeon Lt 1 posisi ( 7 , 7 ) – ( 9 , 7 ), maka tampilkan menu untuk menjual barang seperti contoh di bawah ini. Program akan meminta inputan barang mana yang ingin dijual (Jika player menginputkan 0, maka kembalikan player pada menu utama, dan player berada di dungeon 1 posisi 8, 6), serta setelah itu akan meminta jumlah barang yang ingin dijual. Pastikan jumlah barang yang di jual tidak dapat melebihi jumlah barang yang dimiliki player. Berikut contoh dari store: (Jika penjualan berhasil, pastikan uang dan jumlah barang terupdate)

```
STORE
-----------------------------
1. Stone
2. Mythrill
3. Crystal
0. Back Mining
>>> 1
Berapa banyak yang ingin dijual?
>>> 999
Gagal menjual, stone anda hanya 10.

STORE
-----------------------------
1. Stone
2. Mythrill
3. Crystal
0. Back Mining
>>> 1
Berapa banyak yang ingin dijual?
>>> 10
Berhasil menjual stone sebanyak 10.
Gold +100G
Stone -10
```

MENU 2 : BAG\
Menu ini akan menampilkan item yang dimiliki player. Berikut merupakan contoh tampilan.

```
BAG
-----------------------------
Stone                 -   10x
Mythrill              -    2x
Crystal               -    0x
```

MENU 3 : Back To First Dungeon\
Menu ini akan membuat player berada di dungeon pertama dengan posisi player sama seperti saat pertama kali memulai permainan. Stone akan terspawn kembali dengan posisi random.

MENU 0 : Exit Program\
Menu ini berfungsi untuk keluar dari program. Sebelum keluar program, tampilkan pesan permainan berakhir terlebih dahulu.

```
Permainan berakhir, Bye Bye~
```
