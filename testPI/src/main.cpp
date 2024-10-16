#include <Arduino.h>

// 定义蜂鸣器引脚。
const int buzzerPin = 9;

// 定义音符频率。
int melody[] = {
  262, 262, 294, 262, 349, 330,
  262, 262, 294, 262, 392, 349,
  262, 262, 523, 440, 349, 330, 294,
  466, 466, 440, 349, 392, 349
};

// 定义每个音符的持续时间（以四分之一音符为基准）。
int noteDurations[] = {
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2
};

void setup() {
  // 初始化蜂鸣器引脚为输出模式。
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // 遍历每个音符。
  for (int thisNote = 0; thisNote < 26; thisNote++) {
    // 计算音符的持续时间。
    int noteDuration = 1000 / noteDurations[thisNote];
    // 通过 PWM 信号产生音频。
    for (long i = 0; i < noteDuration * 1000L; i += 1000000 / melody[thisNote]) {
      digitalWrite(buzzerPin, HIGH);
      delayMicroseconds(1000000 / melody[thisNote] / 2);
      digitalWrite(buzzerPin, LOW);
      delayMicroseconds(1000000 / melody[thisNote] / 2);
    }
    // 音符之间的暂停时间。
    delay(noteDuration * 0.30);
  }
  // 循环播放。
}
