// схема https://rm-content.s3.amazonaws.com/57024268467568d777fa4a53/623356/upload-75bd24f0-9175-11e6-a671-ef868f9f21f8.png

#define LED_PIN  13
#define LDR_PIN  A0
#define POT_PIN  A1

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // считываем уровень освещённости. Кстати, объявлять
  // переменную и присваивать ей значение можно разом
  int lightness = analogRead(LDR_PIN);

  // считываем значение с потенциометра, которым мы регулируем
  // пороговое значение между условными темнотой и светом
  int threshold = analogRead(POT_PIN);

  // объявляем логическую переменную и назначаем ей значение
  // «темно ли сейчас». Логические переменные, в отличие от
  // целочисленных, могут содержать лишь одно из двух значений:
  // истину (англ. true) или ложь (англ. false). Такие значения
  // ещё называют булевыми (англ. boolean).
  boolean tooDark = (lightness < threshold);

  // используем ветвление программы: процессор исполнит один из
  // двух блоков кода в зависимости от исполнения условия.
  // Если (англ. «if») слишком темно...
  if (tooDark) {
    // ...включаем освещение
    digitalWrite(LED_PIN, HIGH);
  } else {
    // ...иначе свет не нужен — выключаем его
    digitalWrite(LED_PIN, LOW);
  }
}
