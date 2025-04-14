// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"
extern uint8_t right_inj;
extern uint8_t right_total_inj;

void ui_RightSC_screen_init(void)
{
    ui_RightSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_RightSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_RightSC, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RightSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rightArc2 = lv_arc_create(ui_RightSC);
    lv_obj_set_width(ui_rightArc2, 240);
    lv_obj_set_height(ui_rightArc2, 240);
    lv_obj_set_align(ui_rightArc2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_rightArc2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_range(ui_rightArc2, 0, right_total_inj);
    lv_arc_set_bg_angles(ui_rightArc2, 340, 200);
    lv_arc_set_rotation(ui_rightArc2, 180);
    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0x2C5133), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_rightArc2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_rightArc2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_rightArc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_RIGHTlabel2 = lv_label_create(ui_RightSC);
    lv_obj_set_width(ui_RIGHTlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_RIGHTlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_RIGHTlabel2, 0);
    lv_obj_set_y(ui_RIGHTlabel2, -22);
    lv_obj_set_align(ui_RIGHTlabel2, LV_ALIGN_CENTER);
    char right[10];
    sprintf(right,"%d",right_inj);
    lv_label_set_text(ui_RIGHTlabel2, right);
    lv_obj_set_style_text_color(ui_RIGHTlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RIGHTlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RIGHTlabel2, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_RightSC);
    lv_obj_set_width(ui_Button2, 117);
    lv_obj_set_height(ui_Button2, 71);
    lv_obj_set_x(ui_Button2, 59);
    lv_obj_set_y(ui_Button2, 91);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x295583), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RIGHTlabel3 = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_RIGHTlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_RIGHTlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_RIGHTlabel3, -27);
    lv_obj_set_y(ui_RIGHTlabel3, -4);
    lv_obj_set_align(ui_RIGHTlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_RIGHTlabel3, "+");
    lv_obj_set_style_text_color(ui_RIGHTlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RIGHTlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RIGHTlabel3, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_RightSC);
    lv_obj_set_width(ui_Button3, 117);
    lv_obj_set_height(ui_Button3, 71);
    lv_obj_set_x(ui_Button3, -59);
    lv_obj_set_y(ui_Button3, 91);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x295583), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RIGHTlabel4 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_RIGHTlabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_RIGHTlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_RIGHTlabel4, 23);
    lv_obj_set_y(ui_RIGHTlabel4, -7);
    lv_obj_set_align(ui_RIGHTlabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_RIGHTlabel4, "-");
    lv_obj_set_style_text_color(ui_RIGHTlabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RIGHTlabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RIGHTlabel4, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_RightSC, ui_event_RightSC, LV_EVENT_ALL, NULL);

}
