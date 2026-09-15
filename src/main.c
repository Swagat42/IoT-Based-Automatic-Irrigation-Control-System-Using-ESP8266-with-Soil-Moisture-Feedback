#include <Servo.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define SENSOR_PIN A0
#define BUZZER_PIN D1
#define SERVO_PIN  D3

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Telegram credentials
#define BOT_TOKEN "YOUR_BOT_TOKEN"
#define CHAT_ID "YOUR_CHAT_ID"

const int DRY_THRESHOLD = 600;
const int WET_THRESHOLD = 300;
const int VALVE_OPEN = 90;
const int VALVE_CLOSE = 0;

Servo valveServo;
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

bool isValveOpen = false;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  valveServo.attach(SERVO_PIN);
  valveServo.write(VALVE_CLOSE);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  client.setInsecure(); // Required for ESP8266
}

void loop() {
  int rawValue =analogRead(SENSOR_PIN);
  int moisturePercent =map(rawValue, 1023, 0, 0, 100);

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("  |  Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("%  |  Valve: ");
  Serial.println(isValveOpen ? "OPEN" : "CLOSED");

  if (rawValue > DRY_THRESHOLD && !isValveOpen) {
    // DRY → Open valve + alert
    valveServo.write(VALVE_OPEN);
    isValveOpen = true;

    tone(BUZZER_PIN, 1000);
    delay(500);
    noTone(BUZZER_PIN);

    // Send Telegram message
    bot.sendMessage(CHAT_ID, " Soil is DRY! Watering started... ", "");
    Serial.println("Telegram alert sent!");

  } else if (rawValue < WET_THRESHOLD && isValveOpen) {
    // WET → Close valve
    valveServo.write(VALVE_CLOSE);
    isValveOpen = false;

    tone(BUZZER_PIN, 2000);
    delay(200);
    noTone(BUZZER_PIN);

    // Send Telegram message
    bot.sendMessage(CHAT_ID, "Soil is moist! Watering stopped.", "");
    Serial.println("Telegram confirmation sent!");
  }

  delay(1000);
}
