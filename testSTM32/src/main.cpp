// 包含 Arduino 库。
#include <Arduino.h>

// 定义扬声器引脚。
#define SPEAKER_PIN PA0

// 定义音符频率。
int melody[] = {
  262, 262, 294, 262, 349, 330,
  262, 262, 294, 262, 392, 349,
  262, 262, 523, 440, 349, 330, 294,
  466, 466, 440, 349, 392, 349
};

// 定义每个音符的时长。
int noteDurations[] = {
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

void setup() {
  // 初始化扬声器引脚。
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // 播放每个音符。
  for (int thisNote = 0; thisNote < 25; thisNote++) {
    // 计算音符的时长。
    int noteDuration = 1000 / noteDurations[thisNote];
    // 播放音符。
    tone(SPEAKER_PIN, melody[thisNote], noteDuration);
    // 计算暂停时间。
    int pauseBetweenNotes = noteDuration * 1.30;
    // 暂停。
    delay(pauseBetweenNotes);
    // 停止音符。
    noTone(SPEAKER_PIN);
  }
  // 暂停一段时间后重新播放。
  delay(2000);
}
