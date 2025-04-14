// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"
extern uint8_t left_inj;
extern uint8_t left_total_inj;

void ui_LeftSC_screen_init(void)
{
    ui_LeftSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LeftSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_LeftSC, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LeftSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftArc2 = lv_arc_create(ui_LeftSC);
    lv_obj_set_width(ui_leftArc2, 240);
    lv_obj_set_height(ui_leftArc2, 240);
    lv_obj_set_align(ui_leftArc2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_leftArc2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_range(ui_leftArc2, 0, left_total_inj);
    lv_arc_set_bg_angles(ui_leftArc2, 340, 200);
    lv_arc_set_rotation(ui_leftArc2, 180);
    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0x2C5133), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_leftArc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_LEFTlabel2 = lv_label_create(ui_LeftSC);
    lv_obj_set_width(ui_LEFTlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LEFTlabel2, 0);
    lv_obj_set_y(ui_LEFTlabel2, -22);
    lv_obj_set_align(ui_LEFTlabel2, LV_ALIGN_CENTER);
    char left[10];
    sprintf(left,"%d",left_inj);
    lv_label_set_text(ui_LEFTlabel2, left);
    lv_obj_set_style_text_color(ui_LEFTlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel2, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_btn_create(ui_LeftSC);
    lv_obj_set_width(ui_Button5, 117);
    lv_obj_set_height(ui_Button5, 71);
    lv_obj_set_x(ui_Button5, -59);
    lv_obj_set_y(ui_Button5, 91);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(0x295583), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel6 = lv_label_create(ui_Button5);
    lv_obj_set_width(ui_leftlabel6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel6, 23);
    lv_obj_set_y(ui_leftlabel6, -7);
    lv_obj_set_align(ui_leftlabel6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel6, "-");
    lv_obj_set_style_text_color(ui_leftlabel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel6, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_LeftSC);
    lv_obj_set_width(ui_Button6, 117);
    lv_obj_set_height(ui_Button6, 71);
    lv_obj_set_x(ui_Button6, 59);
    lv_obj_set_y(ui_Button6, 91);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x295583), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel7 = lv_label_create(ui_Button6);
    lv_obj_set_width(ui_leftlabel7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel7, -27);
    lv_obj_set_y(ui_leftlabel7, -4);
    lv_obj_set_align(ui_leftlabel7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel7, "+");
    lv_obj_set_style_text_color(ui_leftlabel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel7, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LeftSC, ui_event_LeftSC, LV_EVENT_ALL, NULL);

}
