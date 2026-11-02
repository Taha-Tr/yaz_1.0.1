// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"

void ui_ColoSC_screen_init(void)
{
    ui_ColoSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ColoSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ColoSC, lv_color_hex(0xC5C6C5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ColoSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button1, 67);
    lv_obj_set_height(ui_Button1, 56);
    lv_obj_set_x(ui_Button1, -74);
    lv_obj_set_y(ui_Button1, -10);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFE6D19), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image6 = lv_img_create(ui_Button1);
    lv_img_set_src(ui_Image6, &ui_img_643638925);
    lv_obj_set_width(ui_Image6, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image6, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_align(ui_Image6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button9 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button9, 67);
    lv_obj_set_height(ui_Button9, 56);
    lv_obj_set_x(ui_Button9, 0);
    lv_obj_set_y(ui_Button9, -10);
    lv_obj_set_align(ui_Button9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button9, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image7 = lv_img_create(ui_Button9);
    lv_img_set_src(ui_Image7, &ui_img_643638925);
    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button10 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button10, 67);
    lv_obj_set_height(ui_Button10, 56);
    lv_obj_set_x(ui_Button10, 74);
    lv_obj_set_y(ui_Button10, -10);
    lv_obj_set_align(ui_Button10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button10, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button10, lv_color_hex(0x878787), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image8 = lv_img_create(ui_Button10);
    lv_img_set_src(ui_Image8, &ui_img_643638925);
    lv_obj_set_width(ui_Image8, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image8, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_align(ui_Image8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_ColoSC);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 0);
    lv_obj_set_y(ui_Label6, -63);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Select the color of the \nright Syringe");
    lv_obj_set_style_text_align(ui_Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftArc3 = lv_arc_create(ui_ColoSC);
    lv_obj_set_width(ui_leftArc3, 240);
    lv_obj_set_height(ui_leftArc3, 240);
    lv_obj_set_align(ui_leftArc3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_leftArc3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_leftArc3, 100);
    lv_arc_set_bg_angles(ui_leftArc3, 60, 120);
    lv_arc_set_rotation(ui_leftArc3, 180);
    lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xc5c6c5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_leftArc3, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Button11 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button11, 117);
    lv_obj_set_height(ui_Button11, 71);
    lv_obj_set_x(ui_Button11, 59);
    lv_obj_set_y(ui_Button11, 101);
    lv_obj_set_align(ui_Button11, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button11, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button11, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel2 = lv_label_create(ui_Button11);
    lv_obj_set_width(ui_leftlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel2, -27);
    lv_obj_set_y(ui_leftlabel2, -9);
    lv_obj_set_align(ui_leftlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel2, "NO");
    lv_obj_set_style_text_color(ui_leftlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button12 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button12, 117);
    lv_obj_set_height(ui_Button12, 71);
    lv_obj_set_x(ui_Button12, -59);
    lv_obj_set_y(ui_Button12, 101);
    lv_obj_set_align(ui_Button12, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button12, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button12, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button12, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel3 = lv_label_create(ui_Button12);
    lv_obj_set_width(ui_leftlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel3, 23);
    lv_obj_set_y(ui_leftlabel3, -10);
    lv_obj_set_align(ui_leftlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel3, "YES");
    lv_obj_set_style_text_color(ui_leftlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel3, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_ColoSC);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 0);
    lv_obj_set_y(ui_Label7, 41);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "Same color as the left \nSyringe ?");
    lv_obj_set_style_text_align(ui_Label7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button20 = lv_btn_create(ui_ColoSC);
    lv_obj_set_width(ui_Button20, 232);
    lv_obj_set_height(ui_Button20, 117);
    lv_obj_set_x(ui_Button20, 0);
    lv_obj_set_y(ui_Button20, 122);
    lv_obj_set_align(ui_Button20, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button20, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button20, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button20, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button20, lv_color_hex(0x43875A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button20, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_Button20);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label15, 0);
    lv_obj_set_y(ui_Label15, -29);
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "Next");
    lv_obj_set_style_text_color(ui_Label15, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label15, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button9, ui_event_Button9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button10, ui_event_Button10, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button11, ui_event_Button11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button12, ui_event_Button12, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button20, ui_event_Button20, LV_EVENT_ALL, NULL);

}
