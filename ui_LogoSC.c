// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"

void ui_LogoSC_screen_init(void)
{
    ui_LogoSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LogoSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image9 = lv_img_create(ui_LogoSC);
    lv_img_set_src(ui_Image9, &ui_img_logo_yaz_png);
    lv_obj_set_width(ui_Image9, LV_SIZE_CONTENT);   /// 210
    lv_obj_set_height(ui_Image9, LV_SIZE_CONTENT);    /// 126
    lv_obj_set_x(ui_Image9, 0);
    lv_obj_set_y(ui_Image9, -3);
    lv_obj_set_align(ui_Image9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Image9, 255);

    ui_Label4 = lv_label_create(ui_LogoSC);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -145);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Welcome to \nYAZ !");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0x103C52), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label4, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_LogoSC, ui_event_LogoSC, LV_EVENT_ALL, NULL);

}
