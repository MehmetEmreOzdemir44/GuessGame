#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sesPin=4;
int sesDurum=0;

int butPin=6;
int butDurum=0;

int randomSayilar;
int sayac=0;
void setup() {
  Serial.begin(9600);
  pinMode(sesPin,INPUT);
  pinMode(butPin,INPUT);
  lcd.init();
  lcd.backlight();

  randomSeed(analogRead(A1));
  lcd.setCursor(1,0);
  lcd.print("Tahmin Oyununa");
  lcd.setCursor(2,1);
  lcd.print("Hosgeldiniz");

  

}


void loop() {
  sesDurum=digitalRead(sesPin);
  butDurum=digitalRead(butPin);
  randomSayilar=random(1,7);
 
  
  if(sesDurum==0)
  {
    sayac++;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Alkis Sayisi: ");
    lcd.println(sayac);
    
    
    delay(100);
  }
  
  if(butDurum==1)
  {
    while(digitalRead(butPin));
    Serial.print("Random Sayi: ");
    Serial.println(randomSayilar);
    lcd.setCursor(2,1);

    lcd.print("Random sayi: ");
    lcd.println(randomSayilar);

    Serial.print("Alkis Adet: ");
    Serial.println(sayac);
    
    
    delay(2000);
    lcd.clear();

    if(sayac==randomSayilar)
    {
      lcd.setCursor(3,0);
      lcd.print("Tebrikler");
      lcd.setCursor(3,1);
      lcd.print("Kazandiniz");
      Serial.println("Tebrikler Kazandiniz");
    }
    else
    {
      lcd.setCursor(4,0);
      lcd.print("Maalesef");
      lcd.setCursor(3,1);
      lcd.print("Kaybettiniz");
      Serial.println("Maalesef Kaybettiniz");
      
    }
    
    
    sayac=0;
    randomSayilar=random(1,7);
    delay(4000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Tekrar Basladi");
  }

}
