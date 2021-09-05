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
#include <stdio.h>


typedef GtkApplication SpApplication;
typedef GtkApplicationClass SpApplicationClass;

GType sp_application_get_type(void);

G_DEFINE_TYPE(SpApplication, sp_application, GTK_TYPE_APPLICATION);

static int sp_application_command_line(GApplication *application, GApplicationCommandLine *command_line);
static void  sp_application_startup(GApplication *application);
GtkWidget *main_window;

static void
sp_application_init(SpApplication *app)
{
    g_set_application_name("simple gallery");

}

static void
sp_application_class_init(SpApplicationClass *klass)
{
    GApplicationClass *application_class;
    application_class = G_APPLICATION_CLASS(klass);
    application_class->command_line = sp_application_command_line;
    application_class->startup      = sp_application_startup;

}



static void
sp_application_startup(GApplication *application)
{
    G_APPLICATION_CLASS (sp_application_parent_class)->startup(application);

    main_window = gtk_application_window_new(GTK_APPLICATION(application));
    gtk_window_set_title(GTK_WINDOW(main_window), "Simple Gallery");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 300, 300);

}

static int 
sp_application_command_line(GApplication *application,
                            GApplicationCommandLine *command_line)
{
    char **argv;
    int    argc;
    gboolean directory_provided = FALSE;

    argv = g_application_command_line_get_arguments(command_line, &argc);

    if(argc == 2) // a directory was provided to open on the command line
    {
       directory_provided = TRUE; 
    }

    sp_activate_main_window(directory_provided, NULL, application);

    return 0;

}


static void
sp_activate_main_window(gboolean directory_provided,
                        char *  default_directory_name,
                        GApplication *application)
{
    gtk_widget_show_all(GTK_WIDGET(main_window));
}


GtkApplication *
sp_application_new(void)
{
    return g_object_new(sp_application_get_type(),
                        "application-id", "simple.gallery",
                        "register-session", TRUE,
                        "flags", G_APPLICATION_HANDLES_COMMAND_LINE,
                        NULL);
}


