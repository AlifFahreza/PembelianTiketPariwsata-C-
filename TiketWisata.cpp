//Nama : Muhammad Alif Fahreza Al Rafi
//NIM : 200533628024
//Prodi : S1 Pendidikan Teknik Informatika B

#include <iostream.h>//Digunakan untuk memanggil perintah cin dan cout
#include <windows.h>//Digunakan untuk memanggil perintah penempatan posisi kursor atau koordinat x dan y
#include <conio.h>//Digunakan untuk memanggil perintah getch()
#include <fstream.h>//Digunakan dalam pemanggilan, dan pembuatan file
#include <sstream>//Digunakan untuk memanggil perintah yang berfungsi memberi format titik "." pada harga
#include <string>//Digunakan untuk memanggil tipe data string
using namespace std;//Digunakan untuk memberitahukan kepada kompiler bahwa kita akan menggunakan semua fungsi, class atau file yang terdapat pada memori namespace std

int i, hari, anakanak, dewasa, tempat, hargaweekdaysA, hargaweekdaysD, hargaweekendA, hargaweekendD, tempatpublik, total_tiket, rekaptempat, bayar, kembalian;
string namahari[] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};//Array dengan isi pada modul 5
string *day;//variabel pointer
string kasir = "Alif Fahreza";
char username[100], pass[100]/*Array satu dimensi*/, tanya, pilihan2, lanjut, namaanak[100][100], namadewasa[100][100];//Array dua dimensi pada modul 5

/* Deklarasi Fungsi readPass untuk mengubah inputan password menjadi karakter "*" */
void readPass(char *);

