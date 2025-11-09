#include <time.h>
#include <stdlib.h>
#include <unistd.h>
/* not necessary for compiling but without vim indicates an error and that's
 * annoying */
#include <getopt.h>

#include "../libC/src/macros.h"

#include "test_gestion_cartes.h"
#include "test_players.h"

static void print_usage(const char *argv0)
{
    printf("usage: %s [-m 'module name' [-t 'test name']]\n", argv0);
}

static int get_all_tests(generic_liste_t *modules_tests)
{
    module_tests_t *module_tests;

    module_tests = RETHROW_PN(get_all_test_gestion_cartes());
    gl_add_elem_last(modules_tests, module_tests);

    module_tests = RETHROW_PN(get_all_test_players());
    gl_add_elem_last(modules_tests, module_tests);

    return 0;
}

int main(int argc, char **argv)
{
    int opt;
    generic_liste_t modules_tests;
    const char *module_name = NULL;
    const char *test_name = NULL;

    srand(time(NULL));

    while ((opt = getopt(argc, argv, "hm:t:")) != -1) {
        switch(opt) {
        case 'h':
            print_usage(argv[0]);
            return 0;

        case 'm':
            module_name = optarg;
            break;

        case 't': {
            if (module_name == NULL) {
                print_usage(argv[0]);
                return 0;
            }
            test_name = optarg;
        }
            break;

        default:
            print_usage(argv[0]);
            return 0;
        }
    }

    gl_init(&modules_tests);

    if (get_all_tests(&modules_tests) < 0) {
        logger_error("error when getting the tests callback");
    }
    run_all_modules_tests(&modules_tests, module_name, test_name);

    free_all_module_test(&modules_tests);

    return 0;
}
