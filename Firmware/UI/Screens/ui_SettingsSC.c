// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"
extern uint16_t brightness_level;

void ui_SettingsSC_screen_init(void)
{
    ui_SettingsSC = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_SettingsSC, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc3 = lv_arc_create(ui_SettingsSC);
    lv_obj_set_width(ui_Arc3, 240);
    lv_obj_set_height(ui_Arc3, 240);
    lv_obj_set_align(ui_Arc3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Arc3, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_arc_set_value(ui_Arc3, brightness_level);
    lv_arc_set_bg_angles(ui_Arc3, 160, 20);
    lv_obj_set_style_arc_color(ui_Arc3, lv_color_hex(0x2E5685), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc3, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc3, lv_color_hex(0x30A0F5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc3, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc3, lv_color_hex(0x31A1F6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc3, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_SettingsSC);
    lv_obj_set_width(ui_Button4, 232);
    lv_obj_set_height(ui_Button4, 117);
    lv_obj_set_x(ui_Button4, 0);
    lv_obj_set_y(ui_Button4, 111);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0x43875A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Button4);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, -24);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Back");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_SettingsSC);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -2);
    lv_obj_set_y(ui_Label2, -70);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Screen Timeout");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller2 = lv_roller_create(ui_SettingsSC);
    lv_roller_set_options(ui_Roller2,
                          "          15 seconds        \n          30 seconds        \n          1 minute        \n          2 minutes      \n          3 minutes          ",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_Roller2, 91);
    lv_obj_set_width(ui_Roller2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_Roller2, 0);
    lv_obj_set_y(ui_Roller2, -3);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_Roller2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller2, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Arc3, ui_event_Arc3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Roller2, ui_event_Roller2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsSC, ui_event_SettingsSC, LV_EVENT_ALL, NULL);

}
