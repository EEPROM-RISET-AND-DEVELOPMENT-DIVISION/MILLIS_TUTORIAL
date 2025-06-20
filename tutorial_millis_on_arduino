
unsigned long waktumoment = 0;

void setup() {
  Serial.begin(9600);

  
  DDRD &= ~(1 << PD2);// gunakan pin D2 sebagai input 

  
  PORTD |= (1 << PD2);// Aktifkan internal pull-up (biasanya kan pakai pinMode( tombol,INPUTPUULUP))
}

void loop() {
  unsigned long waktumillis = millis(); //definisikan milllis ke variable

  if (waktumillis - waktumoment >= 200) { // jadi ketika waktumillis dikurangi waktu pas saat ditekan sampai 200 maka menciptakan seperti efek delay 200 ms
    waktumoment = waktumillis; // reset kembali biar nilai waktu moment masuk ke millis lagi agar bisa digunakan lagi (tidak stuck)

   
    bool tombolDitekan = !(PIND & (1 << PD2));  // LOW = ditekan karena inputpullup 
 // Baca status pin D2 (bit 2 pada PIND)
    if (tombolDitekan) {
      Serial.println("Tombol DITEKAN");
    } else {
      Serial.println("Tombol DILEPAS");
    }
  }

  // Program lain bisa jalan tanpa terganggu
}
