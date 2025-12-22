# lab-project
smart cash


#rules program

✅ VALIDASI KODE BARANG:
   - Harus tepat 6 digit
   - Hanya angka (0-9)
   - Contoh valid: "001234", "999999"
   - Contoh invalid: "123" (terlalu pendek), "12A345" (ada huruf)

✅ VALIDASI NAMA BARANG:
   - Minimal 2 karakter
   - Hanya huruf dan spasi
   - Contoh valid: "Indomie Goreng", "Sabun Mandi"
   - Contoh invalid: "Mie1" (ada angka), "@Buku" (ada simbol)

✅ SISTEM KEAMANAN:
   - Password admin: "admin123"
   - 3x percobaan login
   - Konfirmasi untuk operasi kritis (hapus, transaksi)



TAMBAH BARANG BARU:
------------------------
Masukkan kode barang (6 digit angka): 123     ❌ Error: harus 6 digit
Masukkan kode barang (6 digit angka): 123456  ✅ Valid
Masukkan kode barang (6 digit angka): 123ABC  ❌ Error: harus angka

Masukkan nama barang (huruf saja): Mie1       ❌ Error: ada angka
Masukkan nama barang (huruf saja): Indomie   ✅ Valid

Masukkan harga: -5000                         ❌ Error: harga positif
Masukkan harga: 3500                          ✅ Valid

Masukkan stok: -10                            ❌ Error: stok tidak negatif
Masukkan stok: 50                             ✅ Valid



