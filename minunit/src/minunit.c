/*
 * Copyright (c) 2018, Romanko Mikhail
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
 
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "config.h"

int used_tests = 0;

const char *failed = "Failed";

test_callback callbacks[MAX_TESTS];
const char *callbacks_names[MAX_TESTS];
const char *callbacks_file[MAX_TESTS];

void _mu_add_test(const char *file, const char *func_name, test_callback func)
{
    if (used_tests < MAX_TESTS)
    {
        callbacks_file[used_tests] = file;
        callbacks_names[used_tests] = func_name;
        callbacks[used_tests++] = func;
    }

}

const char *mu_run()
{
    unsigned i;
    const char *p = 0;
    printf("%-16s|%-16s|%-16s\n", "File", "Test", "Result");
    printf("----------------|----------------|----------------\n");
    for (i = 0; i < used_tests; i++)
    {
        const char *result = callbacks[i]();
        printf("%-16s|%-16s|", callbacks_file[i], callbacks_names[i]);
        if (result != NULL)
        {
            puts(result);
            p = failed;
        }
        else
        {
            puts("ok");
        }
    }
    return p;
}
