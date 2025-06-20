#define TOMBOL_GPIO 4  // Gunakan GPIO4

unsigned long waktumoment = 0;

void setup() {
  Serial.begin(9600);

  
  pinMode(TOMBOL_GPIO, INPUT_PULLUP);// jadikan GPIO sebagai input dan aktifkan pull-up
}

void loop() {
  unsigned long waktumillis = millis();

  if (waktumillis - waktumoment >= 200) {
    waktumoment = waktumillis;

   
    bool tombolDitekan = !(GPIO.in & (1 << TOMBOL_GPIO));  // LOW = ditekan
    //GPIO.in itu register 32-bit yang menyimpan status logika semua GPIO 0–31. masing masing nunjukkin perbitnya bit 0 = gpio 0,bit 1 = gpio 1
    //(1 << TOMBOL_GPIO) itu sihfting atau geser angka 1 ke kiri sebanyak TOMBOL_GPIO maka : (1 << 4) = 00010000 (biner) = 16 (desimal)
    //GPIO.in & (1 << TOMBOL_GPIO) maka dia akan melakukan bitwise AND antara GPIO.in dan mask (1 << TOMBOL_GPIO). 
    //Jika GPIO4 bernilai HIGH (1) → hasilnya bukan nol
    //Jika GPIO4 bernilai LOW (0) → hasilnya nol
 // Akses langsung ke register GPIO input
    if (tombolDitekan) {
      Serial.println("Tombol DITEKAN");
    } else {
      Serial.println("Tombol DILEPAS");
    }
  }
}
