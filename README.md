# lab-project
Smart Cash

# Deskripsi Aplikasi: Smart Cash
Smart Cash adalah aplikasi kasir sederhana berbasis terminal yang dirancang untuk membantu pengelolaan transaksi penjualan dan data barang secara cepat, aman, dan terstruktur. Aplikasi ini memiliki fitur utama berupa input data barang, pencatatan transaksi, pencarian barang, serta sistem login admin untuk menjaga keamanan data.

# Tujuan
- Mempermudah admin dalam mengelola data barang (kode, nama, harga, stok).
- Memastikan transaksi penjualan berjalan lancar dengan aturan input yang ketat.
- Menyediakan sistem pencarian barang yang fleksibel berdasarkan nama atau kode.
- Menjaga keamanan dengan sistem login admin dan password.

# Fitur Utama
- Input Barang (Admin):  
  Admin dapat menambahkan barang baru dengan validasi ketat pada kode, nama, harga, dan stok.

- Transaksi Penjualan:  
  User dapat melakukan pembelian barang dengan sistem konfirmasi transaksi dan validasi stok.

*Sistem Member:  
Mendukung input status member untuk transaksi.

- Login Admin:  
  Menggunakan password dengan batas percobaan tertentu untuk keamanan.

- Menu Pilihan:  
  Navigasi sederhana dengan input angka sesuai opsi menu.

- Pencarian Barang:  
  - Bisa mencari barang berdasarkan nama (parsial, tidak case-sensitive) atau kode barang.
  - Penyimpanan Data:
  - Data barang otomatis tersimpan di barang.txt
  - Struk transaksi tersimpan di struk.dat
  - Password admin tersimpan di admin_pass.txt

# Keamanan & Validasi
- Input harus sesuai format (angka bulat, huruf, spasi).
- Tidak boleh ada duplikasi kode/nama barang.
- Program otomatis keluar setelah transaksi selesai untuk mencegah kesalahan berulang.
- Kesalahan input (misalnya huruf di tempat angka) akan menyebabkan error/loop sehingga user harus mengikuti aturan input dengan benar.

#rules program

Berdasarkan kode program yang kamu berikan, berikut adalah **rules yang perlu diperhatikan oleh user saat menginput data:

RULES UMUM INPUT:
1. Tekan ENTER setelah setiap input
2. Hindari karakter khusus** seperti `|`, `\`, `/`, `"`, `'` kecuali yang diizinkan
3. Gunakan format yang tepat sesuai petunjuk

1. INPUT BARANG (Untuk Admin)

KODE BARANG:
- Harus tepat 6 digit angka (tidak kurang/tidak lebih)
- Contoh valid: `123456`, `000001`
- Contoh invalid: `12345`, `1234567`, `abc123`
- Tidak boleh duplikat dengan kode yang sudah ada
- Input `0` untuk kembali

NAMA BARANG:
- Minimal 2 karakter
- Hanya boleh huruf dan spasi
- Tidak boleh angka atau karakter khusus
- Tidak boleh duplikat dengan nama yang sudah ada
- Contoh valid: `Mie Goreng`, `Sabun Mandi`
- Contoh invalid: `Mie123`, `Sabun@`, `A`
- Input `0` untuk kembali

HARGA:
- Harus angka bulat positif (> 0)
- Tidak boleh desimal, koma, atau huruf
- Contoh valid: `5000`, `15000`
- Contoh invalid: `5.000`, `15,000`, `lima ribu`
- Input `0` untuk kembali

STOK:
- Harus angka bulat ≥ 0
- Tidak boleh negatif
- Contoh valid: `0`, `10`, `100`
- Contoh invalid: `-5`, `sepuluh`
- Input `0` untuk kembali

2. INPUT TRANSAKSI

KODE BARANG (saat transaksi):
- Input kode 6 digit seperti di atas, atau:
- Ketik `SELESAI` untuk menyelesaikan transaksi
- Ketik `0` untuk membatalkan transaksi

JUMLAH BELI:
- Harus angka bulat positif
- Tidak boleh melebihi stok yang tersedia
- Contoh: jika stok 10, input `5` (valid), `15` (invalid)

KONFIRMASI MEMBER:
- Input `1` untuk Member
- Input `0` untuk Non-Member
- Tidak ada input lain yang diterima

KONFIRMASI TRANSAKSI:
- Input `y` atau `Y` untuk konfirmasi
- Input `n` atau `N` untuk membatalkan
- Program akan langsung keluar** setelah transaksi berhasil

3. LOGIN ADMIN

PASSWORD:
- Maksimal 49 karakter
- Case-sensitive (huruf besar/kecil berpengaruh)
- 3 kali percobaan gagal → akses ditolak
- Default password: `admin123`

4. MENU PILIHAN

ANGKA PILIHAN:
- Input harus angka bulat sesuai opsi menu
- Contoh: di menu utama, input `1`, `2`, `3`, atau `4`
- Input selain angka akan dianggap invalid
- Tidak perlu tanda titik/koma

5. PENCARIAN BARANG

BERDASARKAN NAMA:
- Bisa input sebagian nama
- Tidak case-sensitive (otomatis diubah ke huruf kecil)
- Contoh: cari `mie` akan menemukan `Mie Goreng`, `Indomie`
- Input `0` untuk kembali

BERDASARKAN KODE:
- Harus tepat 6 digit angka
- Input `0` untuk kembali

6. PERINGATAN KHUSUS:

1. Program keluar otomatissetelah transaksi selesai
2. Data otomatis tersimpandi file `barang.txt`
3. Struk tersimpan di file `struk.dat`
4. Password admintersimpan di `admin_pass.txt`
5. Input huruf di tempat yang meminta angka akan menyebabkan error/loop
6. Spasi di awal/tengah diperbolehkan untuk nama barang
7. Tombol Enter harus ditekan setelah setiap input
