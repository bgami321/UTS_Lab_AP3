// TODO 1: Ubah nama file ini menjadi NIM Anda. Cth: 001.cpp, 042.cpp, 080.cpp

// TODO 2: Buat program anda di file ini. INGAT BERI KOMENTAR PADA SETIAP PROSES DALAM PROGRAM ANDA

// TODO 3: Selesaikan dan kumpulkan sebelum deadline yang telah ditentukan; Details ada dalam file README.md

// Tetap semangat walau sulit ;p

#include <iostream>
using namespace std;

// Fungsi untuk memeriksa apakah nomor kartu valid menggunakan algoritma Luhn
int checksum(char cardNumber[], int length) {
    int sum = 0;
    bool isSecond = false;
    for (int i = length - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0'; //dikurang ascii untuk mendapatkan digit value sebenarnya
        if (isSecond) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
        isSecond = !isSecond;
    }
    return sum;
}

// Fungsi untuk mendeteksi tipe kartu berdasarkan nomor kartu
string detectCardType(char cardNumber[], int length) {
    if ((length == 16) && 
        (cardNumber[0] == '5' && (cardNumber[1] >= '1' && cardNumber[1] <= '5'))) {
        return "MASTERCARD";
    } else if ((length == 13 || length == 16) && cardNumber[0] == '4') {
        return "VISA";
    } else {
        return "TIDAK DIKETAHUI";
    }
}

int main() {
    const int MAX_LENGTH = 19; // maksimum 16 digit + 1 karakter akhir string ('\0')
    char cardNumber[MAX_LENGTH];
    cout << "Masukkan angka kartu: ";
    cin.getline(cardNumber, MAX_LENGTH);

    // Menghitung panjang nomor kartu
    int length = 0;
    while (cardNumber[length] != '\0') {
        length++;
    }

    // Memeriksa validitas nomor kartu
    int checksumValue = checksum(cardNumber, length);

    // Menentukan tipe kartu
    string cardType = detectCardType(cardNumber, length);

    // Output hasil
    cout << "Nomor kartu anda: " << cardNumber << endl;
    cout << "Tipe kartu anda: " << (checksumValue % 10 == 0 ? cardType : "TIDAK VALID") << endl;
    cout << "Checksum: " << checksumValue;

    return 0;
}