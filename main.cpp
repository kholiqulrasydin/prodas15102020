/* Much Kholiqul Rosidin */
/* NIM 20051397058 */
/* 2020B */



/* Mohon Perhatian, Source Code ini Hanya Untuk Operating system Windows. Terimakasih! */



#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <math.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // ini untuk method goto
COORD CursorPosition; // untuk method goto

void gotoXY(int,int);

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void segitigaHeader(int alas, int tinggi, int x){
    gotoXY(18,3); cout << "MENGHITUNG SEGITIGA SIKU-SIKU";
    gotoXY(18,4); cout << "======================================================================================";
    gotoXY(18,5); cout << "Alas (sisi pertama) dari Segitiga Siku-siku = " << alas;
    gotoXY(18,6); cout << "Tinggi (sisi kedua) dari Segitiga Siku-Siku = " << tinggi;
    gotoXY(18,7); cout << "======================================================================================";
    gotoXY(18,10); cout << "(Gunakan Arah Panah Keyboard untuk mengganti posisi kursor)";
    gotoXY(18,x); cout << "->";
}

int segitigaPanjangSisiMiring(int sisiSikuSikuPertama, int tinggiSikuSikuKedua){
    int hasil;
    hasil = sqrt(sisiSikuSikuPertama*sisiSikuSikuPertama + tinggiSikuSikuKedua*tinggiSikuSikuKedua);
    return hasil;
}

void Clear()
{
    system("cls");
    gotoXY(1,1); cout << "Much Kholiqul Rosidin NIM 20051397058 2020B | Program Sederhana";
}

void hitungGajiKaryawan(){
    bool running = true;

    while(running){
        Clear();
    int gaji, jumlahJamKerja;
    char  golongan;
    string golonganUpperCase, pager = "=============================================================", namaKaryawan;
    do {
        Clear();
        gotoXY(18,6);cout << "Masukan Nama Karyawan : "; gotoXY(42,6);getline(cin, namaKaryawan);
    }while(namaKaryawan.length() < 1);

    cout << endl;
    gotoXY(18,7);cout << pager << endl;
    gotoXY(18,8);cout << "PILIH GOLONGAN" << endl;
    gotoXY(18,9);cout << "ketik a untuk Golongan A Lalu Tekan Enter" << endl;
    gotoXY(18,10);cout << "ketik b untuk Golongan B Lalu Tekan Enter" << endl;
    gotoXY(18,11);cout << "ketik c untuk Golongan C Lalu Tekan Enter" << endl;
    gotoXY(18,12);cout << "ketik d untuk Golongan D Lalu Tekan Enter" << endl << endl;
    gotoXY(18,13);cout << "Masukan Golongan : "; cin >> golongan; cout << endl;
    gotoXY(18,14);cout << pager << endl;
    gotoXY(18,15);cout << "Masukan jumlah jam kerja selama seminggu : "; cin >> jumlahJamKerja; cout << endl;
    switch(golongan){

    case 'a':
        {
            gaji = 5000;
            break;
        }
    case 'b':
        {
            gaji = 7000;
            break;
        }
    case 'c':
        {
            gaji = 8000;
            break;
        }
    case 'd':
        {
            gaji = 10000;
            break;
        }
    default:
        {
            gaji = 0;
            break;
        }

    }

    if(jumlahJamKerja > 48){
            gaji = gaji * 48;
            gaji += (jumlahJamKerja - 48) * 4000;
            gaji = gaji*4;
    }else if (jumlahJamKerja <= 48 && gaji != 0){
        gaji = gaji * jumlahJamKerja;
        gaji = gaji * 4;
    }else if(gaji == 0){
        gaji = 0;
    }else if(jumlahJamKerja < 1){
        gaji = 0;
        jumlahJamKerja = 0;
    }

    Clear();
    golonganUpperCase = ::toupper(golongan);
    gotoXY(18,5);
    gotoXY(18,6);cout << "Halo " << namaKaryawan << endl;
    gotoXY(18,7);cout << "Anda Golongan " << golonganUpperCase << endl;
    gotoXY(18,8);cout << "Gaji Anda Rp. " << gaji << ",- " << "per-bulan" << endl << endl << endl;

    if(gaji == 0 && jumlahJamKerja > 0){
        Clear();
        gotoXY(18,5);
        cout << "Error. Golongan Tidak diketahui" << endl;
    }else if(gaji == 0 && jumlahJamKerja == 0){
        Clear();
        gotoXY(18,5);
        cout << "Mohon Maaf Jumlah jam Kerja Tidak Diketahui" << endl;
    }

    gotoXY(18,10);cout << "Apakah Anda Ingin Mengulangi Penghitungan gaji karyawan Lagi?";
    gotoXY(18,11);cout << "Ketuk tombol enter jika iya, ketuk tombol spasi jika ingin kembali ke menu awal";
    system("pause>nul");

    if(GetAsyncKeyState(VK_RETURN)){
        running = true;
    }
    if(GetAsyncKeyState(VK_SPACE)){
        running = false;
    }
    }
}

