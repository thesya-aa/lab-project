# lab-project
smart cash


#rules program

Berdasarkan kode program yang kamu berikan, berikut adalah **rules yang perlu diperhatikan oleh user** saat menginput data:

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
- Harus **angka bulat positif** (> 0)
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
