// vim: ts=8 sw=3 sts=3 et cino=>5n-3f0^-2{2(0W1st0

/*
 * Commit the step-by-step development of hello.h at
 * https://phab.enlightenment.org/w/elementary/
 *
 */

#include <Elementary.h>

EAPI int
elm_main(int argc, char **argv)
{
   elm_run();
   elm_shutdown();

   return 0;
}

ELM_MAIN()

// EOF

