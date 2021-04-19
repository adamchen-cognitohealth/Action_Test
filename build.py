from cffi import FFI
ffibuilder = FFI()

ffibuilder.cdef("""
    void lv_port_disp_init(void);
    void lv_port_indev_init(void);
    void lv_port_fs_init(void);

    void my_lvgl_fs_test(void);

    void page_menu_test(void);

    void lv_tick_inc(uint32_t tick_period);
    void lv_task_handler(void);
""")

ffibuilder.set_source("_lvgl",
"""
    #include "lvgl/lvgl.h"
    #include "lvgl/src/edge_ui/porting/lv_port_disp.h"
    #include "lvgl/src/edge_ui/porting/lv_port_indev.h"
    #include "lvgl/src/edge_ui/porting/lv_port_fs.h"
    #include "lvgl/src/edge_ui/edge_ui.h"
""",
libraries=['lvgl'],
include_dirs=['.']
)

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