/* koordinat adalah fungsi untuk memberikan koordinat letak pada program */
void koordinat(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

/* Fungsi untuk mengecek inputan hanya mengandung huruf atau tidak */
bool IsLetters(string input)
{
	for (int i = 0; i < input.size(); i++)//Perulangan FOR seperti pada modul 4
	{
		int uppercaseChar = toupper(input[i]); //Konversi karakter ke versi upper case dari karakter
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //Jika karakter bukan A-Z
		{
			return false;
		}
	}
	
	return true; //Return true jika karakter adalah A-Z
}

/* Deklarasi Fungsi Utama untuk pindah ke tampilan yang ada pada fungsi void utama*/
void utama();

/* Deklarasi Fungsi int main untuk pindah ke halaman tersebut*/
int main();

/*Berfungsi untuk menampilkan logo dan tampilan animasi loading*/
void logo()
{
	char a = 3760, b = 3547;//Operator penugasan pada modul 2
    int i, j;
	
	system("cls");//Berfungsi untuk membersihkan layar pada program yang akan dijalankan sehingga pemrogram dapat menenentukan saat untuk menghapus data yang telah dijalankan tanpa harus menutup program tersebut dan membukanya kembali
	system("color 06");//Berfungsi untuk memberi warna light white pada tulisan
	
	/*Berfungsi untuk membentuk tulisan JATIM menggunakan л agar outputnya berbentuk garis*/
	koordinat(73,9);/*Berfungsi untuk memanggil fungsi koordinat dan memberikan nilai pada x dan y agar tulisan tersebut dapat tampil pada letak yang kita inginkan*/
	koordinat(32,11);cout<<"      ллллллл  лллллллл  ллллллл  ллл  лллл   лллл G";
	koordinat(32,12);cout<<"        ллл    ллл  ллл    ллл    ллл  ллллллллллл R";
	koordinat(32,13);cout<<"        ллл    лллллллл    ллл    ллл  ллл ллл ллл O";
	koordinat(32,14);cout<<"   ллл  ллл    ллл  ллл    ллл    ллл  ллл  л  ллл U";
	koordinat(32,15);cout<<"     ллллл     ллл  ллл    ллл    ллл  ллл     ллл P";
    koordinat(32,17);
	
	/*Berfungsi untuk menampilkan animasi loading*/
    for(i = 0; i <= 53; i++)//Perulangan FOR pada modul 4
    {
        cout << a;//Menampilkan output variabel a
    }
    koordinat(32, 17);
    for(i = 0; i <= 53; i++) //operator increment pada modul 2
    {
        if(i == 1)//Percabangan IF modul 3
        {
            koordinat(48, 19); cout << "Openning Program..."; koordinat(33,17);
        }
        if(i == 20)
        {
            koordinat(48, 19); cout << "Wait For A Second..."; koordinat(52,17);
        }
        if(i == 30)
        {
            koordinat(48, 19); cout << "Setup Data........"; koordinat(62,17);
        }
        if(i == 40)
        {
            koordinat(48, 19); cout << "Setup Complete..."; koordinat(72,17);
        }
        cout << b;
        for(j = 0; j <= 1e8/4; j++);
    }
	
    j = 0;
}
	
/* Berfungsi untuk memberi bingkai pada tampilan menggunakan karakter "#" */
void frame()
{
    int i;
    system("cls");//system cls berfungsi untuk membersihkan tampilan layar
    
	/*Perulangan for untuk memberi bingkai secara otomatis*/
	for(i=0; i<=239; i++)
    {
        printf("#");
    }
    for(i=0; i<=25; i++)
    {
        koordinat(0,i); printf("##");
        koordinat(118,i); printf("##");
    }
    for(i=0; i<=239; i++)
    {
        printf("#");
    }
}

/* fungsi bernama format angka untuk mengubah dan mengembalikan nilai mata uang agar ada titik pada ribuan, ratusan dsb serta memberikan tulisan Rp. */
string formatAngka(int angka, string perantara = ".") {
	stringstream ss; 
	ss << angka; 
	string output = ss.str();
	int inspost = output.length() - 3;
	
	while (inspost > 0)//Menggunakan perulangan while pada modul 4
	{
		output.insert(inspost, perantara);
		inspost -= 3;
	}
	return "Rp. " + output + ",-";//Mengembalikan nilai output dengan format yang telah ditentukan
}

/*Fungsi untuk menampilkan tampilan error jika user salah menginputkan*/
void salah(){
	system("cls");//Berfungsi untuk membersihkan layar pada program yang akan dijalankan sehingga pemrogram dapat menenentukan saat untuk menghapus data yang telah dijalankan tanpa harus menutup program tersebut dan membukanya kembali
	system("color 0C");//Berfungsi untuk memberikan warna merah pada tampilan tulisan
	
	koordinat(32,10);cout<<"     лллллл  лллллллл  ллл      лллллллл  ллл  ллл";
	koordinat(32,11);cout<<"     ллл     ллл  ллл  ллл      ллл  ллл  ллл  ллл";
	koordinat(32,12);cout<<"     лллллл  лллллллл  ллл      лллллллл  лллллллл";
	koordinat(32,13);cout<<"        ллл  ллл  ллл  ллл      ллл  ллл  ллл  ллл";
	koordinat(32,14);cout<<"     лллллл  ллл  ллл  ллллллл  ллл  ллл  ллл  ллл";
	koordinat(49,16); cout << "Inputan Anda Tidak Valid";
	koordinat(42,17); cout << "Tekan Tombol Apa Saja Untuk Kembali";
	getch();//Berfungsi untuk membaca sebuah karakter dengan sifat karakter yang dimasukkan tidak perlu diakhiri dengan menekan tombol ENTER, dan karakter yang dimasukan tidak akan ditampilkan di layar
}

void cetakrekap(){
	char yo;
	/*Berfungsi untuk inputan destinasi wisata oleh user*/
	koordinat(35,23); cout << "Apakah Anda Ingin Mencetak Ulang Tiket Tersebut [Y]? : ";
	cin >> yo;
		
	if (yo=='y'||yo=='Y')//Percabangan IF jika memilih Y atau y
	{
		system ("Rekap_Tiket.txt");
		utama();
	}
	else 
	{
		utama();
	}
}

void rekap(){
	
	system("cls");
	system("color 0B"); //Memberi Warna Biru Pada Output
	frame();//Memanggil fungsi frame
	
	/*Berfungsi untuk memberi garis menggunakan karakter "#" pada bagian atas dalam bingkai*/
	koordinat(0,5);
	for(i = 0; i <= 119; i++)
	{
		cout << "#";
	}
	
	koordinat(47,3); cout << "Pemesanan Tiket terakhir";
	
	if(rekaptempat == 0){
		
		koordinat(47,12); cout << "Belum Ada Pembelian Tiket";
		koordinat(38,13); cout << "Tekan Apa Saja Untuk Kembali Ke Menu Utama";
		getch();
		utama();
		
	}else{
		ofstream rekap_tiket;//Berfungsi untuk membuka file dalam mode menulis
		rekap_tiket.open("Rekap_Tiket.txt");//Berfungsi untuk menunjuk ke sebuah nama file
	
		cout << "\n\n\n\n\n";
		cout<<"\t\tNama Kasir : " << kasir << endl;
		cout <<"\t\tTotal Yang Harus Dibayar : " << formatAngka(total_tiket) << endl;
		cout <<"\t\tNominal Pembayaran : " << formatAngka(bayar) << endl;
		cout <<"\t\tKembalian : " << formatAngka(kembalian) << endl;
		cout<<"\t\tNama Tempat Pariwisata yang Dipilih : ";
		
		rekap_tiket<<"===============================================================\n";
		rekap_tiket<<"\t\tRekap Pemesanan Tiket Terakhir";
		rekap_tiket<<"\n===============================================================\n";
		rekap_tiket<<"Nama Kasir : " << kasir << endl;
		rekap_tiket<<"Total Yang Harus Dibayar : " << formatAngka(total_tiket) << endl;
		rekap_tiket<<"Nominal Pembayaran : " << formatAngka(bayar) << endl;
		rekap_tiket<<"Kembalian : " << formatAngka(kembalian);
		rekap_tiket<<"Nama Tempat Pariwisata yang Dipilih : ";
		
		if(rekaptempat == 1){
			
			cout << "Jawa Timur Park 1";
			rekap_tiket << "Jawa Timur Park 1";
			
		}else if(rekaptempat == 2){
			
			cout << "Jawa Timur Park 2";
			rekap_tiket << "Jawa Timur Park 2";
			
		}else if(rekaptempat == 3){
			
			cout << "Jawa Timur Park 3";
			rekap_tiket << "Jawa Timur Park 3";
			
		}else if(rekaptempat == 4){
			
			cout << "Batu Secret Zoo";
			rekap_tiket << "Batu Secret Zoo";
			
		}else if(rekaptempat == 5){
			
			cout << "Museum Angkut";
			rekap_tiket << "Museum Angkut";
			
		}else if(rekaptempat == 6){
			
			cout << "Batu Night Spectacular";
			rekap_tiket << "Batu Night Spectacular";
			
		}else {
			cout << " ";
			rekap_tiket << " ";
		}
		
		cout << "\n";
		
		/*Berfungsi untuk menampilkan pemesanan tiket terakhir*/
		if(anakanak != 0 && dewasa != 0){
			
			cout << "\n";
			
			for(i=0; i < anakanak; i++)//Perulangan FOR untuk menampilkan nama yang telah diinputkan
			{
				cout << "\t\tNama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
			}
			
			for(i = 0; i < dewasa; i++){
				cout << "\t\tNama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
			}
			
		}else if(anakanak != 0){
			for(i=0; i < anakanak; i++){
				cout << "\t\tNama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
			}
			
		}else if(dewasa != 0){
			for(i = 0; i < dewasa; i++){
				cout << "\t\tNama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
			}
		}
		
		rekap_tiket << "\n\n";
		/*Percabangan IF untuk mengecek jumlah nama anak-anak dan dewasa pada penginputan tiket*/
		if(anakanak != 0 && dewasa != 0){
			
			for(i=0; i < anakanak; i++){
				rekap_tiket<< "Nama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;//Menampilkan nama pada file format .txt
			}
			
			for(i = 0; i < dewasa; i++){
				rekap_tiket<< "Nama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
			}
			
		}else if(anakanak != 0){
			for(i=0; i < anakanak; i++){
				rekap_tiket<< "Nama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
			}
			
		}else if(dewasa != 0){
			for(i = 0; i < dewasa; i++){
				rekap_tiket<< "Nama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
			}
		}
		
		rekap_tiket<<"\n===============================================================\n";
		rekap_tiket.close();//Berfungsi untuk menutup file txt
		
		/*Berfungsi untuk memberi garis menggunakan karakter "#" pada bagian bawah dalam bingkai*/
		koordinat(0,20);
		for(i=0; i<=119; i++)
		{
			cout << "#";
		}
		
		cetakrekap();
	}
}

/*Fungsi untuk menampilkan pilihan akan mencetak nota dalam format .txt atau tidak*/
void cetak_nota()
{
	int i;
	char yo;
	
	cout << endl;
	for(i=0; i<=119; i++)//Perulangan FOR untuk menampilkan karakter "="
	{
		cout << "=";
	}
	
	cout<<"\n\n\t\t\t\tApakah Anda Ingin mencetak Informasi Diatas [Y] ? ";
	cin >> yo;
	
	if (yo=='y'||yo=='Y')//Percabangan IF jika memilih Y atau y
	{
		system ("Cetak_Tiket.txt");
		utama();
	}
	else 
	{
		utama();
	}
}

/*Fungsi untuk menampilkan output data yang akan diprint pada notepad berformat txt*/
void cetaktiket(int anak, int dewasa){
	
	system("cls");//Berfungsi untuk membersihkan layar pada program yang akan dijalankan sehingga pemrogram dapat menenentukan saat untuk menghapus data yang telah dijalankan tanpa harus menutup program tersebut dan membukanya kembali
	system("color 0B"); //Memberi Warna Biru Pada Output
	int i;
	
	ofstream data_tiket;//Berfungsi untuk membuka file dalam mode menulis
	
	koordinat(32,4);cout<<" ллллллл  ллллллл  ллллллл  лллллллл  ллл   ллл";
	koordinat(32,5);cout<<" ллл      ллл        ллл    ллл  ллл  ллл ллл";
	koordinat(32,6);cout<<" ллл      ллллллл    ллл    лллллллл  лллллл";
	koordinat(32,7);cout<<" ллл      ллл        ллл    ллл  ллл  ллл ллл";
	koordinat(32,8);cout<<" ллллллл  ллллллл    ллл    ллл  ллл  ллл   ллл" << endl << endl << endl;
	
	cout << endl << "\tNama Kasir : " << kasir << endl;
	cout <<"\tTotal Yang Harus Dibayar : " << formatAngka(total_tiket) << endl << endl;
	cout <<"\tInputkan Pembayaran : ";
	cin >> bayar;
	kembalian = bayar - total_tiket;
	
	if(bayar < total_tiket){
		cout <<"\tMaaf Uang Anda Kurang! Silahkan Inputkan Kembali";
		getch();
		cetaktiket(anak, dewasa);
	}else{
		cout <<"\tTotal Kembalian : " << formatAngka(kembalian) << endl << endl;
	}
	
	data_tiket.open("Cetak_Tiket.txt");//Berfungsi untuk menunjuk ke sebuah nama file
	/*Berfungsi untuk menampilkan data pada file berformat .txt*/
	data_tiket<<"=====================================================\n";
	data_tiket<<"\t\tData Pemesanan Tiket" << endl;
	data_tiket<<"=====================================================\n";
	data_tiket<<"Nama Kasir : " << kasir << endl;
	data_tiket<<"Nama Tempat Pariwisata yang Dipilih : ";
	if(tempatpublik == 1){
		
		cout << "\n\tNama Tempat : Jawa Timur Park 1";
		data_tiket << "Jawa Timur Park 1";
		
	}else if(tempatpublik == 2){
		
		cout << "\n\tNama Tempat : Jawa Timur Park 2";
		data_tiket << "Jawa Timur Park 2";
		
	}else if(tempatpublik == 3){
		
		cout << "\n\tNama Tempat : Jawa Timur Park 3";
		data_tiket << "Jawa Timur Park 3";
		
	}else if(tempatpublik == 4){
		
		cout << "\n\tNama Tempat : Batu Secret Zoo";
		data_tiket << "Batu Secret Zoo";
		
	}else if(tempatpublik == 5){
		
		cout << "\n\tNama Tempat : Museum Angkut";
		data_tiket << "Museum Angkut";
		
	}else if(tempatpublik == 6){
		
		cout << "\n\tNama Tempat : Batu Night Spectacular";
		data_tiket << "Batu Night Spectacular";
		
	}else {
		cout << " ";
		data_tiket << " ";
	}
	
	rekaptempat = tempatpublik;
	
	data_tiket<< endl;
	data_tiket<<"Total Yang Harus Dibayar : " << formatAngka(total_tiket) << endl;
	data_tiket<<"Nominal Pembayaran : " << formatAngka(bayar) << endl;
	data_tiket<<"Kembalian : " << formatAngka(kembalian);
	data_tiket<<"\n=====================================================\n";
	
	cout << endl;
	/*Percabangan IF untuk mengecek jumlah nama anak-anak dan dewasa pada penginputan tiket*/
	if(anak != 0 && dewasa != 0){
		
		for(i=0; i < anak; i++)//Perulangan FOR untuk menampilkan nama yang telah diinputkan
		{
			cout << "\tNama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
		}
		
		for(i = 0; i < dewasa; i++){
			cout << "\tNama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
		}
		
	}else if(anak != 0){
		for(i=0; i < anak; i++){
			cout << "\tNama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
		}
		
	}else if(dewasa != 0){
		for(i = 0; i < dewasa; i++){
			cout << "\tNama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
		}
	}
	
	/*Percabangan IF untuk mengecek jumlah nama anak-anak dan dewasa pada penginputan tiket*/
	if(anak != 0 && dewasa != 0){
		
		for(i=0; i < anak; i++){
			data_tiket<< "Nama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;//Menampilkan nama pada file format .txt
		}
		
		for(i = 0; i < dewasa; i++){
			data_tiket<< "Nama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
		}
		
	}else if(anak != 0){
		for(i=0; i < anak; i++){
			data_tiket<< "Nama ke-" << i+1 << " (Anak-Anak) : " << namaanak[i] << endl;
		}
		
	}else if(dewasa != 0){
		for(i = 0; i < dewasa; i++){
			data_tiket<< "Nama ke-" << i+1 << " (Dewasa) : " << namadewasa[i] << endl;
		}
	}
	
	data_tiket<<"=====================================================\n";
	data_tiket.close();//Berfungsi untuk menutup file txt
	cetak_nota();//Berfungsi untuk memanggil fungsi cetak_nota
}

/*Berfungsi untuk menginputkan nama pemesan tiket. Fungsi ini menggunakan parameter*/
void inputdata(int jumlaha, int jumlahb){

	system("cls");
	system("color 0F");
	
	int i;
	
	koordinat(32,4);cout<<"  ллл  ллл    ллл  лллллллл   ллл   ллл  ллллллл";
	koordinat(32,5);cout<<"  ллл  лллл   ллл  ллл   ллл  ллл   ллл    ллл";
	koordinat(32,6);cout<<"  ллл  ллл лл ллл  ллл   ллл  ллл   ллл    ллл";
	koordinat(32,7);cout<<"  ллл  ллл   лллл  лллллллл   ллл   ллл    ллл";
	koordinat(32,8);cout<<"  ллл  ллл    ллл  ллл        ллл   ллл    ллл";
	koordinat(32,9);cout<<"  ллл  ллл    ллл  ллл         ллллллл     ллл";
	koordinat(80,10);cout<<"DATA.";
	koordinat(30,11);cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
	
	if(jumlaha != 0 && jumlahb != 0)//Percabangan IF jika variabel jumlaha dan jumlahb tidak sama dengan 0
	{
		cout << "\n\n\n";
		
		for(i=0; i < jumlaha; i++){
			cout << "\tMasukkan Nama Panggilan ke-" << i+1 << " (Anak-Anak) : ";
			cin.sync();
			cin.getline(namaanak[i], 100);//untuk menginputkan kata-kata atau kalimat(nama)
			
			if (IsLetters(namaanak[i]))//Jika inputan adalah huruf
			{
				
			}
			else//Jika inputan mengandung angka maka menampilkan kalimat peringatan
			{
				cout << "\tInputan Tidak Valid" << endl;
				cout << "\tAnda Tidak Dapat Menginputkan Angka Pada Nama. Mohon Inputkan Kembali!" << endl;
				cout << "\tTekan Apapun Untuk Menginputkan Kembali!" << endl;
				cin.clear();//Berfungsi untuk membersihkan satu atau lebih karakter dari buffer input.
				cin.ignore();//Berfungsi untuk mengabaikan atau menghapus satu atau lebih karakter dari buffer input.
				inputdata(jumlaha, jumlahb);
			}
		}
		
		cout << "\n";
		for(i = 0; i < jumlahb; i++)//Perulangan FOR untuk inputan nama tiket dewasa
		{
			cout << "\tMasukkan Nama Panggilan ke-" << i+1 << " (Dewasa) : ";
			cin.sync();
			cin.getline(namadewasa[i], 100);
			
			if (IsLetters(namadewasa[i]))
			{
				
			}
			else
			{
				cout << "\tInputan Tidak Valid" << endl;
				cout << "\tAnda Tidak Dapat Menginputkan Angka Pada Nama. Mohon Inputkan Kembali!" << endl;
				cout << "\tTekan Apapun Untuk Menginputkan Kembali!" << endl;
				cin.clear();
				cin.ignore();
				inputdata(jumlaha, jumlahb);
			}
		}
		
		cetaktiket(jumlaha, jumlahb);
		
	}else if(jumlaha != 0)//Kondisi jika hanya menginputkan anak-anak saja
	{
		cout << "\n\n\n";
		for(i=0; i < jumlaha; i++){
			cout << "\tMasukkan Nama Panggilan ke-" << i+1 << " (Anak-Anak) : ";
			cin.sync();
			cin.getline(namaanak[i], 100);
			
			if (IsLetters(namaanak[i]))//Jika inputan adalah huruf
			{
				
			}
			else//jika inputan adalah angka atau karakter
			{
				cout << "\tInputan Tidak Valid" << endl;
				cout << "\tAnda Tidak Dapat Menginputkan Angka Pada Nama. Mohon Inputkan Kembali!" << endl;
				cout << "\tTekan Apapun Untuk Menginputkan Kembali!" << endl;
				cin.clear();
				cin.ignore();
				inputdata(jumlaha, jumlahb);
			}
		}
		
		cetaktiket(jumlaha, 0);
		
	}else if(jumlahb != 0)//Kondisi jika hanya menginputkan dewasa saja
	{
		cout << "\n\n\n";
		for(i = 0; i < jumlahb; i++){
			cout << "\tMasukkan Nama Panggilan ke-" << i+1 << " (Dewasa) : ";
			cin.sync();
			cin.getline(namadewasa[i], 100);
			
			if (IsLetters(namadewasa[i]))
			{
				
			}
			else
			{
				cout << "\tInputan Tidak Valid" << endl;
				cout << "\tAnda Tidak Dapat Menginputkan Angka Pada Nama. Mohon Inputkan Kembali!" << endl;
				cout << "\tTekan Apapun Untuk Menginputkan Kembali!" << endl;
				cin.clear();
				cin.ignore();
				inputdata(jumlaha, jumlahb);
			}
		}
		
		cetaktiket(0, jumlahb);
	}else{
		salah();
		utama();
	}
}

/*Berfungsi untuk menampilkan total harga tiket*/
void lihatharga(int x, int y){
	system("cls");
	frame();
	
	koordinat(0,5);
	for(i = 0; i <= 119; i++)//Perulangan FOR
	{
		cout << "#";
	}
	
	koordinat(48,3); cout << "Total Harga Pemesanan Tiket";
	koordinat(37,9); cout << "Note : Inputkan Dengan Angka 0 Jika Tidak Ada";
	koordinat(37,10); cout << "Masukkan Jumlah Anak-Anak : ";
	cin >> anakanak;
	
	while(!cin)//Perulangan untuk mengecek jika inputan yang diinputkan bukan angka melainkan huruf pada inputan anak-anak
	{
		koordinat(37,11); cout << "Inputan Tidak Valid";
		koordinat(37,12); cout << "Anda Hanya Dapat Menginputkan Angka. Mohon Inputkan Kembali!";
		cin.clear();//Berfungsi untuk membersihkan satu atau lebih karakter dari buffer input.
		cin.ignore();//Berfungsi untuk mengabaikan atau menghapus satu atau lebih karakter dari buffer input.
		koordinat(37,13); cout << "Tekan Apapun Untuk Menginputkan Kembali!";
		getch();
		lihatharga(x, y);//Berfungsi untuk memanggil fungsi lihatharga dengan mengirim nilai variabel x dan y
	}
	
	koordinat(37,11); cout << "Masukkan Jumlah Orang Dewasa : ";
	cin >> dewasa;
	
	while(!cin)//Perulangan untuk mengecek jika inputan yang diinputkan bukan angka melainkan huruf pada inputan dewasa
	{
		koordinat(37,11); cout << "Inputan Tidak Valid";
		koordinat(37,12); cout << "Anda Hanya Dapat Menginputkan Angka. Mohon Inputkan Kembali!";
		cin.clear();//Berfungsi untuk membersihkan satu atau lebih karakter dari buffer input.
		cin.ignore();//Berfungsi untuk mengabaikan atau menghapus satu atau lebih karakter dari buffer input.
		koordinat(37,13); cout << "Tekan Apapun Untuk Menginputkan Kembali!";
		getch();
		lihatharga(x, y);//Berfungsi untuk memanggil fungsi lihatharga dengan mengirim nilai variabel x dan y
	}
		
	int total_tiket_anak = anakanak * x;//Menghitung total tiket anak
	int total_tiket_dewasa = dewasa * y;//Menghitung total tiket dewasa
	total_tiket = total_tiket_anak + total_tiket_dewasa;//Menghitung total tiket keseluruhan
	koordinat(37,13); cout << "Total Harga Tiket Anak-Anak : " << formatAngka(total_tiket_anak);
	koordinat(37,14); cout << "Total Harga Tiket Dewasa : " << formatAngka(total_tiket_dewasa);
	koordinat(37,15); cout << "Total Harga Tiket Seluruhnya : " << formatAngka(total_tiket);
	koordinat(37,17); cout << "Tekan Enter Untuk Mengisi Data Diri";
	getch();
	inputdata(anakanak, dewasa);
}

/*Berfungsi untuk menampilkan inputan apakah ingin melanjutkan? */
void opsilanjut(int tiket1, int tiket2){
	koordinat(42,22); cout << "Anda Anda Ingin Melanjutkan? (Y/N)" << endl;
	koordinat(60,23); cin >> lanjut;
	
	if(lanjut == 'Y' || lanjut == 'y')//Percabangan IF jika inputan Y atau y maka akan melanjutkan ke proses selanjutnya
	{
		lihatharga(tiket1, tiket2);
	}else{
		utama();//Jika pilihan bukan Y atau y maka akan kembali ke fungsi utama
	}
}

/*Berfungsi untuk menampilkan harga anak anak dan dewasa seusai pilihan*/
void opsitiket(string c, int a, int b){
	if(c == "Sabtu" || c == "Minggu"){
		koordinat(37,12); cout << "Hari : " << c << " (Weekend)";
	}else{
		koordinat(37,12); cout << "Hari : " << c << " (Weekdays)";
	}
	
	koordinat(37,13); cout << "Harga Tiket Bagi Anak Umur 1-5 : " << formatAngka(a);//Berfungsi untuk memanggil fungsi formatAngka yang berfungsi untuk mengkonversi harga dengan format yang telah ditentukan
	koordinat(37,14); cout << "Harga Tiket Bagi Dewasa : " << formatAngka(b);
	opsilanjut(a, b);//Memanggil fungsi opsilanjut dengan mengirim nilai pada variabel a dan b
}

/*Berfungsi untuk menampilkan dan menginputkan hari yang nantinya akan digunakan untuk menghitung harga tiket*/
void wisata(int tempat3){
	
	tempatpublik = tempat3;//Memberi nilai pada variabel publik yaitu tempatpublik
	
	system("cls");
	do//Terdapat perulangan do while
	{
		system("color 0E");
		frame();
	
	koordinat(0,5);
	for(i = 0; i <= 119; i++)
	{
		cout << "#";
	}
	
	/*Berfungsi untuk memberi garis menggunakan karakter "#" pada bagian bawah dalam bingkai*/
	koordinat(0,20);
	for(i=0; i<=119; i++)
	{
		cout << "#";
	}
	
	/*Terdapat kondisi percabangan IF untuk menampilkan nama tempat wisata dan harga berdasarkan inputan pilihan menu wisata*/
	if(tempat3 == 1){
		
		koordinat(49,3); cout << "Jawa Timur Park 1";
		hargaweekdaysA = 80000;
		hargaweekdaysD= 110000;
		hargaweekendA = 100000;
		hargaweekendD = 150000;
		
	}else if(tempat3 == 2){
		
		koordinat(49,3); cout << "Jawa Timur Park 2";
		hargaweekdaysA = 100000;
		hargaweekdaysD = 110000;
		hargaweekendA = 110000;
		hargaweekendD = 155000;
		
	}else if(tempat3 == 3){
		
		koordinat(49,3); cout << "Jawa Timur Park 3";
		hargaweekdaysA = 120000;
		hargaweekdaysD = 130000;
		hargaweekendA = 140000;
		hargaweekendD = 165000;
		
	}else if(tempat3 == 4){
		
		koordinat(50,3); cout << "Batu Secret Zoo";
		hargaweekdaysA = 80000;
		hargaweekdaysD = 90000;
		hargaweekendA = 90000;
		hargaweekendD = 95000;
		
	}else if(tempat3 == 5){
		
		koordinat(51,3); cout << "Museum Angkut";
		hargaweekdaysA = 90000;
		hargaweekdaysD = 95000;
		hargaweekendA = 95000;
		hargaweekendD = 98000;
		
	}else if(tempat3 == 6){
		
		koordinat(47,3); cout << "Batu Night Spectacular";
		hargaweekdaysA = 70000;
		hargaweekdaysD = 74000;
		hargaweekendA = 80000;
		hargaweekendD = 84000;
		
	}else{
		main();
	}
	
	koordinat(37,10); cout << "Inputkan Hari Ini Berdasarkan Angka (1-7): ";
	day = namahari;//Memberi nilai pada pointer
	switch (getch()) {//Percabangan SwitchCase
            case '1':
				opsitiket(*(day), hargaweekdaysA, hargaweekdaysD);//Berfungsi untuk memanggil fungsi opsitiket dengan mengirim nilai pada variabel pointer day, dan harga tiket anak-anak serta dewasa
            break;
            case '2':
				opsitiket(*(day+1)/*Berungsi untuk mengirim variabel pointer ke fungsi opsitiket*/, hargaweekdaysA, hargaweekdaysD);
            break;
			case '3':
				opsitiket(*(day+2), hargaweekdaysA, hargaweekdaysD);
            break;
			case '4':
				opsitiket(*(day+3), hargaweekdaysA, hargaweekdaysD);
            break;
			case '5':
				opsitiket(*(day+4), hargaweekdaysA, hargaweekdaysD);
            break;
			case '6':
				opsitiket(*(day+5), hargaweekendA, hargaweekendD);
            break;
			case '7':
				opsitiket(*(day+6), hargaweekendA, hargaweekendD);
            break;
            default :
                system("color 0C");
                koordinat(45,22); cout << "Anda Memasukkan Angka Yang Salah";
                koordinat(42,23); cout << "Apakah Anda Ingin Mengulangi? (Y/N) : ";
                cin >> pilihan2;
				
				/*Percabangan IF untuk mengecek inputan apakah mengisi Y atau N atau inputan yang tidak valid*/
				if(pilihan2 == 'Y' || pilihan2 == 'y'){
					
				}else if(pilihan2 == 'N' || pilihan2 == 'n'){
					utama();
				}else{
					salah();
					utama();
				}
                system("cls");
            break;
        }
	
	}while(pilihan2 == 'Y' || pilihan2 == 'y');//Jika pilihan adalah Y maka program akan terus berulang
}

/*Fungsi untuk menampilkan halaman daftar harga tiket setelah memilih tempat pariwisata */
void daftarharga(int tempat2){
	
	system("cls");
	system("color 0B"); //Memberi Warna Biru Pada Output
	/*Berfungsi untuk membuat frame bagian atas judul menggunakan karakter "#" */
	koordinat(18,5);
	for(i = 0; i <= 80; i++)
	{
		cout << "#";
	}
	
	koordinat(50,7); cout << "Daftar Harga Tiket";
	
	/*Berfungsi untuk membuat frame bagian atas pada bawah judul menggunakan karakter "#" */
	koordinat(18,9);
	for(i = 0; i <= 80; i++)
	{
		cout << "#";
	}
	
	/*Berfungsi untuk membuat frame samping kiri menggunakan karakter "#" */
	for(i = 5; i <= 21; i++)
	{
		koordinat(18,i);
		printf("##");
	}
	
	/*Berfungsi untuk membuat frame samping kanan menggunakan karakter "#" */
	for(i = 5; i <= 21; i++)
	{
		koordinat(97,i);
		printf("##");
	}
	
	/*Berfungsi untuk membuat frame bagian bawah menggunakan karakter "#" */
	koordinat(18,21);
	for(i = 0; i <= 80; i++)
	{
		cout << "#";
	}
	
	/*Berfungsi untuk membuat batas tabel horizontal menggunakan karakter "#" */
	koordinat(18,15);
	for(i = 0; i <= 80; i++)
	{
		cout << "#";
	}
	
	/*Berfungsi untuk membuat batas tabel vertikal menggunakan karakter "#" */
	for(i = 9; i <= 21; i++)
	{
		koordinat(50,i);
		printf("##");
	}
	
	/*Percabangan IF untuk memberi harga tiket berdasarkan inputan wisata yang dipilih*/
	if(tempat2 == 1)
	{
		hargaweekdaysA = 80000;//Jika memilih weekdays dan jenis tiket anak-anak
		hargaweekdaysD= 110000;//Jika memilih weekdays dan jenis tiket dewasa
		hargaweekendA = 100000;//Jika memilih weekend dan jenis tiket anak-anak
		hargaweekendD = 150000;//Jika memilih weekend dan jenis tiket dewasa
	}else if(tempat2 == 2){
		hargaweekdaysA = 100000;
		hargaweekdaysD = 110000;
		hargaweekendA = 110000;
		hargaweekendD = 155000;
	}else if(tempat2 == 3){
		hargaweekdaysA = 120000;
		hargaweekdaysD = 130000;
		hargaweekendA = 140000;
		hargaweekendD = 165000;
	}else if(tempat2 == 4){
		hargaweekdaysA = 80000;
		hargaweekdaysD = 90000;
		hargaweekendA = 90000;
		hargaweekendD = 95000;
	}else if(tempat2 == 5){
		hargaweekdaysA = 90000;
		hargaweekdaysD = 95000;
		hargaweekendA = 95000;
		hargaweekendD = 98000;
	}else if(tempat2 == 6){
		hargaweekdaysA = 70000;
		hargaweekdaysD = 74000;
		hargaweekendA = 80000;
		hargaweekendD = 84000;
	}else{
		main();//Jika kondisi salah maka akan kembali ke menu main
	}
	
	/*Menampilkan harga yang telah dikonversi pada fungsi formatAngka*/
	koordinat(23,12); cout << "Weekdays (Senin - Jumat)";
	koordinat(55,11); cout << "Tiket Anak-Anak : " << formatAngka(hargaweekdaysA);
	koordinat(55,12); cout << "Tiket Dewasa : " << formatAngka(hargaweekdaysD);
	koordinat(23,18); cout << "Weekend  (Sabtu & Minggu)";
	koordinat(55,17); cout << "Tiket Anak-Anak : " << formatAngka(hargaweekendA);
	koordinat(55,18); cout << "Tiket Dewasa : " << formatAngka(hargaweekendD);
	getch();
}

void utama()//Menu Utama Yaitu Pilihan Destinasi
{
    system("cls");
	tempat = 1;//Memberi nilai 1 pada variabel tempat. Yang selanjutnya akan dijadikan parameter fungsi untuk meringkas program
	
	do//Perulangan DO While
	{
		frame();//Memanggil fungsi frame
		/*Berfungsi untuk memberi garis menggunakan karakter "#" pada bagian atas dalam bingkai*/
		koordinat(0,5);
		for(i = 0; i <= 119; i++)
		{
			cout << "#";
		}
		
		/*Berfungsi untuk menampilkan pilihan destinasi wisata*/
		system("color 0f"); //Memberi Warna Biru Pada Output
		koordinat(47,3); cout << "Daftar Destinasi Wisata";
		koordinat(30,9); cout << "1) Jawa Timur Park 1";
		koordinat(30,11); cout << "2) Jawa Timur Park 2";
		koordinat(30,13); cout << "3) Jawa Timur Park 3";
		koordinat(30,15); cout << "4) Batu Secret Zoo";
		koordinat(60,9); cout << "5) Museum Angkut";
		koordinat(60,11); cout << "6) Batu Night Spectacular";
		koordinat(60,13); cout << "7) Rekapan Data Pemesanan Tiket Terakhir";
		koordinat(60,15); cout << "8) Keluar";
		
		/*Berfungsi untuk memberi garis menggunakan karakter "#" pada bagian bawah dalam bingkai*/
		koordinat(0,20);
		for(i=0; i<=119; i++)
		{
			cout << "#";
		}
		
		/*Berfungsi untuk inputan destinasi wisata oleh user*/
		koordinat(48,23); cout << "Pilih Daftar Wisata : ";
		
		/*Berfungsi untuk hidden inputan*/
		switch (getch()) {//Percabangan SwitchCase
            case '1':
				daftarharga(tempat);//Berfungsi untuk memanggil fungsi bernama daftarharga dengan memberi nilai yaitu variabel tempat yang nantinya akan menjadi parameter pada fungsi daftarharga
                wisata(tempat);//Berfungsi untuk memanggil fungsi bernama wisata dengan memberi nilai yaitu variabel tempat yang nantinya akan menjadi parameter pada fungsi wisata
            break;
            case '2':
				tempat = 2;
				daftarharga(tempat);
                wisata(tempat);
            break;
			case '3':
				tempat = 3;
				daftarharga(tempat);
                wisata(tempat);
            break;
			case '4':
				tempat = 4;
				daftarharga(tempat);
                wisata(tempat);
            break;
			case '5':
				tempat = 5;
				daftarharga(tempat);
                wisata(tempat);
            break;
			case '6':
				tempat = 6;
				daftarharga(tempat);
                wisata(tempat);
            break;
			case '7':
				rekap();
            break;
			case '8':
				main();
            break;
            default :
                system("color 0C");
                koordinat(47,22); cout << "Menu Yang Anda Pilih Salah";
                koordinat(43,23); cout << "Apakah Anda Ingin Mengulangi? (Y/N) : ";
                cin >> tanya;
				system("cls");
				
				if(tanya == 'Y' || tanya == 'y'){
					
				}else if(tanya == 'N' || tanya == 'n'){
					main();
				}else{
					salah();
					main();
				}
            break;
        }
	
	}while(tanya == 'Y' || tanya == 'y');
	
}

int main() {
	
	system("cls");//Berfungsi untuk membersihkan layar pada program yang akan dijalankan sehingga pemrogram dapat menenentukan saat untuk menghapus data yang telah dijalankan tanpa harus menutup program tersebut dan membukanya kembali
	system("color 0A"); //Memberi Warna Hijau Pada Output
	
	/*Berfungsi untuk membuat frame samping kiri kanan menggunakan karakter "#" */
	for(i = 5; i <= 21; i++)// Perulangan FOR
	{
		koordinat(6,i); printf("##");
		koordinat(111,i); printf("##");
	}
	
	/*Berfungsi untuk membuat frame atas menggunakan karakter "#" */
	koordinat(6,5); 
	for(i = 0; i <= 105; i++)
	{
		printf("#");
	}
		
	/*Berfungsi untuk membuat frame bawah menggunakan karakter "#" */
	koordinat(6,21);
	for(i = 0; i <= 105; i++)
	{
		printf("#");
	}
	koordinat(6,20);
	for(i = 0; i <= 105; i++)
	{
		printf("#");
	}
		
	/*Berfungsi untuk membuat frame samping kiri kanan bagian dalam menggunakan karakter "#" */
	for(i = 5; i <= 21; i++)
	{
		koordinat(30,i);
		printf("##");
		koordinat(80,i);
		printf("##");
	}
		
	koordinat(4,3); cout << "|-------------------------------------------------------------------------------------------------------------|";
	koordinat(25,3); cout << "[ SELAMAT DATANG DI PROGRAM KASIR PEMBELIAN TIKET PARIWISATA ]";
		
	koordinat(4,23); cout << "|--------------------------------------------------------------------------------------------------------------|";
	koordinat(45,23); cout << "[ JAWA TIMUR PARK GROUP ]";
		
	koordinat(33,9); cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
	koordinat(33,15); cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
		
	/*Berfungsi untuk memasukkan inputan username dan password kasir */
	koordinat(37,11); cout << "Username : ";
	cin >> username;
	koordinat(37,13); cout << "Password : ";
    readPass(pass);
 
	string user = "kasir";//Memberikan nilai pada variabel user
	string password = "kasir123";//Memberikan nilai pada variabel password
	
	if(username == user && pass == password)//Percabangan IF untuk mengecek jika inputan sama dengan username dan password yang ditentukan
	{
		logo();
		utama();
	}else{
		system("color 0C");//Untuk menampilkan warna merah jika inputan salah
		koordinat(40,16); cout << "Username atau Password Yang Anda";
		koordinat(40,17); cout << "Masukkan Salah, Tekan Enter!";
		getch();
		system("cls");
		main();
	}
 
    return 0;
}
 
void readPass(char *temp) {
    int key = 0, index = 0;
 
    do {
        key = getch(); /* Simpan karakter yang ditekan ke dalam variabel key */
 
        switch (key) {
             
                /* 0 adalah kode awal untuk tombol fungsi (function key), seperti F1, F2, ..., F12 
                 * Misalkan jika tombol F1 ditekan, maka fungsi getch akan mengembalikan
                 * nilai 0 dan menyimpan sebuah kode yang menandakan tombol F1 ditekan ke buffer.
                 */
            case 0:
 
                /* 224 adalah kode awal untuk tombol panah, home, page up, page down, end dan lain-lain. 
                 * Misalkan jika tombol panah ditekan, fungsi getch akan 
                 * mengembalikan nilai 224 dan menyimpan sebuah kode
                 * yang menandakan tombol yang ditekan ke buffer.
                 */
            case 224:
                 
                /* Fungsi getch di sini digunakan untuk membersihkan buffer */
                getch();
 
                break;
                 
                /* Jika tombol back space ditekan, maka mundurkan cursor satu langkah */
            case '\b':
                if (index > 0) {
                    index = index - 1; /* Kurangi index temp sebesar 1 */
                    temp[index] = 0; /* set temp[index] menjadi kosong (NUL) */
 
                    printf("\b \b"); /* Mundurkan cursor satu langkah */
                }
 
                break;
            default:
                 
                /* Hanya karakter printable yang dapat ditekan, seperti huruf, angka dan karakter spesial */
                if (key > 31 && key < 127) {
                    temp[index] = key; /* Simpan karakter ke dalam temp[index] */
                    index = index + 1; /* Naikkan nilai index sebesar 1 */
 
                    printf("*");
                }
        }
 
        /* 13 adalah kode ASCII untuk karakter enter.
         * Perulangan akan terus dilakukan sampai tombol enter ditekan.
         */
    } while (key != 13);
     
    /* Menambahkan NUL di akhir temp yang menandakan akhir dari sebuah string */
    temp[index] = '\0';
}