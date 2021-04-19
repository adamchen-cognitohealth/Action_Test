/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "port_gpio.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void keypad_init(void);
static bool keypad_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data);
static uint8_t keypad_scan(void);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_indev_t* indev_keypad;
gpio_t gpio_back = {0}; // Pin 194, 1
gpio_t gpio_up = {0}; // Pin 145, 2
gpio_t gpio_down = {0}; // Pin 196, 3
gpio_t gpio_enter = {0}; // Pin 198, 4
// static lv_indev_state_t keypad_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /* Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    lv_indev_drv_t indev_drv;

    /*------------------
     * Keypad
     * -----------------*/

    /*Initialize your keypad or keyboard if you have*/
    keypad_init();

    /*Register a keypad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);


    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_keypad, group);` */
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
/*------------------
 * Keypad
 * -----------------*/

/* Initialize your keypad */
static void keypad_init(void)
{
    gpio_back.pin = 194;
    gpio_open(&gpio_back);
    gpio_set_direction(&gpio_back, MODE_INPUT);
    gpio_get_value(&gpio_back);

    gpio_up.pin = 145;
    gpio_open(&gpio_up);
    gpio_set_direction(&gpio_up, MODE_INPUT);
    gpio_get_value(&gpio_up);

    gpio_down.pin = 196;
    gpio_open(&gpio_down);
    gpio_set_direction(&gpio_down, MODE_INPUT);
    gpio_get_value(&gpio_down);

    gpio_enter.pin = 198;
    gpio_open(&gpio_enter);
    gpio_set_direction(&gpio_enter, MODE_INPUT);
    gpio_get_value(&gpio_enter);
}

static uint8_t keypad_scan(void) {
    static uint8_t key_released=1;
    key_released=1;

    uint8_t value_back = gpio_get_value(&gpio_back);
    uint8_t value_up = gpio_get_value(&gpio_up);
    uint8_t value_down = gpio_get_value(&gpio_down);
    uint8_t value_enter = gpio_get_value(&gpio_enter);

    if(key_released&&(value_back==0||value_up==0||value_down==0||value_enter==0))
    {
        key_released=0;
        if(value_back==0)return 1;
        else if(value_up==0)return 2;
        else if(value_down==0)return 3;
        else if(value_enter==0)return 4;
    } 
    else if(value_back==1&&value_up==1&&value_down==1&&value_enter==1) {
        key_released=1;
    }
    return 0;
}

/* Will be called by the library to read the mouse */
static bool keypad_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data)
{
    static uint8_t last_key = 0;

    
    /*Get whether the a key is pressed and save the pressed key*/
    uint8_t act_key = keypad_scan();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
        case 1:
            act_key = LV_KEY_ESC;
            break;
        case 2:
            act_key = LV_KEY_PREV;
            break;
        case 3:
            act_key = LV_KEY_NEXT;
            break;
        case 4:
            act_key = LV_KEY_ENTER;
            break;
        }

        last_key = act_key;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;

    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

lv_indev_t* get_indev(void)
{
    return indev_keypad;
}

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif