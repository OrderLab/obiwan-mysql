/* Copyright (c) 2009 Sun Microsystems, Inc.
   Use is subject to license terms.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

/* 
  main() for mysqld.
  Calls mysqld_main() entry point exported by sql library.
*/
extern int mysqld_main(int argc, char **argv);

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  // This is a hack for deadlock checker waiter.
  // It must have at least one child to wait.
  if (fork() == 0) {
    while(true)
      sleep(100000000);
  }
  return mysqld_main(argc, argv);
}
