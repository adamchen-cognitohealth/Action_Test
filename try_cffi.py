import time
from _lvgl import ffi, lib

# LVGL Display Init
lib.lv_port_disp_init()

# LVGL Device Init
lib.lv_port_indev_init()

# LVGL File System Init
lib.lv_port_fs_init()


## Create style for Chinese fonts
# label_style = ffi.new("lv_style_t *")
# lib.lv_style_init(label_style)
# lib.lv_style_set_text_font(label_style,LV_STATE_DEFAULT, lv_font_simsun_16_cjk)

# Custom Button
# @ffi.def_extern()
# def lv_event_cb_t_callback(obj, event):
#     lib.lv_label_set_text(p_label, b"Hello!")
#     print(event)
# p_btn1 = lib.my_btn_create(ffi.addressof(lib, "lv_event_cb_t_callback"))
# p_label = lib.my_label_create(p_btn1, b"Button")

# Main page
lib.page_menu_test()
# lib.my_lvgl_fs_test()


## Handle LitlevGL tasks (tickless mode)
#lib.demo_create();
while True:
    lib.lv_tick_inc(5)
    lib.lv_task_handler()
    time.sleep(0.005)
