#include <Servo.h>

//ini adalah template_id, device_id dan token dari blynk yang kita miliki
#define BLYNK_TEMPLATE_ID "TMPL6JsRP8Hlq"
#define BLYNK_TEMPLATE_NAME "Makan Kucing"
#define BLYNK_AUTH_TOKEN "nmLXcOZZsJ3PWa3qqRlVv7iVuO3DnK-T"

//include library blynk
#include <BlynkSimpleEsp8266.h>

//Sebuah Object untuk servo
Servo myservo ;

//variable buat datastream StatusKucing
int StatusKucing;

void setup() {
  //pin yang digunain untuk servo = D8 = 15
  myservo.attach(15);
  //posisi servo awal di 180 derajat
  myservo.write(185);

  Serial.begin(115200);

  // koneksi ke wifi
  WiFi.begin("adromax", "masihbaru");
  // uji koneksi
  // digunakan untuk memunculkan conect di serial monitor
  // ini jika tidak terkoneksi
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(50);
  }

  Serial.println("Wifi Sudah Connect :)");

  //apabila terkoneksi, koneksikan perangkat ke blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, "adromax", "masihbaru");

  Serial.println("Blynk Sudah Connect juga :)");
}

void BeriMakan() {
  // proses perputaran t15 secara lambat dari 180 ke 0
  for(int posisi = 185; posisi >= 10; posisi--) {
    //set posisi awal untuk proses
    myservo.write(posisi);
    delay(5);
  }

  // proses perputaran t15 ke posisi balik ke 180
  for(int posisi = 10; posisi <= 185; posisi++) {
    myservo.write(posisi);
    delay(5);
  }
}

void loop() {
  //jalankan aplikasi blynk dari nodemcu
  Blynk.run();

  //tampilan statuskucing di serial monitor
  Serial.println("Status Makan : " + String(StatusKucing));

  //jika statusKucing = 1 maka beri makan
  if(StatusKucing == 1) {
    //panggil void beri makan, 1 puteran dari 180 sampai 0 derajat dan kembali ke 180
    BeriMakan();

    //kembali ke posisi mati atau tidak di beri makan
    Blynk.virtualWrite(V0, 0);
    StatusKucing = 0;
    delay(2000);
  }
}

//baca datastream statuskucing
BLYNK_WRITE(V0) {
  //membaca data stream tampung di dalam variable
  StatusKucing = param.asInt();
}
