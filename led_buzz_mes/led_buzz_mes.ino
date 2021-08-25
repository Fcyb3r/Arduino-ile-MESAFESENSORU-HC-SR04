/*
 * led,buzzer,mesafe sensörü(HC-S1R04)
 * yapımcı:fcyber tarih:25.08.2021
 */
int led=2; //ledimi 2.pine bagladım
int buzz=3; //buzzeri 3 numarali pine bagladim
//mesafe sensoru tanımlıyorum

int echoPin=8; //8.pine bağladım
int trigPin=9; //9.pine bağladım

//değisken tanımlıyalım 2tane
float mes;
float sure;

void setup() {


pinMode(led,OUTPUT); //led cıkıs pininde
pinMode(buzz,OUTPUT); //buzzer cıkıs pininde

Serial.begin(9600); //seri haberlesmeyi baslattım
pinMode(echoPin,INPUT); //echopini giris pinidir,ses dalgası alır
pinMode(trigPin,OUTPUT); //trigpini cıkıs pinidir,ses dalgası gönderir

}

void loop() {


  digitalWrite(trigPin,LOW); //ses dalgası yolladık
delay(300);

  digitalWrite(trigPin,HIGH); //ses dalgası uretmek icin pasıf duruma cektik
delay(300);

  digitalWrite(trigPin,LOW); //trig ses dalgası yolluyor
 sure=pulseIn(echoPin,HIGH); //gonderilen ses dalgasi sure ile olculuyor
 
mes=29.1/sure/2; //burada bir matamatiksel islem var ses hızının mikro saniye cinsi sure bölü 2
Serial.println("KALAN MESAFE"); //seri port ekranında boyle kalan mesafe yazsın diye boyle yaptim
Serial.println(mes); //mesafeyi ekrana yazsın diye
delay(300);

if(mes>0.03){ //mesafem 0.03 den büyükse asagidaki durumlar olsun dedim

  digitalWrite(led,HIGH); //ledi yaktim 
  delay(300);

  digitalWrite(led,LOW); //ledi sondurdum
  delay(100);


  digitalWrite(buzz,HIGH); //buzzeri caklistirdim
  delay(300);

  digitalWrite(buzz,LOW); //buzzeri kapattim
  delay(100);
  
  }else{

    /*
     * ifin icindekilerin tam tersi burada led ve buzzeri sonduruyor
     */
    digitalWrite(led,LOW); 
    digitalWrite(buzz,LOW);
    }
}
//saygı ve sevgilerimle saglıcakla kalın 
//tesekkurler pinoo robotic
