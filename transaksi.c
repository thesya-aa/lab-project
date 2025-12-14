#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_ITEMS 50

// Struktur Barang konsisten dengan Admin/Customer
struct Barang {
    char kode[20];
    char nama[50];
    int harga;
    int stok;
} daftar[MAX];

int jumlah = 0;

// Struktur Transaksi
struct Transaksi {
    char kodeBarang[20];
    char namaBarang[50];
    int jumlahBeli;
    int hargaSatuan;
    int subTotal;
};

// ================= Kurangi Stok =================
void kurangiStock(const struct Transaksi keranjang[], int jumlahItem) {
    printf("\n--- Kurangi Stok ---\n");
    for (int i = 0; i < jumlahItem; i++) {
        char *kode = keranjang[i].kodeBarang;
        int jumlahBeli = keranjang[i].jumlahBeli;

        for (int j = 0; j < jumlah; j++) {
            if (strcmp(daftar[j].kode, kode) == 0) {
                daftar[j].stok -= jumlahBeli;
                printf("Stok %s dikurangi %d. Sisa: %d\n",
                       daftar[j].nama, jumlahBeli, daftar[j].stok);
                break;
            }
        }
    }
}

// ================= Cetak Struk =================
void cetakStruk(const struct Transaksi keranjang[], int jumlahItem,
                double totalHarga, double diskon, double totalAkhir, int isMember) {
    printf("\n        STRUK TRANSAKSI\n");
    printf("==================================\n");
    printf("STATUS: %s\n", isMember ? "Member" : "Non-Member");
    printf("----------------------------------\n");

    for (int i = 0; i < jumlahItem; i++) {
        printf("%d. %s\n", i + 1, keranjang[i].namaBarang);
        printf("   %d x %d \t\tRp %d\n",
               keranjang[i].hargaSatuan,
               keranjang[i].jumlahBeli,
               keranjang[i].subTotal);
    }

    printf("----------------------------------\n");
    printf("Total Harga Awal:\tRp %.0f\n", totalHarga);
    printf("Diskon:\t\t\tRp -%.0f\n", diskon);
    printf("TOTAL AKHIR:\t\tRp %.0f\n", totalAkhir);
    printf("==================================\n");

    // Simpan ke file
    FILE *fp = fopen("struk.dat", "w");
    if (fp != NULL) {
        fprintf(fp, "STATUS: %s\n", isMember ? "Member" : "Non-Member");
        for (int i = 0; i < jumlahItem; i++) {
            fprintf(fp, "%s x%d = Rp %d\n",
                    keranjang[i].namaBarang,
                    keranjang[i].jumlahBeli,
                    keranjang[i].subTotal);
        }
        fprintf(fp, "Total: Rp %.0f\nDiskon: Rp %.0f\nTOTAL BAYAR: Rp %.0f\n",
                totalHarga, diskon, totalAkhir);
        fclose(fp);
    }
}

// ================= Diskon =================
double hitungDiskon(double totalHarga, int member) {
    if (member && totalHarga >= 300000) return totalHarga * 0.30;
    else if (member && totalHarga >= 150000) return totalHarga * 0.20;
    else if (!member && totalHarga >= 200000) return totalHarga * 0.15;
    else if (!member && totalHarga >= 150000) return totalHarga * 0.10;
    return 0;
}

// ================= Cari Barang =================
int cariBarang(const char *kode) {
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(daftar[i].kode, kode) == 0) {
            return i;
        }
    }
    return -1;
}

// ================= Proses Transaksi =================
void prosesTransaksi() {
    struct Transaksi keranjang[MAX_ITEMS];
    int jumlahItem = 0;
    double totalHarga = 0.0;
    char kodeInput[20];

    printf("\n--- Mulai Proses Transaksi ---\n");
    printf("Ketik 'SELESAI' untuk mengakhiri.\n");

    while (jumlahItem < MAX_ITEMS) {
        printf("\nMasukkan Kode Barang (atau SELESAI): ");
        scanf("%s", kodeInput);

        if (strcmp(kodeInput, "SELESAI") == 0) break;

        int idx = cariBarang(kodeInput);
        if (idx == -1) {
            printf("[ERROR] Kode barang tidak ditemukan.\n");
            continue;
        }

        int jumlahBeli;
        printf("Jumlah beli (%s, stok %d): ",
               daftar[idx].nama, daftar[idx].stok);
        scanf("%d", &jumlahBeli);

        if (jumlahBeli <= 0 || jumlahBeli > daftar[idx].stok) {
            printf("[ERROR] Stok tidak cukup atau jumlah tidak valid.\n");
            continue;
        }

        keranjang[jumlahItem].jumlahBeli = jumlahBeli;
        strcpy(keranjang[jumlahItem].kodeBarang, daftar[idx].kode);
        strcpy(keranjang[jumlahItem].namaBarang, daftar[idx].nama);
        keranjang[jumlahItem].hargaSatuan = daftar[idx].harga;
        keranjang[jumlahItem].subTotal = jumlahBeli * daftar[idx].harga;

        totalHarga += keranjang[jumlahItem].subTotal;
        daftar[idx].stok -= jumlahBeli;
        jumlahItem++;

        printf("Item ditambahkan! Total sementara: Rp %.0f\n", totalHarga);
    }

    if (jumlahItem == 0) {
        printf("\nTransaksi dibatalkan. Tidak ada item.\n");
        return;
    }

    int isMember;
    printf("\nApakah pelanggan member? (1=Ya, 0=Tidak): ");
    scanf("%d", &isMember);

    double diskon = hitungDiskon(totalHarga, isMember);
    double totalAkhir = totalHarga - diskon;

    cetakStruk(keranjang, jumlahItem, totalHarga, diskon, totalAkhir, isMember);
}

// ================= Main =================
int main() {
    // contoh data dummy
    strcpy(daftar[0].kode, "A001");
    strcpy(daftar[0].nama, "Sabun Mandi");
    daftar[0].harga = 10000;
    daftar[0].stok = 20;
    jumlah++;

    strcpy(daftar[1].kode, "B002");
    strcpy(daftar[1].nama, "Shampoo");
    daftar[1].harga = 25000;
    daftar[1].stok = 15;
    jumlah++;

    strcpy(daftar[2].kode, "C003");
    strcpy(daftar[2].nama, "Pasta Gigi");
    daftar[2].harga = 15000;
    daftar[2].stok = 10;
    jumlah++;

    prosesTransaksi();
    return 0;
}
