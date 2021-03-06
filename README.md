# Ψηφιακή Στροφή του Σχολείου

Συμμετοχή του 3ου ΓΕΛ Τρίπολης 1ο Πανελλήνιο Διαγωνισμό Ρομποτικής Ανοιχτών Τεχνολογιών 

## Εισαγωγή 

Με τη συμμετοχή μας στον 1ο Πανελλήνιο Διαγωνισμό Ρομποτικής Ανοιχτών Τεχνολογιών επιθυμούμε να δημιουργήσουμε έργα με χρήση ανοιχτών τεχνολογιών, ώστε να εκσυγχρονίσουμε τόσο κάποιες λειτουργίες που γίνονται καθημερινά σε επίπεδο Σχολικής Μονάδας, όσο και να εκμεταλλευτούμε τις δυνατότητες ρομποτικών κατασκευών και να κάνουμε το Σχολείο μας περισσότερο Ψηφιακό.

Η ομάδα μας χωρίστηκε σε 4 υποομάδες, κάθε μια από τις οποίες επέλεξε μια διαφορετική κατασκευή με στόχο να επιλύσει ένα συγκεκριμένο "πρόβλημα" ή να αλλάξει τον τρόπο λειτουργίας μιας "συνηθισμένης" λειτουργίας χρησιμοποιώντας αισθητήρες και μικροελεγκτές.Πιο συγκεκριμένα με δεδομένες συνθήκες/χρόνο και τον ηλεκτρονικό εξοπλισμό που διαθέσαμε στον προγραμματισμό μας υπάρχει η κατασκευή των εξής:

 1. Διαχείριση δεξαμενής πετρελαίου</br>
 2. Απεικόνιση θερμοκρασίας και υγρασίας εξωτερικού και εσωτερικού χώρου</br>
 3. Ανιχνευτής σεισμού</br>
 4. Πρόσβαση σε πόρτες με κάρτες</br>
 5. Έξυπνοι κάδοι απορριμμάτων</br>
 6. Ρύθμιση φασαρίας στην τάξη</br>
 7. e-απουσίες</br>
 8. Έξυπνο κουδούνι</br>
 9. Αυτόματο πότισμα γλαστρών</br>
10. Αυτόματα φώτα αιθουσών</br>

<b>Όλοι οι κώδικες βρίσκονται στο φάκελο ¨code"</b>

## 01. Διαχείριση δεξαμενής πετρελαίου

### ΠΕΡΙΛΗΨΗ 

