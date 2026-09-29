#include <iostream>
#include <string>
#include <cctype>

using namespace std;


// ===============================
// STRUCT
// ===============================
struct Soal {
    string tema;
    string kata;
    string clue;
};


// ===============================
// FUNCTION
// ===============================
Soal pilihSoal(Soal daftarSoal[], int tema) {
    return daftarSoal[tema - 1];
}


int main() {

    // ===============================
    // ARRAY + STRUCT
    // ===============================
    Soal daftarSoal[5] = {

        {
            "Makanan",
            "GORENGAN",
            "Musuh diet terbesar umat manusia, belinya di pinggir jalan."
        },

        {
            "Tokoh",
            "SOEKARNO",
            "Presiden pertama Indonesia."
        },

        {
            "Lokasi",
            "JOGJA",
            "Kota yang terkenal dengan gudeg dan Malioboro."
        },

        {
            "Benda",
            "KANEBO",
            "Sering raib pas cuci motor, wujudnya kotak licin."
        },

        {
            "Kegiatan Manusia",
            "TIDUR",
            "Kegiatan yang dilakukan saat tubuh butuh istirahat."
        }
    };


    // 1. TIPE DATA
    string kataRahasia;
    string clue;
    int totalSkor = 0;
    int nyawa = 5;
    char mainLagi = 'y';


    // ===============================
    // LOOP GAME
    // ===============================
    while (mainLagi == 'y' || mainLagi == 'Y') {

        // 2. PILIH TEMA
        int tema;

        cout << "\n=== GAME TEBAK KATA RECEH ===" << endl;
        cout << "=== PILIH TEMA ===" << endl;

        cout << "1. Makanan" << endl;
        cout << "2. Tokoh" << endl;
        cout << "3. Lokasi" << endl;
        cout << "4. Benda" << endl;
        cout << "5. Kegiatan Manusia" << endl;

        cout << "\nPilih tema (1-5): ";
        cin >> tema;


        // ===============================
        // VALIDASI PILIHAN
        // ===============================
        if (tema < 1 || tema > 5) {

            cout << "Pilihan tema tidak tersedia!" << endl;
            continue;
        }


        // ===============================
        // FUNCTION DIPANGGIL
        // ===============================
        Soal soalDipilih = pilihSoal(daftarSoal, tema);

        kataRahasia = soalDipilih.kata;
        clue = soalDipilih.clue;


        // Membuat tampilan kata menjadi _____
        string kataTebakan(kataRahasia.length(), '_');

        nyawa = 5;
        bool menang = false;


        cout << "\nTema     : " << soalDipilih.tema << endl;
        cout << "Petunjuk : " << clue << endl;


        // ===============================
        // WHILE LOOP
        // ===============================
        while (nyawa > 0 && kataTebakan != kataRahasia) {

            cout << "Kata     : " << kataTebakan << endl;

            cout << "Nyawa    : ";

            switch (nyawa) {

                case 5:
                    cout << "5" << endl;
                    break;

                case 4:
                    cout << "4" << endl;
                    break;

                case 3:
                    cout << "3" << endl;
                    break;

                case 2:
                    cout << "2" << endl;
                    break;

                case 1:
                    cout << "1" << endl;
                    break;
            }


            string inputTebakan;

            cout << "\nMasukkan 1 huruf: ";
            cin >> inputTebakan;


            // ===============================
            // IF - ELSE
            // ===============================
            if (inputTebakan.length() > 1) {

                cout << "-> Woy! Masukinnya satu huruf aja!\n" << endl;
                continue;
            }


            char hurufTebakan = inputTebakan[0];

            hurufTebakan = toupper(hurufTebakan);

            bool adaHuruf = false;


            // ===============================
            // LOOP MENGECEK HURUF
            // ===============================
            int i = 0;

            while (i < kataRahasia.length()) {

                if (kataRahasia[i] == hurufTebakan) {

                    kataTebakan[i] = hurufTebakan;
                    adaHuruf = true;
                }

                i++;
            }


            if (adaHuruf) {

                cout << "-> Asik, tebakan bener!\n" << endl;

            } else {

                cout << "-> Yahh, huruf ga ada.\n" << endl;
                nyawa--;
            }


            // ===============================
            // BREAK
            // ===============================
            if (kataTebakan == kataRahasia) {

                menang = true;
                break;
            }
        }


        // ===============================
        // HASIL PERMAINAN
        // ===============================
        if (menang) {

            cout << "Kata     : " << kataTebakan << endl;
            cout << "\nKamu menang!" << endl;

            totalSkor += 100;

        } else {

            cout << "\nSayang sekali, nyawa abis." << endl;
            cout << "Katanya: " << kataRahasia << endl;
        }


        cout << "Total Skor kamu: " << totalSkor << endl;


        // ===============================
        // MAIN LAGI
        // ===============================
        cout << "\nMau main lagi? (y/n): ";
        cin >> mainLagi;
    }


    cout << "\n=== PROGRAM SELESAI ===" << endl;
    cout << "Skor akhir kamu: " << totalSkor << endl;


    return 0;
}