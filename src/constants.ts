
/*
 * the constants exposed by the Logitech LED SDK header file.
 * provides fancy reverse lookup for KeyNames ( KeyName.ESC -> 0x01 ; KeyName[0x01] -> 'ESC' )
 */

module constants {

    export const LED_BITMAP_WIDTH = 21
    export const LED_BITMAP_HEIGHT = 6
    export const LED_BITMAP_BYTES_PER_KEY = 4

    export const LED_BITMAP_SIZE = (LED_BITMAP_WIDTH*LED_BITMAP_HEIGHT*LED_BITMAP_BYTES_PER_KEY)

    export const LED_DURATION_INFINITE = 0

    export const DEVICETYPE_MONOCHROME_ORD = 0
    export const DEVICETYPE_RGB_ORD        = 1
    export const DEVICETYPE_PERKEY_RGB_ORD = 2

    export const DEVICETYPE_MONOCHROME = (1 << DEVICETYPE_MONOCHROME_ORD)
    export const DEVICETYPE_RGB        = (1 << DEVICETYPE_RGB_ORD)
    export const DEVICETYPE_PERKEY_RGB = (1 << DEVICETYPE_PERKEY_RGB_ORD)

    export const DEVICETYPE_ALL = (DEVICETYPE_MONOCHROME | DEVICETYPE_RGB | DEVICETYPE_PERKEY_RGB)

}

export = constants;
