
/*
 * the constants exposed by the Logitech LED SDK header file.
 */

const LED_BITMAP_WIDTH = 21;
const LED_BITMAP_HEIGHT = 6;
const LED_BITMAP_BYTES_PER_KEY = 4;

const LED_BITMAP_SIZE = (LED_BITMAP_WIDTH * LED_BITMAP_HEIGHT * LED_BITMAP_BYTES_PER_KEY);

const LED_DURATION_INFINITE = 0;

export const Constants = {
    LED_BITMAP_WIDTH,
    LED_BITMAP_HEIGHT,
    LED_BITMAP_BYTES_PER_KEY,
    LED_BITMAP_SIZE,
    LED_DURATION_INFINITE
};
