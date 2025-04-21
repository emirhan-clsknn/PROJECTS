#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>

// RFID Pin Tanımlamaları
#define RST_PIN 22 // Reset pini
#define SS_PIN 21  // SDA (SS) pini

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID nesnesi oluşturuluyor

// Wi-Fi Bağlantı Bilgileri
const char* ssid = "pro";  // Wi-Fi adı
const char* password = "00000000";  // Wi-Fi şifresi
const char* serverUrl = "http://172.20.10.2:3000/checkCard";  // Express.js server adresi

// LED Pinleri
int ledGreen = 2;  // Olumlu yanit LED'i
int ledRed = 4;    // Olumsuz yanit LED'i

// Buton Pin Tanımlamaları
#define BUTTON1_PIN 25   // Buton 1
#define BUTTON2_PIN 26  // Buton 2
#define BUTTON3_PIN 27   // Buton 3
#define BUTTON4_PIN 33   // Buton 4
#define BUTTON5_PIN 4   // Buton 4


int selectedButton = -1;  // Seçilen buton numarası

void setup() {
  delay(100);
  Serial.begin(115200);
  Serial.println("Başlatılıyor...");

  // SPI ve RFID başlatma
  Serial.println("SPI ve RFID başlatılıyor...");
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("RFID modülü hazır.");

  // LED pinlerini ayarla
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);

  // Buton pinlerini giriş olarak ayarla
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(BUTTON5_PIN, OUTPUT);
  digitalWrite(BUTTON5_PIN, LOW);
  

  // Wi-Fi bağlantısı
  Serial.print("Wi-Fi ağına bağlanılıyor: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi bağlantısı başarılı.");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Butonlardan birine basıldı mı?
  if (digitalRead(BUTTON1_PIN) == LOW) {
    selectedButton = 1;
    Serial.println("Buton 1 basıldı. Kart okutuluyor...");
    waitForCard();
  }
  else if (digitalRead(BUTTON2_PIN) == LOW) {
    selectedButton = 2;
    Serial.println("Buton 2 basıldı. Kart okutuluyor...");
    waitForCard();
  }
  else if (digitalRead(BUTTON3_PIN) == LOW) {
    selectedButton = 3;
    Serial.println("Buton 3 basıldı. Kart okutuluyor...");
    waitForCard();
  }
  else if (digitalRead(BUTTON4_PIN) == LOW) {
    selectedButton = 4;
    Serial.println("Buton 4 basıldı. Kart okutuluyor...");
    waitForCard();
  }
}

void waitForCard() {
  // Kart okutulmasını bekle
  while (!(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())) {
    delay(100); // Kart okumak için kısa bir süre bekle
  }

  Serial.println("Yeni bir kart algılandı!");

  // Kart UID'sini oku
  String token = "";
  Serial.print("Kart UID'si okunuyor: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    token += String(mfrc522.uid.uidByte[i], HEX);
    Serial.print(String(mfrc522.uid.uidByte[i], HEX));
    Serial.print(" ");
  }
  token.toUpperCase();
  Serial.println("\nKart UID'si: " + token);

  // Servera token ve buton bilgisini gönderme
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Servera bağlanılıyor...");
    HTTPClient http;
    http.begin(serverUrl);  
    http.addHeader("Content-Type", "application/json");

    String postData = "{\"token\":\"" + token + "\", \"button\":\"" + String(selectedButton) + "\"}";
    Serial.println("POST verisi: " + postData);

    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.print("Server Yanıt Kodu: ");
      Serial.println(httpResponseCode);
      Serial.println("Server Yanıtı: " + response);

      // Server yanıtına göre LED sinyali
      if (response == "OK") {
        Serial.println("Kart doğrulandı, yeşil LED yanıyor.");
        switch (selectedButton)
          {
          case 1: 
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              break;
          case 2:
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              break;
          case 3:
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              break;
          case 4:
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              delay(300);
              digitalWrite(BUTTON5_PIN,HIGH);
              delay(150);
              digitalWrite(BUTTON5_PIN,LOW);
              break;
          default:
          break;
          }
        digitalWrite(ledGreen, HIGH);
        delay(2000);
        digitalWrite(ledGreen, LOW);
      } else if (response == "FAIL") {
        Serial.println("Kart doğrulanamadı, kırmızı LED yanıyor.");
        digitalWrite(ledRed, HIGH);
        delay(2000);
        digitalWrite(ledRed, LOW);
      }
    } else {
      Serial.print("Server bağlantı hatası: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Wi-Fi bağlantısı yok. Token gönderilemiyor.");
  }

  // RFID iletişimini sonlandır
  mfrc522.PICC_HaltA();
  Serial.println("Kart işleme sonlandırıldı.\n");
}
