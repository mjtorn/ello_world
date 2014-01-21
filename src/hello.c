// vim: ts=8 sw=3 sts=3 et cino=>5n-3f0^-2{2(0W1st0

/*
 * Commit the step-by-step development of hello.h at
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
   Evas_Object *win;

   // (*parent, *name, type)
   // NULL means not attaching to anything
   // "hello" the name should be unique
   win = elm_win_add(NULL, "hello", ELM_WIN_BASIC);
   elm_win_title_set(win, "Hello");
   evas_object_smart_callback_add(win, "delete,request", _cb_win_del, NULL);

   evas_object_show(win);

   elm_run();
   elm_shutdown();

   return 0;
}

ELM_MAIN()

// EOF

