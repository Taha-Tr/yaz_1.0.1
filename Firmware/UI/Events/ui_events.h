// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void play_settings_anim(lv_event_t * e);
void control_brightness(lv_event_t * e);
void control_timeout(lv_event_t * e);
void play_right_anim(lv_event_t * e);
void inc_right(lv_event_t * e);
void dec_right(lv_event_t * e);
void play_left_anim(lv_event_t * e);
void dec_left(lv_event_t * e);
void inc_left(lv_event_t * e);
void orange_selected(lv_event_t * e);
void blue_selected(lv_event_t * e);
void grey_selected(lv_event_t * e);
void different_colors(lv_event_t * e);
void same_color(lv_event_t * e);
void get_level(lv_event_t * e);
void different_levels(lv_event_t * e);
void same_level(lv_event_t * e);
void doses_are_different(lv_event_t * e);
void same_dose(lv_event_t * e);
void inc_dose(lv_event_t * e);
void dec_dose(lv_event_t * e);
void configuration_complete(lv_event_t * e);
void play_dashboard_anim(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
