// vim: ts=8 sw=3 sts=3 et cino=>5n-3f0^-2{2(0W1st0

/*
 * Commit the step-by-step development of dialog.c at
 * https://phab.enlightenment.org/w/elementary/
 *
 */

#include <Elementary.h>

static void
_cb_win_del(void *data, Evas_Object *obj, void *event_info)
{
   elm_exit();
}

EAPI int
elm_main(int argc, char **argv)
{
   Evas_Object *win, *bg, *box, *box0, *btn_ok, *btn_cancel, *frame, *frame0, *frame1, *label;
   const char *text = "No text provided";

   // Override with user's text if given
   if (argc > 1) text = argv[1];

   // Initialize a parentless window the basic way
   win = elm_win_add(NULL, "dialog", ELM_WIN_BASIC);
   elm_win_title_set(win, "Dialog");
   evas_object_smart_callback_add(win, "delete,request", _cb_win_del, NULL);

   // Add the bg, but this one does not get to scale
   bg = elm_bg_add(win);
   evas_object_size_hint_weight_set(bg, 0.0, 0.0);
   elm_win_resize_object_add(win, bg);
   evas_object_show(bg);

   // We want to pack our widgets in a box this time
   box = elm_box_add(win);
   // It doesn't grow either
   evas_object_size_hint_weight_set(box, 0.0, 0.0);
   elm_win_resize_object_add(win, box);
   evas_object_show(box);

   // Add also some padding
   frame = elm_frame_add(win);
   elm_object_style_set(frame, "pad_large");
   // No resize
   evas_object_size_hint_weight_set(frame, 0.0, 0.0);
   // Fill allocated region
   evas_object_size_hint_align_set(frame, -1.0, -1.0);
   elm_box_pack_end(box, frame);
   evas_object_show(frame);

   // Pack the label
   label = elm_label_add(win);
   elm_object_text_set(label, text);
   elm_object_content_set(frame, label);
   elm_box_pack_end(frame, label);
   evas_object_show(label);

   // Another frame, differently styled
   frame0 = elm_frame_add(win);
   elm_object_style_set(frame0, "outdent_bottom");
   // No resize
   evas_object_size_hint_weight_set(frame, 0.0, 0.0);
   // Fill allocated region
   evas_object_size_hint_align_set(frame, -1.0, -1.0);
   elm_box_pack_end(box, frame0);
   evas_object_show(frame0);

   // Then a frame more, medium-padded
   frame1 = elm_frame_add(win);
   elm_object_style_set(frame1, "pad_medium");
   elm_object_content_set(frame0, frame1);
   evas_object_show(frame1);

   // Horizontal box for buttons
   box0 = elm_box_add(win);
   elm_box_horizontal_set(box0, 1);
   elm_box_homogeneous_set(box0, 1);
   elm_object_content_set(frame1, box0);
   evas_object_show(box0);

   // Ok button
   btn_ok = elm_button_add(win);
   elm_object_text_set(btn_ok, "OK");
   evas_object_size_hint_weight_set(btn_ok, 1.0, 1.0);
   evas_object_size_hint_align_set(btn_ok, -1.0, -1.0);
   elm_box_pack_end(box0, btn_ok);
   evas_object_show(btn_ok);
   // TODO: functionality

   // Cancel button
   btn_cancel = elm_button_add(win);
   elm_object_text_set(btn_cancel, "Cancel");
   evas_object_size_hint_weight_set(btn_cancel, 1.0, 1.0);
   evas_object_size_hint_align_set(btn_cancel, -1.0, -1.0);
   elm_box_pack_end(box0, btn_cancel);
   evas_object_show(btn_cancel);
   // TODO: functionality

   // Showtime
   evas_object_show(win);

   elm_run();
   elm_shutdown();

   return 0;
}

ELM_MAIN()

// EOF

