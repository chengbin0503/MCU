#include <Arduino.h>

// 定义扬声器引脚
#define SPEAKER_PIN 12

// 定义音符频率
#define C4 261
#define D4 294
#define E4 329
#define F4 349
#define G4 392
#define A4 440
#define B4 493
#define C5 523

// 生日快乐歌的音符和节拍
int notes[] = {C4, C4, D4, C4, F4, E4, C4, C4, D4, C4, G4, F4, C4, C4, C5, A4, F4, E4, D4, B4, B4, A4, F4, G4, F4};
int durations[] = {500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 2000};

void setup() {
    pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
    // 播放生日快乐歌。
    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
        tone(SPEAKER_PIN, notes[i]); // 播放音符。
        delay(durations[i]); // 音符持续时间。
        noTone(SPEAKER_PIN); // 停止音符。
        delay(100); // 音符之间的短暂停顿。
    }
    delay(5000); // 完成后暂停一段时间。
}