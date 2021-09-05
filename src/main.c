/*
 *    This file is part of simple_gallery.
 *
 *    simple_gallery is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    simple_gallery is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with simple_gallery.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <gtk/gtk.h>
#include "sp-application.h"

GtkApplication * MainApplication;

int main(int argc, char ** argv)
{

    int status;
    MainApplication = sp_application_new();
    status = g_application_run(G_APPLICATION(MainApplication), argc, argv);
    g_object_unref(MainApplication);

    return status;

}

