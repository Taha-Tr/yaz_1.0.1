// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------2
#include "ui.h"

void ui_LevelSC_screen_init(void)
{
    ui_LevelSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LevelSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_LevelSC, lv_color_hex(0xC5C6C5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LevelSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc2 = lv_arc_create(ui_LevelSC);
    lv_obj_set_width(ui_Arc2, 240);
    lv_obj_set_height(ui_Arc2, 240);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Arc2, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_arc_set_value(ui_Arc2, 1);
    lv_arc_set_bg_angles(ui_Arc2, 160, 20);
    lv_obj_set_style_arc_color(ui_Arc2, lv_color_hex(0x6B6B6B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc2, lv_color_hex(0x387952), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc2, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc2, lv_color_hex(0x397952), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Button13 = lv_btn_create(ui_LevelSC);
    lv_obj_set_width(ui_Button13, 117);
    lv_obj_set_height(ui_Button13, 71);
    lv_obj_set_x(ui_Button13, 59);
    lv_obj_set_y(ui_Button13, 101);
    lv_obj_set_align(ui_Button13, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button13, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button13, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button13, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel4 = lv_label_create(ui_Button13);
    lv_obj_set_width(ui_leftlabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel4, -27);
    lv_obj_set_y(ui_leftlabel4, -9);
    lv_obj_set_align(ui_leftlabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel4, "NO");
    lv_obj_set_style_text_color(ui_leftlabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel4, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button14 = lv_btn_create(ui_LevelSC);
    lv_obj_set_width(ui_Button14, 117);
    lv_obj_set_height(ui_Button14, 71);
    lv_obj_set_x(ui_Button14, -59);
    lv_obj_set_y(ui_Button14, 101);
    lv_obj_set_align(ui_Button14, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button14, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button14, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button14, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button14, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel5 = lv_label_create(ui_Button14);
    lv_obj_set_width(ui_leftlabel5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel5, 23);
    lv_obj_set_y(ui_leftlabel5, -10);
    lv_obj_set_align(ui_leftlabel5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel5, "YES");
    lv_obj_set_style_text_color(ui_leftlabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel5, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_LevelSC);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 0);
    lv_obj_set_y(ui_Label8, -57);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "Set the level of the \nright Syringe ");
    lv_obj_set_style_text_align(ui_Label8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LEFTlabel3 = lv_label_create(ui_LevelSC);
    lv_obj_set_width(ui_LEFTlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LEFTlabel3, 0);
    lv_obj_set_y(ui_LEFTlabel3, -11);
    lv_obj_set_align(ui_LEFTlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LEFTlabel3, "0");
    lv_obj_set_style_text_color(ui_LEFTlabel3, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel3, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_LevelSC);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 0);
    lv_obj_set_y(ui_Label9, 41);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Same level as the left \nSyringe ?");
    lv_obj_set_style_text_align(ui_Label9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button21 = lv_btn_create(ui_LevelSC);
    lv_obj_set_width(ui_Button21, 232);
    lv_obj_set_height(ui_Button21, 117);
    lv_obj_set_x(ui_Button21, 0);
    lv_obj_set_y(ui_Button21, 122);
    lv_obj_set_align(ui_Button21, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button21, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button21, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button21, lv_color_hex(0x43875A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label16 = lv_label_create(ui_Button21);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label16, 0);
    lv_obj_set_y(ui_Label16, -29);
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "Next");
    lv_obj_set_style_text_color(ui_Label16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label16, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Arc2, ui_event_Arc2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button13, ui_event_Button13, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button14, ui_event_Button14, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button21, ui_event_Button21, LV_EVENT_ALL, NULL);

}
