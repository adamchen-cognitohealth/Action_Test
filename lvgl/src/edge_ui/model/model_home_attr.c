#include "model_home_attr.h"


edge_home_attr_t get_home_attr_not_on_bed(){
	edge_home_attr_t tmp_attr = {
        "Not on Bed",
        "00:12:03",
        '\0',
        GRAY_COUNTER_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_on_bed(){
	edge_home_attr_t tmp_attr = {
        "On Bed",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_onbed_blc.bin",
        NORMAL_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_immobilization(){
	edge_home_attr_t tmp_attr = {
        "Immobile",
        '\0',
        "F:/mnt/card/rgb888/mainpage_onbed_wt.bin",
        NORMAL_MODE,
        EDGE_COLOR_BLUE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_stirring(){
	edge_home_attr_t tmp_attr = {
        "Stirring",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_stirring.bin",
        NORMAL_MODE,
        EDGE_COLOR_GREEN
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_sitting_up(){
	edge_home_attr_t tmp_attr = {
        "Sitting Up",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_sittingup.bin",
        NORMAL_MODE,
        EDGE_COLOR_YELLOW
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_leaving(){
	edge_home_attr_t tmp_attr = {
        "Leaving",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_leaving.bin",
        NORMAL_MODE,
        EDGE_COLOR_RED
    };
    return tmp_attr;
}


edge_home_attr_t get_home_attr_out_of_bed(){
	edge_home_attr_t tmp_attr = {
        "Out of Bed",
        "00:12:03",
        '\0',
        COUNTER_MODE,
        EDGE_COLOR_RED
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_return(){
	edge_home_attr_t tmp_attr = get_home_attr_on_bed();
	return tmp_attr;
}

edge_home_attr_t get_home_attr_leave_too_long(){
	edge_home_attr_t tmp_attr = {
        "Leave Too Long",
        "00:12:03",
        '\0',
        COUNTER_MODE,
        EDGE_COLOR_RED
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_reposition(){
	edge_home_attr_t tmp_attr = {
        "Reposition",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_onbed_wt.bin",
        NORMAL_MODE,
        EDGE_COLOR_LIGHT_BLUE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_reposition_off(){
	edge_home_attr_t tmp_attr = get_home_attr_on_bed();
	return tmp_attr;
}

edge_home_attr_t get_home_attr_pad_disconnected(){
	edge_home_attr_t tmp_attr = {
        "Sensor Module\n Disconnected",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_warning.bin",
        ALERT_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_pad_replaced(){
	edge_home_attr_t tmp_attr = {
        "Please Replace\nSensor Module",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_warning.bin",
        ALERT_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_pad_damaged(){
	edge_home_attr_t tmp_attr = {
        "Sensor Module\nAbnormal",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_warning.bin",
        ALERT_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_res_disconnected(){
	edge_home_attr_t tmp_attr = {
        "Signal Sensor \nAbnormal",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_warning.bin",
        ALERT_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_nurse_mode_on(){
	edge_home_attr_t tmp_attr = {
        "Nurse Mode",
        '\0',
        "F:/var/code/edge_ui_control/rgb888/mainpage_nursemode.bin",
        NURSE_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}

edge_home_attr_t get_home_attr_nurse_mode_off(){
	edge_home_attr_t tmp_attr = {
        "Out of Bed",
        "00:12:03",
        '\0',
        GRAY_COUNTER_MODE,
        EDGE_COLOR_WHITE
    };
    return tmp_attr;
}


