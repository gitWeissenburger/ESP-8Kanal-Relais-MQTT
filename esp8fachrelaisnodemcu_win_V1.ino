
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <PubSubClient.h>



const char* ssid = "Deine SSID";
const char* password = "Dein WLAN Passwort";
const char* mqtt_server = "IP Adresse deines Brokers";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

// Client ID, outTopic, inTopic1 und deviceName zum Publish und Subscribe für das MQTT Protokoll
const char* clientID = "ESP8_Relais";
const char* outTopic = "/WEP_Home/Terrasse";
const char* inTopic1 = "/WEP_Home/Terrasse/Relais";
const char* deviceName = "ESP8_Relais";

int relay_pin1 = 5;
int relay_pin2 = 4;
int relay_pin3 = 0;
int relay_pin4 = 2;
int relay_pin5 = 14;
int relay_pin6 = 12;
int relay_pin7 = 13;
int relay_pin8 = 15;

// Dient zur Verbindungsanzeige bei erfolgreicher Brokerverbindung
int LED_pIN = 16;

bool relayState1 = LOW;
bool relayState2 = LOW;
bool relayState3 = LOW;
bool relayState4 = LOW;
bool relayState5 = LOW;
bool relayState6 = LOW;
bool relayState7 = LOW;
bool relayState8 = LOW;


// IPAddresse des ESP
IPAddress ip(192,168,178,122);
// IPAddresse des gateways
IPAddress gateway(192,168,178,1);
IPAddress subnet(255,255,255,0);


void setup_wifi() {

  delay(10000);
 
    // Connect to WiFi network
    WiFi.mode(WIFI_STA);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.hostname(deviceName);      // DHCP Hostname (useful for finding device for static lease)
    WiFi.config(ip, gateway, subnet);  // (DNS not required)
    WiFi.begin(ssid, password);
    
    
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  Serial.println();

// Auswertung der empfangen Daten, 
// erste Ziffer = Relaisnummer
// zweite Ziffer = 0 für LOW, 1 für High
  if ((char)payload[0] == '1') {
      if ((char)payload[1] == '0') {
        digitalWrite(relay_pin1, LOW);
        Serial.println("relay_pin1 -> LOW");
        client.publish(outTopic, "relay_pin1 -> LOW");
        relayState1 = LOW;
        EEPROM.write(0, relayState1);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin1, HIGH);
        Serial.println("relay_pin1 -> HIGH");
        client.publish(outTopic, "relay_pin1 -> HIGH");
        relayState1 = HIGH;
        EEPROM.write(0, relayState1);
        EEPROM.commit();}
  } else if ((char)payload[0] == '2') {
      if ((char)payload[1] == '0') {
        digitalWrite(relay_pin2, LOW);
        Serial.println("relay_pin2 -> LOW");
        client.publish(outTopic, "relay_pin2 -> LOW");
        relayState2 = LOW;
        EEPROM.write(1, relayState2);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin2, HIGH);
        Serial.println("relay_pin2 -> HIGH");
        client.publish(outTopic, "relay_pin2 -> HIGH");
        relayState2 = HIGH;
        EEPROM.write(1, relayState2);
        EEPROM.commit();}
  } else if ((char)payload[0] == '3') {
       if ((char)payload[1] == '0') {
        digitalWrite(relay_pin3, LOW);
        Serial.println("relay_pin3 -> LOW");
        client.publish(outTopic, "relay_pin3 -> LOW");
        relayState3 = LOW;
        EEPROM.write(2, relayState3);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin3, HIGH);
        Serial.println("relay_pin3 -> HIGH");
        client.publish(outTopic, "relay_pin3 -> HIGH");
        relayState3 = HIGH;
        EEPROM.write(2, relayState3);
        EEPROM.commit();}
  } else if ((char)payload[0] == '4') {
        if ((char)payload[1] == '0') {
        digitalWrite(relay_pin4, LOW);
        Serial.println("relay_pin4 -> LOW");
        client.publish(outTopic, "relay_pin4 -> LOW");
        relayState4 = LOW;
        EEPROM.write(3, relayState4);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin4, HIGH);
        Serial.println("relay_pin4 -> HIGH");
        client.publish(outTopic, "relay_pin4 -> HIGH");
        relayState4 = HIGH;
        EEPROM.write(3, relayState4);
        EEPROM.commit();}
  } else if ((char)payload[0] == '5') {
      if ((char)payload[1] == '0') {
        digitalWrite(relay_pin5, LOW);
        Serial.println("relay_pin5 -> LOW");
        client.publish(outTopic, "relay_pin5 -> LOW");
        relayState5 = LOW;
        EEPROM.write(4, relayState5);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin5, HIGH);
        Serial.println("relay_pin5 -> HIGH");
        client.publish(outTopic, "relay_pin5 -> HIGH");
        relayState5 = HIGH;
        EEPROM.write(4, relayState5);
        EEPROM.commit();}
  } else if ((char)payload[0] == '6') {
        if ((char)payload[1] == '0') {
        digitalWrite(relay_pin6, LOW);
        Serial.println("relay_pin6 -> LOW");
        client.publish(outTopic, "relay_pin6 -> LOW");
        relayState6 = LOW;
        EEPROM.write(5, relayState6);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin6, HIGH);
        Serial.println("relay_pin6 -> HIGH");
        client.publish(outTopic, "relay_pin6 -> HIGH");
        relayState6 = HIGH;
        EEPROM.write(5, relayState6);
        EEPROM.commit();}
  } else if ((char)payload[0] == '7') {
      if ((char)payload[1] == '0') {
        digitalWrite(relay_pin7, LOW);
        Serial.println("relay_pin7 -> LOW");
        client.publish(outTopic, "relay_pin7 -> LOW");
        relayState7 = LOW;
        EEPROM.write(6, relayState7);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin7, HIGH);
        Serial.println("relay_pin7 -> HIGH");
        client.publish(outTopic, "relay_pin7 -> HIGH");
        relayState7 = HIGH;
        EEPROM.write(6, relayState7);
        EEPROM.commit();}
  } else if ((char)payload[0] == '8') {
        if ((char)payload[1] == '0') {
        digitalWrite(relay_pin8, LOW);
        Serial.println("relay_pin8 -> LOW");
        client.publish(outTopic, "relay_pin8 -> LOW");
        relayState8 = LOW;
        EEPROM.write(7, relayState8);
        EEPROM.commit();
      } else if ((char)payload[1] == '1') {
        digitalWrite(relay_pin8, HIGH);
        Serial.println("relay_pin8 -> HIGH");
        client.publish(outTopic, "relay_pin8 -> HIGH");
        relayState8 = HIGH;
        EEPROM.write(7, relayState8);
        EEPROM.commit();}
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    Serial.print("WIFI Status: ");
    Serial.println(WiFi.status());
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientID)) {
      Serial.println("connected");
      Serial.println();
      Serial.print(clientID);
      // Once connected, publish an announcement...
      client.publish(outTopic, "Relais bootet");
      // ... and resubscribe
      client.subscribe(inTopic1);
      digitalWrite(LED_pIN, LOW);   // Turn the LED on by making the voltage LOW
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 10 seconds");
      // Wait 5 seconds before retrying
      for(int i = 0; i<10; i++){
        digitalWrite(LED_pIN, LOW);
        delay(500);
        digitalWrite(LED_pIN, HIGH);
        delay(500);
      }
    }
  }
}



