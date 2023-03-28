# 1 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino"
# 2 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino" 2
# 3 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino" 2
# 4 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino" 2

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
void setup(void) {
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}
Color e1 = Color(&tcs);
void loop(void) {

    int color = e1.colorSegment();

    Serial.println(color);

    delay(100);
}