int segitigaLuas(int alas, int tinggi){
    int hasil;
    hasil = 0.5 * alas * tinggi;
    return hasil;
}

int segitigaKeliling(int alas, int tinggi){
    int keliling;
    int miring = sqrt(alas*alas + tinggi*tinggi);
    keliling = alas + tinggi + miring;
    return keliling;
}

void tampilkanIndexNol(int panjangSisiMiring){
    gotoXY(55,11); cout << " | Panjang Sisi Miring = " << panjangSisiMiring;
}

void tampilkanIndexSatu(int luas){
    gotoXY(55,12); cout << " | Luas Segitiga Siku-Siku = " << luas;
}

void tampilkanIndexDua(int keliling){
    gotoXY(55,13); cout << " | Keliling Segitiga Siku-Siku = " << keliling;
}


void menghitungSegitigaSikuSiku(){

    int menu_item = 0, x = 11, alas = 0, tinggi = 0, sisiMiring = 0, luas = 0, keliling = 0;
    bool running = true;

    gotoXY(18,3); cout << "MENGHITUNG SEGITIGA SIKU-SIKU";
    gotoXY(18,4); cout << "======================================================================================";
    gotoXY(18,5); cout << "Masukkan Alas (sisi pertama) dari Segitiga Siku-siku : "; cin >> alas;
    gotoXY(18,6); cout << "Masukkan Tinggi (sisi kedua) dari Segitiga Siku-Siku : "; cin >> tinggi;
    gotoXY(18,7); cout << "======================================================================================";

    Clear();
    segitigaHeader(alas, tinggi, x);

    while(running){

            gotoXY(20,11);  cout << "1) Tampilkan panjang sisi miring";
            gotoXY(20,12);  cout << "2) Tampilkan luas";
            gotoXY(20,13);  cout << "2) Tampilkan keliling";
            gotoXY(20,14);  cout << "Hitung Ulang";
            gotoXY(20,15); cout << "Ke menu awal";

		if(alas == 0 && tinggi == 0){
            Clear();
            gotoXY(18,3); cout << "MENGHITUNG SEGITIGA SIKU-SIKU";
            gotoXY(18,4); cout << "======================================================================================";
            gotoXY(18,5); cout << "Masukkan Alas (sisi pertama) dari Segitiga Siku-siku : "; cin >> alas;
            gotoXY(18,6); cout << "Masukkan Tinggi (sisi kedua) dari Segitiga Siku-Siku : "; cin >> tinggi;
            gotoXY(18,7); cout << "======================================================================================";

            gotoXY(20,11);  cout << "1) Tampilkan panjang sisi miring";
            gotoXY(20,12);  cout << "2) Tampilkan luas";
            gotoXY(20,13);  cout << "2) Tampilkan keliling";
            gotoXY(20,14);  cout << "Hitung Ulang";
            gotoXY(20,15); cout << "Ke menu awal";

            Clear();
            segitigaHeader(alas, tinggi, x);
            gotoXY(20,11);  cout << "1) Tampilkan panjang sisi miring";
            gotoXY(20,12);  cout << "2) Tampilkan luas";
            gotoXY(20,13);  cout << "2) Tampilkan keliling";
            gotoXY(20,14);  cout << "Hitung Ulang";
            gotoXY(20,15); cout << "Ke menu awal";
		}
		if(alas != 0 && tinggi != 0 ){
            segitigaHeader(alas, tinggi, x);
		}
		if(sisiMiring != 0){
            tampilkanIndexNol(sisiMiring);
		}
		if(luas != 0){
            tampilkanIndexSatu(luas);
		}
		if(keliling != 0){
            tampilkanIndexDua(keliling);
		}

		system("pause>nul"); //system paused && null bit karena tidak mengeluarkan output apapun

		if(GetAsyncKeyState(VK_DOWN) && x != 15)
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;

			}

		if(GetAsyncKeyState(VK_UP) && x != 11)
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){

			switch(menu_item){

				case 0: {
				    sisiMiring += segitigaPanjangSisiMiring(alas, tinggi);
				    Clear();
				    menu_item += 1;
				    x += 1;
				    running = true;
					break;
				}


				case 1: {
                    luas += segitigaLuas(alas, tinggi);
                    Clear();
                    menu_item -= 1;
                    menu_item += 2;
				    x -= 1;
				    x += 2;
                    running = true;
					break;
				}
				case 2: {
				    keliling += segitigaKeliling(alas, tinggi);
				    Clear();
				    menu_item -= 1;
                    menu_item += 2;
				    x -= 1;
				    x += 2;
				    running = true;
					break;
				}

				case 3: {
				    alas -= alas;
				    tinggi -= tinggi;
				    luas -= luas;
				    keliling -= keliling;
				    sisiMiring -= sisiMiring;
				    Clear();
				    menu_item -= 3;
				    x -= 14;
				    x += 11;
					running = true;
					break;
				}

				case 4: {
				    Clear();
				    menu_item -= 4;
				    x -= 15;
					running = false;
				}

			}

		}

	}
}