void setup() {
  Serial.begin(115200);
  EEPROM.begin(1024);              // Begin eeprom to store on/off state
  pinMode(relay_pin1, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin2, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin3, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin4, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin5, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin6, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin7, OUTPUT);     // Initialize the relay pin as an output
  pinMode(relay_pin8, OUTPUT);     // Initialize the relay pin as an output
  pinMode(LED_pIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.println(" Setup set output pin end");

// setzen der Relaiszustände die zuletzt gespeichert wurden
  relayState1 = EEPROM.read(0);
  digitalWrite(relay_pin1,relayState1);
  Serial.print(relayState1);
  Serial.println(": set output pin 1 end: ");
  relayState2 = EEPROM.read(1);
  digitalWrite(relay_pin2,relayState2);
  Serial.print(relayState2);
  Serial.println(": set output pin 2 end: ");
  relayState3 = EEPROM.read(2);
  digitalWrite(relay_pin3,relayState3);
  Serial.print(relayState3);
  Serial.println(": set output pin 3 end: ");
  relayState4 = EEPROM.read(3);
  digitalWrite(relay_pin4,relayState4);
  Serial.print(relayState4);
  Serial.println(": set output pin 4 end: ");
  relayState5 = EEPROM.read(4);
  digitalWrite(relay_pin5,relayState5);
  Serial.print(relayState5);
  Serial.println(": set output pin 5 end: ");
  relayState6 = EEPROM.read(5);
  digitalWrite(relay_pin6,relayState6);
  Serial.print(relayState6);
  Serial.println(": set output pin 6 end: ");
  relayState7 = EEPROM.read(6);
  digitalWrite(relay_pin7,relayState7);
  Serial.print(relayState7);
  Serial.println(": set output pin 7 end: ");
  relayState8 = EEPROM.read(7);
  digitalWrite(relay_pin8,relayState8);
  Serial.print(relayState8);
  Serial.println(": set output pin 8 end: ");
  digitalWrite(LED_pIN, HIGH);   // Turn the LED off by making the voltage HIGH
  

  setup_wifi();                   // Connect to wifi 
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}