Ο αισθητήρας υπερύθρων RFID ultrasonic sensor συνδέεται στη δεξαμενή πετρελαίου.Έτσι έχει τη δυνατότητα να ανιχνεύει μέσω I2C που συνδέεται με τον αισθητήρα υπερύθρων την τιμή της στάθμης του υγρού,την οποία στην συνέχεια εμφανίζει σε μία οθόνη LCD.Για το συγκεκριμένο πρότζεκτ χρησιμοποιήσαμε την πλακέτα NodeMCU,η οποία μας επιτρέπει την ενσωμάτωση wifi στα έργα μας. Αυτό μας δίνει την δυνατότητα να ελέγχουμε απομακρυσμένα τη δεξαμενή πετρελαίου, αφού μπορούμε να τοποθετήσουμε την οθόνη όπου επιθυμούμε. 

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 2 | 9,90€ |
| Display 16X2 Character LCD 3.3V Blue |  ![LCD_16X2_Blue](https://user-images.githubusercontent.com/40848626/57192811-5f0ebb80-6f3d-11e9-820a-e4dc4aed4ac7.jpg) | 1 | 4.20€ |
| I2C LCD Backpack for 1602 | ![lcd1602_i2c](https://user-images.githubusercontent.com/40848626/57192815-7188f500-6f3d-11e9-91bd-6310c2555edb.jpg) | 1 | 8,00€ |
| Ultrasonic Sensor HC-SR04  |  ![UltraSonic_sr04s](https://user-images.githubusercontent.com/40848626/57192823-7cdc2080-6f3d-11e9-9f1b-9d1340f1c5ea.jpg) | 1 | 2.50€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 37,1€ |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη </br>
<b> για το συγκεκριμένο έργο χρησιμοποιήσαμε 2 NodeMCU ως server και client,συνεπώς υπάρχουν δύο διαφορετικοί κώδικες.</b>
### ΚΥΚΛΩΜΑ

##### Client

![01_OK_Diesel_Client_bb](https://user-images.githubusercontent.com/40848626/57197825-90ef4480-6f74-11e9-8e18-ff707798a207.jpg)


##### Server

![01_OK_Diesel_Server_bb](https://user-images.githubusercontent.com/40848626/57197826-9187db00-6f74-11e9-8c6c-1c5452488b51.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p1_diesel (2)](https://user-images.githubusercontent.com/40848626/57194468-fc72eb00-6f4f-11e9-9a24-858524f36832.jpg)

![p2_diesel](https://user-images.githubusercontent.com/40848626/57192960-f9233380-6f3e-11e9-87cb-7f0682fbeec5.jpg)

![p3_diesel](https://user-images.githubusercontent.com/40848626/57192834-98dfc200-6f3d-11e9-9e46-b367ac924a66.jpg)

![p4_diesel (2)](https://user-images.githubusercontent.com/40848626/57194608-78b9fe00-6f51-11e9-8f5c-263e7a7e1bb2.jpg)

![p5_diesel](https://user-images.githubusercontent.com/40848626/57192836-98dfc200-6f3d-11e9-8988-7b16eef1f720.jpg)

![p6_diesel](https://user-images.githubusercontent.com/40848626/57192837-99785880-6f3d-11e9-9e01-3170c232ba61.jpg)

![p7_diesel (2)](https://user-images.githubusercontent.com/40848626/57194469-fd0b8180-6f4f-11e9-8631-5cbf64176ff6.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το προτζεκτ αυτό θα μπορούσε να χρησιμοποιηθεί σε δημόσιες και ιδιωτικές υπηρεσίες εξοικονομώντας χρόνο και κάνοντας ευκολότερο τον προγραμματισμό των εξόδων της εταιρίας (πχ για ανεφοδιασμό πετρελαίου).  

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2.Ultrasonic HC-SR04 Datasheet</br>
https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

## 02. Απεικόνιση θερμοκρασίας και υγρασίας εξωτερικού και εσωτερικού χώρου 

### ΠΕΡΙΛΗΨΗ 

   Στις δύο πλακέτες NodeMCU συνδέθηκε από ένας αισθητήρας θερμοκρασίας και υγρασίας DHT11. Έπειτα η πρώτη πλακέτα τοποθετήθηκε σε εξωτερικό χώρο, ενώ η δεύτερη σε εσωτερικό. Μέσω wifi, οι τιμές των αισθητήρων απεικονίζονται σε μία οθόνη LCD, η οποία βρίσκεται συνδεδεμένη στην δεύτερη πλακέτα. Κατά αυτόν τον τρόπο έχουμε τη δυνατότητα ανά πάσα στιγμή να ενημερωθούμε για την εξωτερική αλλά και εσωτερική θερμοκρασία της τάξης.  


### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 2 | 9,90€ |
| Display 16X2 Character LCD 3.3V Blue |  ![LCD_16X2_Blue](https://user-images.githubusercontent.com/40848626/57192811-5f0ebb80-6f3d-11e9-820a-e4dc4aed4ac7.jpg) | 1 | 4.20€ |
| I2C LCD Backpack for 1602 | ![lcd1602_i2c](https://user-images.githubusercontent.com/40848626/57192815-7188f500-6f3d-11e9-91bd-6310c2555edb.jpg) | 1 | 8,00€ |
| Αισθητήρας Υγρασίας & Θερμοκρασίας DHT11  | ![DHT11-800x800](https://user-images.githubusercontent.com/40848626/57193021-a138fc80-6f3f-11e9-8211-7f98522ae8fb.jpg) | 2 | 1,90€  |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 40,30€  |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη </br>
<b> για το συγκεκριμένο έργο χρησιμοποιήσαμε 2 NodeMCU ως server και client,συνεπώς υπάρχουν δύο διαφορετικοί κώδικες.</b>

### ΚΥΚΛΩΜΑ 

##### Client
![02_OK_Temperature_Client_bb](https://user-images.githubusercontent.com/40848626/57197827-9187db00-6f74-11e9-816a-8f8b906b8eb0.jpg)

##### Server
![02_OK_Temperature_Server_bb](https://user-images.githubusercontent.com/40848626/57197828-92207180-6f74-11e9-9857-7076f9a4759d.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p8_temp](https://user-images.githubusercontent.com/40848626/57192976-1c4de300-6f3f-11e9-9c23-80a33ed9a13e.jpg)

![p9_temp](https://user-images.githubusercontent.com/40848626/57192977-1c4de300-6f3f-11e9-9b52-103049136d6a.jpg)

![p10_temp](https://user-images.githubusercontent.com/40848626/57192978-1c4de300-6f3f-11e9-90ea-4becdb72183c.jpg)

![p11_temp](https://user-images.githubusercontent.com/40848626/57192979-1c4de300-6f3f-11e9-986c-838d9e9eb50a.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το συγκεκριμένο προτζεκτ θα μπορούσε να χρησιμοποιηθεί σε συνδυασμό με το amazon echo ενημερώνοντας τον χρήστη οποιαδήποτε στιγμή για το επίπεδο υγρασίας και τη θερμοκρασία σε κάποιο απομονωμένο χώρο  

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2. DHT11 Datasheet</br>
https://cdn-learn.adafruit.com/downloads/pdf/dht.pdf


## 03. Ανιχνευτής Σεισμού 

### ΠΕΡΙΛΗΨΗ 

Το σύστημα ανιχνεύει τις δονήσεις της γης που σημειώνονται σε περίπτωση σεισμού μέσω του αισθητήρα δόνησης MEAS. Σε περίπτωση έντονης σεισμικής δόνησης εμφανίζει ανάλογο μήνυμα στην οθόνη LCD.   

 
### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
| Display 16X2 Character LCD 3.3V Blue |  ![LCD_16X2_Blue](https://user-images.githubusercontent.com/40848626/57192811-5f0ebb80-6f3d-11e9-820a-e4dc4aed4ac7.jpg) | 1 | 4.20€ |
| I2C LCD Backpack for 1602 | ![lcd1602_i2c](https://user-images.githubusercontent.com/40848626/57192815-7188f500-6f3d-11e9-91bd-6310c2555edb.jpg) | 1 | 8,00€ |
| Αισθητήρας Δόνησης μεγάλος όρθιος (MEAS) | ![vibration_sensor_meas](https://user-images.githubusercontent.com/40848626/57193133-a480b800-6f40-11e9-8b20-85f36d11dc28.jpg) | 1 | 3.50€  |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 28,20€   |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![03_ΟΚ_Seismos_bb](https://user-images.githubusercontent.com/40848626/57197829-92207180-6f74-11e9-9aeb-417d17077af1.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p12_seismos](https://user-images.githubusercontent.com/40848626/57193105-64b9d080-6f40-11e9-8bc3-eee9b38eb96c.jpg)

![p13_seismos](https://user-images.githubusercontent.com/40848626/57193067-160c3680-6f40-11e9-87b1-772d955387f7.jpg)

![p15_seismos](https://user-images.githubusercontent.com/40848626/57193070-16a4cd00-6f40-11e9-9327-00160e6dfb94.jpg)

![p16_seismos (2)](https://user-images.githubusercontent.com/40848626/57194471-fd0b8180-6f4f-11e9-83c4-132429612e37.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το πρότζεκτ αυτό θα μπορούσε να χρησιμοποιηθεί ειδοποιώντας τους κατοίκους μιας πόλης (πχ μέσω μιας σειρήνας/συναγερμού) όταν υπάρχει επικίνδυνη σεισμική δραστηριότητα. 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2.Vibration Sensor MEAS 100 Datasheet</br>
https://www.sparkfun.com/datasheets/Sensors/Flex/MiniSense_100.pdf

## 04. Ε-Πρόσβαση σε πόρτες  με ηλεκτρομαγνητικές κάρτες 

### ΠΕΡΙΛΗΨΗ 

Το MFRC522 RFID Reader έχει τη δυνατότητα να ανιχνεύει, μέσω του ανέπαφου περάσματος των RFID Tags, την ταυτότητα τους και ταυτόχρονα να ελέγχει αν ταυτίζεται με κάποια από αυτές που έχουν ενσωματωθεί στη βάση δεδομένων. Σε περίπτωση ταύτισης η πόρτα θα ανοίγει, σε αντίθετη περίπτωση  η πόρτα θα παραμένει κλειστή. Εφόσον η πόρτα ανοίξει, στην βάση δεδομένων θα καταγράφονται ταυτόχρονα η ημερομηνία και η ώρα της πρόσβασης καθώς και το όνομα του κατόχου της κάρτας.  

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
| Display 16X2 Character LCD 3.3V Blue |  ![LCD_16X2_Blue](https://user-images.githubusercontent.com/40848626/57192811-5f0ebb80-6f3d-11e9-820a-e4dc4aed4ac7.jpg) | 1 | 4.20€ |
| Μπρελόκ RFID - 13.56MHz Μπλε  |![10pcs-lot-13-56MHz-RFID-IC-Key-Tags-Keyfobs-Token-NFC-TAG-Keychain-for-arduino-DIY jpg_640x640](https://user-images.githubusercontent.com/40848626/57193269-e5c59780-6f41-11e9-9914-d6bf4db2e404.jpg) | 1* | 0,50€  |
| Αναγνώστης NFC/RFID - MFRC-522 13.56MHz  |![RFID_MFRC_522](https://user-images.githubusercontent.com/40848626/57193271-ed853c00-6f41-11e9-8a1c-aa006f56e48e.jpg) | 1 | 5.90€  |
|Ηλεκτρομαγνητικό κυπρί πόρτας Realsafe VML-074 205x35mm 12VDC 1A | ![ilektriko-kypri-vml-074](https://user-images.githubusercontent.com/40848626/57193272-f118c300-6f41-11e9-906d-681559d6cf4b.gif) | 1 | 25,00€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 43,90€ |

*Η ποσότητα αλλάζει ανάλογα με τον αριθμό του προσωπικού που θέλουμε να έχει πρόσβαση στις αίθουσες. </br>
στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![04_OK_Portes_bb](https://user-images.githubusercontent.com/40848626/57197830-92b90800-6f74-11e9-9399-79faa336cb66.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p17_portes](https://user-images.githubusercontent.com/40848626/57193276-fb3ac180-6f41-11e9-9e2c-ecced3c230e0.jpg)

![p18_portes (2)](https://user-images.githubusercontent.com/40848626/57194472-fda41800-6f4f-11e9-8855-2c7065843151.jpg)

![p19_portes](https://user-images.githubusercontent.com/40848626/57193174-43a5af80-6f41-11e9-9579-92201f3528d1.jpg)

![p20_portes (2)](https://user-images.githubusercontent.com/40848626/57194473-fda41800-6f4f-11e9-8a64-14c93a3c5b3e.jpg)

![p21_portes (2)](https://user-images.githubusercontent.com/40848626/57194609-78b9fe00-6f51-11e9-87a4-aa8569bf90bb.jpg)

![p22_portes](https://user-images.githubusercontent.com/40848626/57193177-443e4600-6f41-11e9-9201-eac1d571d671.jpg)

![p23_portes (2)](https://user-images.githubusercontent.com/40848626/57194610-78b9fe00-6f51-11e9-9b3e-ad409dea1cdf.jpg)

![p24_portes](https://user-images.githubusercontent.com/40848626/57193235-92534980-6f41-11e9-9ee7-f3fff824e954.jpg)

![p25_portes](https://user-images.githubusercontent.com/40848626/57193236-92ebe000-6f41-11e9-93c6-5434d52cff4b.jpg)

![IMG_20190503_204602 (2)](https://user-images.githubusercontent.com/40848626/57194467-fc72eb00-6f4f-11e9-8772-d12882c51a29.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το πρότζεκτ αυτό θα μπορούσε να χρησιμοποιηθεί από εταιρίες διευκολύνοντας την πρόσβαση σε γραφεία, αίθουσες και άλλες εγκαταστάσεις. Επιπλέον θα μπορούσε να έχει εφαρμογή στον τομέα της υγείας κάνοντας ευκολότερη την πρόσβαση (και έλεγχο) σε ιατρεία. 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2. RFID MFRC-522</br>
https://www.hwkitchen.cz/user/related_files/rc522-rfid-ctecka-klicenka-a-karta-rychly-start-pdf.pdf

## 05.Εξυπνοι καδοι απορριματων ή ανακύκλωσης μπαταριών 

### ΠΕΡΙΛΗΨΗ 

Αρχικά θέτουμε το μέγιστο ύψος που μπορεί να σχηματίσει ο σωρός των σκουπιδιών προκειμένου ο έξυπνος κάδος να μην υπερχειλίσει. Οι έξυπνοι κάδοι θα έχουν την δυνατότητα να ανιχνεύουν πότε η στάθμη των απορριμμάτων έχει φτάσει στο μέγιστο ύψος.Στη συνέχεια στη βάση δεδομένων θα καταγράφεται η στάθμη του σωρού και η πιθανή ανάγκη για άδειασμα του έξυπνου κάδου. 

 ### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
| Ultrasonic Sensor HC-SR04  |  ![UltraSonic_sr04s](https://user-images.githubusercontent.com/40848626/57192823-7cdc2080-6f3d-11e9-9f1b-9d1340f1c5ea.jpg) | 1 | 2.50€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 15,00€  |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ

![05_OK_Skoupidia_bb](https://user-images.githubusercontent.com/40848626/57197831-93519e80-6f74-11e9-8bcd-4709d7fda68a.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p28_kadoi](https://user-images.githubusercontent.com/40848626/57193279-0988dd80-6f42-11e9-9ec2-6b03800acaa7.jpg)

![p29_kadoi](https://user-images.githubusercontent.com/40848626/57193280-0a217400-6f42-11e9-856d-02487f51a49b.jpg)

![p26_kadoi](https://user-images.githubusercontent.com/40848626/57193432-9aac8400-6f43-11e9-8967-e7d1e7a8ec31.jpg)

![p27_kadoi (2)](https://user-images.githubusercontent.com/40848626/57194611-79529480-6f51-11e9-8ad8-9e154a7edfde.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το πρότζεκτ με τους έξυπνους κάδους μπορεί να χρησιμοποιηθεί από τους Δήμους για την πιο εύκολη και αποτελεσματική συγκομιδή των σκουπιδιών. ( Ο αρμόδιος φορέας συγκομιδής σκουπιδιών θα ενημερώνεται για το ποιοι κάδοι έχουν γεμίσει και ποιοί όχι άρα δε θα χρειάζεται ο φορέας αυτός να κάνει άσκοπες μετακινήσεις. Συνεπώς εξοικονομεί χρόνο και καύσιμα. Άρα και ο Δήμος θα ξοδεύει λιγότερα χρήματα) Μια επέκταση αυτού του πρότζεκτ είναι η τοποθέτηση συλλέκτη φωτός ώστε να αυτονομηθεί ο κάδος και να γίνει “εξυπνότερος” και με “οικολογική συνείδηση”! 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2.Ultrasonic HC-SR04 Datasheet</br>
https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

## 06. Ρύθμιση φασαρίας στην τάξη 

### ΠΕΡΙΛΗΨΗ 

Η ιδέα για το συγκεκριμένο πρότζεκτ ήταν η δημιουργία ενός μετρητή φασαρίας (μέσω arduino nano) ο οποίος θα έχει εφαρμογή στις σχολικές αίθουσες. Χρησιμοποιώντας μία λεντοταινία ως μπάρα ένδειξης του επιπέδου του θορύβου θα καταφέρουμε να περιορίσουμε την φασαρία στις τάξεις. Όσο το επίπεδο της φασαρίας θα αυξάνεται τόσο περισσότερα φωτάκια στη λεντοταινία θα ανάβουν, ενώ όσο το επίπεδο της φασαρίας θα ελαττώνεται τόσο περισσότερα λαμπάκια θα σβήνουν ή θα παραμένουν σβηστά.  

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| Arduino Nano Compatible CH340  | ![Arduino_nano](https://user-images.githubusercontent.com/40848626/57193502-7ac99000-6f44-11e9-9625-2911a4c51bf5.jpg) | 1 | 5,80€ |
| WS2812B 5v LED Strip |  ![ledstrip](https://user-images.githubusercontent.com/40848626/57193512-8452f800-6f44-11e9-9546-b505b3283dc9.jpg) | 1 | 4.20€ |
| Microphone Amplifier - MAX4466  |![Αισθητήρας_Ηχου_MAX4466](https://user-images.githubusercontent.com/40848626/57193518-992f8b80-6f44-11e9-9aad-c2eebd0db127.jpg) | 1 | 8,50€  |
| 100 mF Capacitor   |![Capacitor_100_mfarad](https://user-images.githubusercontent.com/40848626/57193510-7ef5ad80-6f44-11e9-8299-a7b1d8c04ceb.jpg)| 1 | 0.07€ |
|220 Ohm Resistor  | ![resistor_220Ohm](https://user-images.githubusercontent.com/40848626/57193515-8b7a0600-6f44-11e9-8f58-c353638d1ddb.jpg)| 1 | 0,01€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 21,18€  |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![06_OK_fasaria_bb](https://user-images.githubusercontent.com/40848626/57197833-93ea3500-6f74-11e9-9ccc-8ff63641ff72.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p31_fasaria](https://user-images.githubusercontent.com/40848626/57193282-0a217400-6f42-11e9-9ea7-47f855aa5c18.jpg)

![p32_fasaria](https://user-images.githubusercontent.com/40848626/57193283-0aba0a80-6f42-11e9-93eb-54298fb45572.jpg)

![p33_fasaria](https://user-images.githubusercontent.com/40848626/57193284-0b52a100-6f42-11e9-9ecc-a0586e981996.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το πρότζεκτ αυτό θα μπορούσε να έχει επεκτάσεις στην μετρηση φασαριας στους δρόμους και μείωση της ηχορύπανσης. 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Arduino Nano</br>
https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf

## 07. Ε-Απουσίες 

### ΠΕΡΙΛΗΨΗ 

Το MFRC522 RFID Reader θα μπορεί να ανιχνεύει, μέσω του ανέπαφου περάσματος των RFID Tags των μαθητών, το όνομα και την ώρα προσέλευσης τους, τα οποία στη συνέχεια θα εμφανίζονται στην ηλεκτρονική βάση δεδομένων που έχει δημιουργηθεί. Αν η κάρτα του μαθητή είναι έγκυρη ένα LED φωτάκι ανάβει το οποίο σημαίνει την επιτυχή αναγνώρισή του από το σύστημα. Για το συγκεκριμένο πρότζεκτ χρησιμοποιήθηκε πλακέτα NodeMCU.  

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 
|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
|Αναγνώστης NFC/RFID - MFRC-522 13.56MHz   | ![RFID_MFRC_522](https://user-images.githubusercontent.com/40848626/57193271-ed853c00-6f41-11e9-8a1c-aa006f56e48e.jpg) | 1 | 5.90€   |
|Κάρτα RFID (13.56Mhz)   | ![RFID_Tag_(125kHz)](https://user-images.githubusercontent.com/40848626/57193749-6044e600-6f47-11e9-9de8-d99fd894092d.jpg) | 1* | 0,50€ |
|LED 10mm Red  | ![LED_10mm_red](https://user-images.githubusercontent.com/40848626/57193746-558a5100-6f47-11e9-9653-25da8cc8d900.jpg) | 1 | 0.20€ |
|LED 10mm Yellow |![LED_10mm_yellow](https://user-images.githubusercontent.com/40848626/57193747-5622e780-6f47-11e9-989c-c2873a436dc3.jpg) | 1 | 0.20€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 19,10€ |

*Η ποσότητα αλλάζει ανάλογα με τον αριθμό των μαθητών που θέλουμε να έχει πρόσβαση στις Ε-Απουσίες.</br>
στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![07_OK_Apousies_bb](https://user-images.githubusercontent.com/40848626/57197834-93ea3500-6f74-11e9-8791-b10252ae8c68.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p34_apousies](https://user-images.githubusercontent.com/40848626/57193285-0beb3780-6f42-11e9-9517-7ffb35c7930f.jpg)

![p35_apousies](https://user-images.githubusercontent.com/40848626/57193287-0beb3780-6f42-11e9-82a2-28cb67b8c417.jpg)

![p36_apousies](https://user-images.githubusercontent.com/40848626/57193288-0c83ce00-6f42-11e9-89f3-b1f064e8d59a.jpg)

![p37_apousies](https://user-images.githubusercontent.com/40848626/57193289-0c83ce00-6f42-11e9-8052-ec685885d1c9.jpg)

![p38_apousies (2)](https://user-images.githubusercontent.com/40848626/57194474-fed54500-6f4f-11e9-9289-96fb84c7c133.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

το συγκεκριμένο project θα μπορούσε να προσαρμοστεί έτσι ώστε οι δημόσιες εταιρείες να έχουν τη δυνατότητα ελέγχου των υπαλλήλων στο θέμα άφιξης-αποχώρησης από τον εργασιακό χώρο 


### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2. RFID MFRC-522</br>
https://www.hwkitchen.cz/user/related_files/rc522-rfid-ctecka-klicenka-a-karta-rychly-start-pdf.pdf


## 08. Ε-Κουδούνι 

### ΠΕΡΙΛΗΨΗ 

Στο έργο αυτό προσπαθήσαμε να ενσωματώσουμε τη τεχνολογία φωνητικών εντολών , μέσω του Alexa Echo Dot, στις δυνατότητες που έχει ένα Nodemcu.Έτσι μπορούμε να ενεργοποιήσουμε το κουδούνι μέσω φωνητικών εντολών. Σύμφωνα με το eMarketer, μέσα σε αυτό τον χρόνο υπολογίζεται πως πάνω από 25 εκατομμύρια Αμερικάνοι θα χρησιμοποιήσουν το συγκεκριμένο μηχάνημα (Echo Dot) τουλάχιστον μία φορά τον μήνα.  

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
| Relay Module - 1 Channel 5V Low Level Trigger  |  ![relay_SRD_5VDC](https://user-images.githubusercontent.com/40848626/57193847-67b8bf00-6f48-11e9-8ec0-3329d2c43b8f.jpg) | 1 | 1,50€ |
| Κουδούνι με ήχο 80dB  | ![koudouni-me-icho-80db-12v-lefko-normal](https://user-images.githubusercontent.com/40848626/57193839-596aa300-6f48-11e9-9233-500ec2740a50.jpg) | 1* | 11.90€  |
| Echo Dot (3rd Gen)  | ![GUEST_d0ed568d-e584-4bb5-9995-891975630a9d](https://user-images.githubusercontent.com/40848626/57193836-51aafe80-6f48-11e9-9cea-1000f6da5d24.jpg) | 1 | 46.36€  |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 72,26€ |

 *Η ποσότητα αλλάζει ανάλογα με τον αριθμό διαφορετικών κουδουνιών που θέλουμε να χειριστούμε </br>
στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![08_OK_Smart_koudouni_bb](https://user-images.githubusercontent.com/40848626/57197835-9482cb80-6f74-11e9-95ed-edd901260668.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p39_koudouni](https://user-images.githubusercontent.com/40848626/57193291-0d1c6480-6f42-11e9-853c-76e10f0973b4.JPG)

![p40_koudouni](https://user-images.githubusercontent.com/40848626/57193292-0d1c6480-6f42-11e9-8fe6-932dafaa07b2.JPG)

### ΕΠΕΚΤΑΣΕΙΣ 
Το amazon echo θα μπορούσε να χρησιμοποιηθεί ενσωματώνοντας τις φωνητικές εντολές στο φωτισμό του σχολείου και κάνοντας τον έτσι εξυπνότερο. 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 

1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf
2. Relay Module</br>
https://www.fecegypt.com/uploads/dataSheet/1522335312_relay%20module.pdf


## 0.9 Αυτόματο πότισμα γλαστρών 

### ΠΕΡΙΛΗΨΗ 

Ο αισθητήρας που βρίσκεται τοποθετημένος στις γλάστρες των φυτών που επιθυμούμε να ποτίσουμε ανιχνεύει την υγρασία του χώματος. Το σύστημα έχει δύο δυνατότητες. Σε περίπτωση που η τιμή της υγρασίας είναι κατώτερη του επιθυμητού επιπέδου, επιτρέπει την παροχή νερού στα φυτά μέσω μιας αντλίας, η οποία βρίσκεται συνδεδεμένη σε πηγή νερού. Σε αντίθετη περίπτωση διατηρεί την αρχική του κατάσταση χωρίς να προχωρήσει στην εκτέλεση κάποιας εντολής.  

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| Arduino Uno R3  | ![arduino_uno_rev3](https://user-images.githubusercontent.com/40848626/57194225-f2032200-6f4c-11e9-973e-aecf3d6efa3c.jpg) | 1 | 11,90€  |
| Αισθητήρας Υγρασίας Εδάφους |  ![soil-hygrometer](https://user-images.githubusercontent.com/40848626/57193963-b1ee7000-6f49-11e9-9027-e780dd14fccc.jpg) | 1 | 1.90€  |
| Liquid Pump Motor - Micro 12V |![Liquid_pump_motor_12v](https://user-images.githubusercontent.com/40848626/57193958-a8fd9e80-6f49-11e9-81ea-b1e9d78ea7c9.jpg) | 1 | 3,90€ |
| Silicone Tube Transparent 2x4mm - per meter |![Silicone_tube](https://user-images.githubusercontent.com/40848626/57193961-b1ee7000-6f49-11e9-9c84-c5b58cafab85.jpg)| 1 | 0.60€ |
| Transistor Darlington NPN 5A - TIP120 | ![tip120](https://user-images.githubusercontent.com/40848626/57193964-b2870680-6f49-11e9-8eee-3b1edc10db1f.jpg)| 1 | 0.50€ |
| Diode Rectifier - 1A 400V 1N4004 | ![diode_1N4004](https://user-images.githubusercontent.com/40848626/57193973-b7e45100-6f49-11e9-8a0d-5c1ba2cc953d.jpg) | 1 | 0.025€ |
| 1 KΩ Resistor | ![1kohm](https://user-images.githubusercontent.com/40848626/57194273-b157d880-6f4d-11e9-9e75-c5b79de5a146.jpg) | 1 | 0.01€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 21,435€  |

στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 

![09_OK_potisma_bb](https://user-images.githubusercontent.com/40848626/57197836-9482cb80-6f74-11e9-8557-7493f38c5b58.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p41_potisma (2)](https://user-images.githubusercontent.com/40848626/57194344-5c689200-6f4e-11e9-9f9c-7b0a0c320fb0.jpg)

![p42_potisma](https://user-images.githubusercontent.com/40848626/57193295-0db4fb00-6f42-11e9-98e1-77492c6a8443.jpg)

![p43_potisma](https://user-images.githubusercontent.com/40848626/57193296-0e4d9180-6f42-11e9-9f5f-e4a865c9505c.jpg)

![p44_potisma](https://user-images.githubusercontent.com/40848626/57193297-0ee62800-6f42-11e9-9591-557f4e8d433f.jpg)

![p45_potisma](https://user-images.githubusercontent.com/40848626/57193298-0ee62800-6f42-11e9-8cdd-ddd7718e03fa.jpg)

![p46_potisma](https://user-images.githubusercontent.com/40848626/57193299-0f7ebe80-6f42-11e9-9c6b-d91e3ab34672.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Το συγκεκριμένο πρότζεκτ θα μπορούσε να έχει εφαρμογή σε δημόσια πάρκα και κήπους πόλεων  

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Arduino Uno R3</br>
https://www.fecegypt.com/uploads/dataSheet/1522237550_arduino%20uno%20r3.pdf

2. Moisture Sensor</br>
https://www.fecegypt.com/uploads/dataSheet/1480854383_water%20and%20soil.pdf


## 0.10 Ε-Φώτα Αιθουσών 

### ΠΕΡΙΛΗΨΗ 

Μέσω μιας εφαρμογής την οποία δημιουργήσαμε στο πρόγραμμα App Inventor, έχουμε τη δυνατότητα να ελέγχουμε πλήρως τα φώτα σε μία αίθουσα,αποκλειστικά μέσω wifi,από το κινητό μας.Αυτό επιτυγχάνεται μέσω της πλακέτας NodeMCU.Κάθε φορά που δίνουμε εντολή να ανοίξουν τα φώτα,οι ρελέδες μπαίνουν σε λειτουργία δινοντάς μας το επιθυμητό αποτέλεσμα. 

### ΑΠΑΙΤΟΥΜΕΝΑ ΥΛΙΚΑ ΚΑΙ ΕΝΔΕΙΚΤΙΚΟ ΚΟΣΤΟΣ ΚΑΤΑΣΚΕΥΗΣ 

|Περιγραφή|Ενδεικτική Εικόνα|Ποσότητα|Ενδεικτικό Κόστος (με ΦΠΑ)|
| --- | --- | --- | ---|
| NodeMCU Lolin v3 | ![Nodemcu_Lolin](https://user-images.githubusercontent.com/40848626/57192799-05a68c80-6f3d-11e9-9967-1a382de641c1.jpg) | 1 | 9,90€ |
| Relay Module - 1 Channel 5V Low Level Trigger  |  ![relay_SRD_5VDC](https://user-images.githubusercontent.com/40848626/57193847-67b8bf00-6f48-11e9-8ec0-3329d2c43b8f.jpg) | 1 | 1,50€ |
|Breadboard mini | ![breadboard_mini](https://user-images.githubusercontent.com/40848626/57192824-806fa780-6f3d-11e9-92fa-7371e7a49538.jpg) | 1 | 1.60€ |
| Καλώδια σύνδεσης | - | - | 1,00€ |
|  |  | Σύνολο | 14,00€  |

 *Η ποσότητα αλλάζει ανάλογα με τον αριθμό διαφορετικών κουδουνιών που θέλουμε να χειριστούμε </br>
στο κόστος πρέπει να συμπεριλάβουμε κόστος για τροφοδοσία του Nodemcu, αλλά επειδή υπάρχουν τόσοι διαφορετικοί τρόποι δεν το αναφέρουμε παραπάνω και το αφήνουμε ως επιλογή στο χρήστη 

### ΚΥΚΛΩΜΑ 
![10_OK_Fwta_bb](https://user-images.githubusercontent.com/40848626/57197837-9482cb80-6f74-11e9-9c66-c6209271e70a.jpg)

### ΦΩΤΟΓΡΑΦΙΕΣ 

![p47_fwta (2)](https://user-images.githubusercontent.com/40848626/57194612-79529480-6f51-11e9-9090-f7c29a0efe5d.jpg)

![p48_fwta (2)](https://user-images.githubusercontent.com/40848626/57194613-79eb2b00-6f51-11e9-9baf-793bbd05334e.jpg)

![p49_fwta](https://user-images.githubusercontent.com/40848626/57193302-10afeb80-6f42-11e9-98c0-4232cb93918c.jpg)

### ΕΠΕΚΤΑΣΕΙΣ 

Χρησιμοποιώντας ένα photoresistor μπορούμε να φτιάξουμε ένα σύστημα το οποίο ανάλογα με την φωτεινότητα που υπάρχει στον εξωτερικό χώρο να ανοίγει τα φώτα των πόλεων με σκοπό την εξοικονόμηση ενέργειας 

### ΣΧΕΤΙΚΟΙ ΣΥΝΔΕΣΜΟΙ 
1. Nodemcu Datasheet</br>
https://www.handsontec.com/pdf_learn/esp8266-V10.pdf

2. Relay Module</br>
https://www.fecegypt.com/uploads/dataSheet/1522335312_relay%20module.pdf

## Η Ομάδα Ρομποτικής του 3ου Γενικού Λυκείου Τρίπολης

### Καθηγητής:
Αγγελόπουλος Γιώργος

### Μαθητές: 
Αγγελόπουλος Κωνσταντίνος</br>
Ανδριανόπουλος Νίκος</br>
Βέργου Παναγιώτα</br> 
Γεωργακόπουλος Γιώργος</br> 
Γιαννόπουλος Γιώργος</br> 
Γκάνιος Θανάσης</br> 
Γκουσιάκη Έρη</br> 
Κιτσοπούλου Κάτια</br> 
Κιτσοπούλου Δήμητρα</br> 
Μαυρόγιαννης Αναστάσης</br> 
Μητσόπουλος Αργύρης</br> 
Μπόγρης Βαγγέλης</br>
Σακελλαριάδη Ελένη</br> 
Σούχλας Σπύρος</br> 
Τρικάτσουλα Νικολέτα</br> 
Φόρτης Παναγιώτης</br> 
Χελιώτη Χριστίνα</br> 
