#include <SimpleSDAudio.h>

int trigger = 7;

void setup() {
  Serial.begin(9200);
  pinMode(trigger, INPUT);

  SdPlay.setSDCSPin(4); // sd card cs pin
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  {
    while (1);
  }
  if (!SdPlay.setFile("waage2.wav"))
  { while (1);
  }
}

void loop(void) {
  if (digitalRead(trigger) == true) {
    delay(5000);
    SdPlay.play();
    Serial.println("Music is playing.");
    while (!SdPlay.isStopped()) {
      ;
    }
  }
}
