#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

int pinR = 23, pinV = 22, pinA = 21;

//Conectar a una red WiFi
const char* WIFI_SSID = "iPhone";             //el nombre de la red
const char* WIFI_PASSWORD = "1234esp3210";  //la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyAwvibsko1t0NL8WHqO_LCOukzZZI2a1ZU";
const char* FIREBASE_PROJECT_ID = "pokedex-74590  ";
//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "esp32@esp.com";
const char* USER_PASSWORD = "123456";

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
void setup() {
  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);  //Verificamos la version
  setupWiFi();                                                        //Llamamos la funcion de configuración wifi
  setupFirebase();                                                    //Llamamos la funcion de configuración Firebase

  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  String path = "pokemones/pokemon"; // RUTA DE COLECCION
  FirebaseJson json;

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

    if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"]; // PARAMETRO NOMBRE
        Serial.print(document);
        const char* tipo = document["fields"]["tipo"]["stringValue"]; // PARAMETRO DE CAMPOS A REVISAR
        Serial.print(" : ");
        if (strstr(document_name, "pokemon") != nullptr) { // COMPARAR NOMBRE CON  RESULTADO ESPERADO pinR
          if (strcmp(tipo, "fire") == 0) {
            // Encender pin rojo
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "water") == 0) {
            // Encender pin azul
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "grass") == 0) {
            // Encender pin verde
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "electric") == 0) {
            // Encender pin amarillo
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "normal") == 0) {
            // Encender pin blanco
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "fighting") == 0) {
            // Encender pin naranja
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "poison") == 0) {
            // Encender pin morado
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "ground") == 0) {
            // Encender pin marrón
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "flying") == 0) {
            // Encender pin celeste
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "psychic") == 0) {
            // Encender pin rosado
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "bug") == 0) {
            // Encender pin verde claro
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "rock") == 0) {
            // Encender pin café
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, HIGH);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "ghost") == 0) {
            // Encender pin gris
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "dark") == 0) {
            // Encender pin negro
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "dragon") == 0) {
            // Encender pin azul oscuro
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else if (strcmp(tipo, "steel") == 0) {
            // Encender pin gris acero
            digitalWrite(pinR, LOW);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, LOW);
          } else if (strcmp(tipo, "fairy") == 0) {
            // Encender pin rosa
            digitalWrite(pinR, HIGH);
            digitalWrite(pinV, LOW);
            digitalWrite(pinA, HIGH);
          } else {
            // Aquí puedes manejar otros tipos de Pokémon si es necesario
          }
        }
      }
    }
  }
}