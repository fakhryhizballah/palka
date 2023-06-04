#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
 

const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

int nilai_angka_tombol_pertama;//variabel untuk mendeklarasikan nilai awal untuk masing-masing tombol untuk memasukan perintah untuk nilai pertama
int nilai_angka_tombol_kedua;//variabel untuk mendeklarasikan nilai awal untuk masing-masing tombol untuk memasukan perintah untuk nilai kedua

String penjumlahan_angka_pertama = "";//variabel untuk menjumlahkan angka pertama
String penjumlahan_angka_kedua = "";//variabel untuk menjumlahkan angka kedua
int nilai_angka_penggabungan;//variabel untuk mendeklarasikan nilai awal untuk penggabungan antara nilai pertama dan nilai kedua

int nilai_angka_pertama = 0;//variabel untuk mendeklarasikan nilai awal untuk angka pertama
int nilai_angka_kedua = 0;//variabel untuk mendeklarasikan nilai awal untuk angka kedua

int pengunci_angka_pertama = 0;//variabel untuk mengunci perintah "masukan angka pertama" agar perintah tersebut dapat terus berjalan sampai pengguna menonaktifkannya sendiri
int pengunci_angka_kedua = 0;//variabel untuk mengunci perintah "masukan angka kedua" agar perintah tersebut dapat terus berjalan sampai pengguna menonaktifkannya sendiri

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {//mengaktifkan remote
    if (results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch (results.value) {
      case 0xFFA25D://tombol 1
        delay(100);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 1;//
        break;

      case 0xFF629D://tombol 2
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 2;
        break;

      case 0xFFE21D://tombol 3
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 3;
        break;

      case 0xFF22DD://tombol 4
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 4;
        break;

      case 0xFF02FD://tombol 5
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 5;
        break;

      case 0xFFC23D://tombol 6
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 6;
        break;

      case 0xFFE01F://tombol 7
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 7;
        break;

      case 0xFFA857://tombol 8
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 8;
        break;

      case 0xFF906F://tombol 9
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 9;
        break;

      case 0xFF6897://tombol bintang(*)
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 10;
        break;

      case 0xFF9867://tombol 0
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 0;
        break;

      case 0xFFB04F://tombol pagar(#)
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 12;
        break;

      case 0xFF18E7://tombol atas
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        nilai_angka_tombol_pertama = 13;
        break;

      case 0xFF10EF://tombol kiri
        delay(200);//MEMBERIKAN JEDA WAKTU PADA SAAT SETELAH MENEKAN TOMBOL AGAR TIDAK TERJADI PENGULANGAN MELAKUKAN INPUT
        Serial.println("masukkan angka pertama!!!");
        nilai_angka_tombol_pertama = 14;
        break;

      case 0xFF38C7://tombol ok
        delay(200);
        nilai_angka_tombol_pertama = 15;
        break;

      case 0xFF5AA5://tombol kanan
        delay(200);
        Serial.println("masukkan angka kedua!!!");
        nilai_angka_tombol_pertama = 16;
        break;

      case 0xFF4AB5://tombol bawah
        delay(200);
        nilai_angka_tombol_pertama = 17;
        break;
    }
    key_value = results.value;
    irrecv.resume();
  }
  ///////////////////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT ANGKA PERTAMA///////////////////////////////////////////////////////////////
  if (nilai_angka_tombol_pertama == 14) {
    pengunci_angka_pertama = 1;
  }
  if (pengunci_angka_pertama == 1) {
    if (nilai_angka_tombol_pertama == 1) {
      nilai_angka_pertama = 1;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 2) {
      nilai_angka_pertama = 2;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 3) {
      nilai_angka_pertama = 3;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 4) { 
      nilai_angka_pertama = 4;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 5) {
      nilai_angka_pertama = 5;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 6) {
      nilai_angka_pertama = 6;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 7) {
      nilai_angka_pertama = 7;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 8) {
      nilai_angka_pertama = 8;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 9) {
      nilai_angka_pertama = 9;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 0) {
      nilai_angka_pertama = 0;
      penjumlahan_angka_pertama = String(penjumlahan_angka_pertama) + String(nilai_angka_pertama);
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 13;
    }
    if (nilai_angka_tombol_pertama == 10) {
      penjumlahan_angka_pertama = "";
      Serial.print("angka pertama: ");
      Serial.println(penjumlahan_angka_pertama); //MENAMPILKAN NILAI ANGKA PERTAMA
      nilai_angka_tombol_pertama = 14;
    }
    if (nilai_angka_tombol_pertama == 12) {
      Serial.println("input angka pertama telah selesai");
      pengunci_angka_pertama = 0;
    }
  }
  ///////////////////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT ANGKA PERTAMA///////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT ANGKA KEDUA////////////////////////////////////////////////////////////////
  if (nilai_angka_tombol_pertama == 16) {
    pengunci_angka_kedua = 1;
  }
  if (pengunci_angka_kedua == 1) {
    if (nilai_angka_tombol_pertama == 1) {
      nilai_angka_kedua = 1;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 2) {
      nilai_angka_kedua = 2;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 3) {
      nilai_angka_kedua = 3;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 4) {
      nilai_angka_kedua = 4;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 5) {
      nilai_angka_kedua = 5;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 6) {
      nilai_angka_kedua = 6;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 7) {
      nilai_angka_kedua = 7;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 8) {
      nilai_angka_kedua = 8;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 9) {
      nilai_angka_kedua = 9;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 0) {
      nilai_angka_kedua = 0;
      penjumlahan_angka_kedua = String(penjumlahan_angka_kedua) + String(nilai_angka_kedua);
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 10) {//PERINTAH MELAKUKAN DELETE
      penjumlahan_angka_kedua = "";
      Serial.print("angka kedua: ");
      Serial.println(penjumlahan_angka_kedua); //MENAMPILKAN NILAI ANGKA KEDUA
      nilai_angka_tombol_pertama = 16;
    }
    if (nilai_angka_tombol_pertama == 12) {
      Serial.println("input angka kedua telah selesai");
      pengunci_angka_kedua = 0;
    }
  }
  ////////////////////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT ANGKA KEDUA////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT MENGGABUNGKAN ANGKA PERTAMA DAN ANGKA KEDUA////////////////////////////////////////////////
  if (nilai_angka_tombol_pertama == 15) {
    nilai_angka_penggabungan = penjumlahan_angka_pertama.toInt() + penjumlahan_angka_kedua.toInt();//MENGUBAH VARIABEL PADA penjumlahan_angka_pertama DAN penjumlahan_angka_kedua MENJADI DATA INTEGER YANG SEBELUMNYA ADALAH DATA STRING DENGAN MENGGUNAKAN PERINTAH toInt
    Serial.print("hasil: ");
    Serial.println(nilai_angka_penggabungan); //MENAMPILKAN NILAI HASIL PENGGABUNGAN KEDUA NILAI
    nilai_angka_tombol_pertama = 99;
  }
  if (nilai_angka_tombol_pertama == 12) {
    nilai_angka_penggabungan = 0;//MERESET NILAI HASIL MENJADI 0 (NOL)
  }
  ////////////////////////////////////////////////BAGIAN UNTUK MEMBUAT MENGGABUNGKAN ANGKA PERTAMA DAN ANGKA KEDUA////////////////////////////////////////////////
}