void menuheader(){
        gotoXY(1,1); cout << "Much Kholiqul Rosidin NIM 20051397058 2020B";
	    gotoXY(18,5); cout << "Main Menu";
	    gotoXY(18,6); cout << "(Gunakan Arah Panah Keyboard untuk mengganti posisi kursor)\n";
        gotoXY(18,8); cout << "->";
}

int main()
{

    int menu_item = 0, x=8;
	bool running = true;
	menuheader();

	while(running)
	{
        gotoXY(20,8);  cout << "1) Hitung Gaji Karyawan";
		gotoXY(20,9);  cout << "2) Hitung Segitiga siku-siku";
		gotoXY(20,10); cout << "Keluar Program";

		system("pause>nul"); //system paused && null bit karena tidak mengeluarkan output apapun

		if(GetAsyncKeyState(VK_DOWN) && x != 10)
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;

			}

		if(GetAsyncKeyState(VK_UP) && x != 8)
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){

			switch(menu_item){

				case 0: {
					gotoXY(20,16);
					hitungGajiKaryawan();
					    Clear();
                        menuheader();
                        menu_item -= menu_item;
                        x -= x;
                        x += 8;
                        running = true;
					break;
				}


				case 1: {
					gotoXY(20,16);
					Clear();
					menghitungSegitigaSikuSiku();
                        Clear();
                        menuheader();
                        menu_item -= menu_item;
                        x -= x;
                        x += 8;
                        running = true;
					break;
				}

				case 2: {
					gotoXY(20,16);
					cout << "Terimakasih Telah menggunakan Program ini";
					running = false;
				}

			}

		}

	}

	gotoXY(20,21);

    return 0;

    }



