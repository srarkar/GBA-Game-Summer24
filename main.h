#ifndef MAIN_H
#define MAIN_H
#include "gba.h"

#define TIME_LIMIT 30
#define BORDER 2
#define TIMER_HEIGHT 20
#define FOREST_GREEN COLOR(5, 22, 15)
#define SEGMENT_SIZE 3 // width/height of snake segment
#define SNAKE_LENGTH 6 // num of segments
#define APPLE_SIZE 9 // width/height of apples
#define NUM_APPLES 3
#define NUM_VINES (2 * (NUM_APPLES - 1))
#define VINE_WIDTH 5
#define VINE_HEIGHT 26

enum gba_state {
  START,
  PLAY,
  WIN,
  LOSE,
};

typedef struct snakeSegment {
    int x;
    int y;
    u16 color;
} snakeSegment_t;



typedef struct snake {
    int length;
    int velX;
    int velY;
    int oldTX;
    int oldTY;
    snakeSegment_t segs[SNAKE_LENGTH];
} snake_t;



typedef struct apple {
  int x;
  int y;
  int eaten;
  int deleted; 
} apple_t;

typedef struct vine {
  int x;
  int y;
} vine_t;

typedef struct Game {
  enum gba_state state;
  int timer;
  char timerStr[30];
  snake_t snake;
  u32 currentButtons;
  u32 previousButtons;
  apple_t apples[NUM_APPLES];
  int eaten_counter;
  vine_t vines[NUM_VINES];
} Game_t;
#endif
