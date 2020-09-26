# ESP-8Kanal-Relais-MQTT
ESP8266 NodeMCU – 8-fach Relaiskarte

Verwendungszweck: 

Diese 8-fach Relaiskarte wird zur Steuerung einer Terrassenbeleuchtung eingesetzt.
Dachbeleuchtung für die Hauptterrasse und die Nebenterrasse
2 x Bodenbeleuchtung mit 230V LED-Streifen 
Beleuchtete Feuertonne
Somit 3 Relais auf Reserve

Aufbau:

Aufgebaut ist das Ganze auf einem ESP8266-NodeMCU, kann aber auch auf einem WEMOS oder einem normalem ESP8266 aufgesetzt werden.
Die Verkabelung ist in einem Unterverteiler realisiert. Dort wurde eine Zuleitung über einen Leitungsschutzschalter 10A abgesichert. Mit einem Hutschienen-Trafo 230V/5V wird die Spannungsversorgung für den ESP und die Relaiskarte zur Verfügung gestellt. Die Ableitungen zu den Verbrauchern ist über ein Rangierfeld aus Steckkontakten flexibel änderbar.

Benötigte Hardware:

ESP8266 Node-MCU 
Beispiel: https://www.az-delivery.de/products/copy-of-nodemcu-lua-amica-v2-modul-mit-esp8266-12e?variant=36247507410&utm_medium=cpc&utm_source=Smarketer&utm_content=453269278475_c_&utm_term=&gclid=EAIaIQobChMInI_Kwumu6wIVweeyCh0XWA8wEAAYASAAEgJPdPD_BwE
Oder 
https://www.amazon.de/AZDelivery-NodeMCU-Development-Unverl%C3%B6tet-inklusive/dp/B07V4KL8CW/ref=sr_1_1_sspa?dchild=1&keywords=nodemcu+esp8266&qid=1598099776&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExNjlCVlk4Uk5OUkVJJmVuY3J5cHRlZElkPUEwNTA5MzMxMk5EVVYwWk0wRlo3TiZlbmNyeXB0ZWRBZElkPUEwNzM3NDY0MklSTTVUN0ROSTVHJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==

8-fach Relaiskarte 
Beispiel: https://www.amazon.de/Yizhet-Channel-Optocoupler-Raspberry-Arduino-5v-8/dp/B07MJF9Z4K/ref=pd_vtp_107_1/260-7515943-8572230?_encoding=UTF8&pd_rd_i=B07MJF9Z4K&pd_rd_r=6a7a1ba6-0bbe-41ae-8f17-d2bf03e77c42&pd_rd_w=G62Nc&pd_rd_wg=5yVIh&pf_rd_p=69e0861b-3c38-489a-96c2-122ec4152d31&pf_rd_r=CTRRST4SVYPF999VN0AR&psc=1&refRID=CTRRST4SVYPF999VN0AR

Trafo 230V/5V für die Hutschiene:
Beispiel: https://www.reichelt.de/schaltnetzteil-hutschiene-12-w-5-v-2-4-a-mw-dr-15-5-p148095.html?PROVID=2788&gclid=EAIaIQobChMI9I7oyuuu6wIV2ON3Ch3h5wMCEAQYASABEgLN1PD_BwE&&r=1


 
Bilder:
Im Bild seht ihr die Zuleitung (ganz links über dem Sicherungselement) sowie die Ableitungen zu den einzelnen Steckdosen bzw. zu den Verbrauchern. 
Jeder Verbraucher ist dann wiederrum über das Rangierfeld an einen Relaiskontakt angeschlossen.



Verdrahtung ESP und Relaiskarte:
ESP			Relaiskarte
D0			R1
D1			R2
D2			R3
D3			R4
D4			R5
D5			R6
D6			R7
D7			R8
Vin an 5V von Trafo	Pluseingang an 5V von Trafo
Gnd an Masse von Trafo	Minuseingang an Masse von Trafo


Der ESP wurde auf Stecksockel gesetzt um diesen im Fehlerfall schnell austauschen zu können. Auf der Leiterplatte wurden dann wiederrum Stiftleisten gesetzt um zwischen der Relaiskarte und dem ESP per Jumperkabel verbinden zu können.

Anschlussbild NODE MCU
 


Installation:

Den ESP an einem PC über USB Kabel anschließen, die Arduino Anwendung starten.
Wenn alle Bibliotheken installiert sind sollte der ESP-NodeMCU wie auf dem folgenden Bild erkannt worden sein.
Bild Arduino Connect NODE MCU

Die notwendigen Bibliotheken dazu sind:
-	Auflistung der Bib

Bild Arduino Connect

Anschließend den Sketch auf den ESP übertragen und beim ersten Bootvorgang über den seriellen Monitor die Verbindung zum eigenen WLAN kontrollieren. Erste Schaltvorgänge können (ohne die Relaiskarte angeschlossen zu haben) ebenfalls über den seriellen Monitor kontrolliert werden. Testweise kann dazu ein MQTT-Tool (https://github.com/mqtt/mqtt.github.io/wiki/tools) zum Senden von Schaltbefehlen verwendet werden.

 
Inbetriebnahme:

Achtung! Beim Booten des ESP muss die angeschlossene Relaiskarte von der Spannungsversorgung getrennt werden. 
Hintergrund. Die Relaiskarte zieht, je nach Relaisstellung, die Ausgänge (Dx – Dn) des ESP auf Masse. Dieser Lowpegel beeinflusst aber wiederrum das Bootverhalten des ESP. Daher!! Spannungsversorgung der Relaiskarte (5V) abstecken während des Bootvorgangs.

Die Steuerung der einzelnen Relais erfolgt über MQTT senden des Präfixes und des Relaiskennzeichens. 
Z. B. 	/Terrasse/Relais/10 --> schaltet Relais 1 auf AUS.
	/Terrasse/Relais/31 --> schaltet Relais 3 auf EIN.


Relais	Aus	Ein
1	10	11
2	20	21
3	30	31
4	40	41
5	50	51
6	60	61
7	70	71
8	80	81



