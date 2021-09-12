/* eZalo.c generated by valac 0.50.9, the Vala compiler
 * generated from eZalo.vala, do not modify */

/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: 2021 HuynhAnh <anhnhps01145@gmail.com>
 */

#include <gtk/gtk.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <webkit2/webkit2.h>

#define TYPE_BROWSER (browser_get_type ())
#define BROWSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BROWSER, Browser))
#define BROWSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BROWSER, BrowserClass))
#define IS_BROWSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BROWSER))
#define IS_BROWSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BROWSER))
#define BROWSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BROWSER, BrowserClass))

typedef struct _Browser Browser;
typedef struct _BrowserClass BrowserClass;
typedef struct _BrowserPrivate BrowserPrivate;
enum  {
	BROWSER_0_PROPERTY,
	BROWSER_NUM_PROPERTIES
};
static GParamSpec* browser_properties[BROWSER_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _Browser {
	GtkWindow parent_instance;
	BrowserPrivate * priv;
};

struct _BrowserClass {
	GtkWindowClass parent_class;
};

static gpointer browser_parent_class = NULL;

GType browser_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Browser, g_object_unref)
#define BROWSER_URL "https://chat.zalo.me"
Browser* browser_new (void);
Browser* browser_construct (GType object_type);
static GtkScrolledWindow* browser_create_web_window (Browser* self);
static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender,
                                        gpointer self);
static gint browser_main (gchar** args,
                   gint args_length1);
static GType browser_get_type_once (void);

static void
_gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender,
                                   gpointer self)
{
#line 16 "../src/eZalo.vala"
	gtk_main_quit ();
#line 63 "eZalo.c"
}

Browser*
browser_construct (GType object_type)
{
	Browser * self = NULL;
	GtkScrolledWindow* _tmp0_;
	GtkScrolledWindow* _tmp1_;
#line 12 "../src/eZalo.vala"
	self = (Browser*) g_object_new (object_type, NULL);
#line 13 "../src/eZalo.vala"
	gtk_window_set_default_size ((GtkWindow*) self, 1024, 870);
#line 14 "../src/eZalo.vala"
	gtk_window_set_title ((GtkWindow*) self, "eOS Zalo Unofficial");
#line 15 "../src/eZalo.vala"
	_tmp0_ = browser_create_web_window (self);
#line 15 "../src/eZalo.vala"
	_tmp1_ = _tmp0_;
#line 15 "../src/eZalo.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp1_);
#line 15 "../src/eZalo.vala"
	_g_object_unref0 (_tmp1_);
#line 16 "../src/eZalo.vala"
	g_signal_connect ((GtkWidget*) self, "destroy", (GCallback) _gtk_main_quit_gtk_widget_destroy, NULL);
#line 12 "../src/eZalo.vala"
	return self;
#line 90 "eZalo.c"
}

Browser*
browser_new (void)
{
#line 12 "../src/eZalo.vala"
	return browser_construct (TYPE_BROWSER);
#line 98 "eZalo.c"
}

static GtkScrolledWindow*
browser_create_web_window (Browser* self)
{
	WebKitWebView* view = NULL;
	WebKitWebView* _tmp0_;
	GtkScrolledWindow* scrolled_window = NULL;
	GtkScrolledWindow* _tmp1_;
	GtkScrolledWindow* result = NULL;
#line 19 "../src/eZalo.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 20 "../src/eZalo.vala"
	_tmp0_ = (WebKitWebView*) webkit_web_view_new ();
#line 20 "../src/eZalo.vala"
	g_object_ref_sink (_tmp0_);
#line 20 "../src/eZalo.vala"
	view = _tmp0_;
#line 21 "../src/eZalo.vala"
	webkit_web_view_load_uri (view, BROWSER_URL);
#line 23 "../src/eZalo.vala"
	_tmp1_ = (GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL);
#line 23 "../src/eZalo.vala"
	g_object_ref_sink (_tmp1_);
#line 23 "../src/eZalo.vala"
	scrolled_window = _tmp1_;
#line 24 "../src/eZalo.vala"
	gtk_scrolled_window_set_policy (scrolled_window, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
#line 25 "../src/eZalo.vala"
	gtk_container_add ((GtkContainer*) scrolled_window, (GtkWidget*) view);
#line 27 "../src/eZalo.vala"
	result = scrolled_window;
#line 27 "../src/eZalo.vala"
	_g_object_unref0 (view);
#line 27 "../src/eZalo.vala"
	return result;
#line 135 "eZalo.c"
}

static gint
browser_main (gchar** args,
              gint args_length1)
{
	Browser* browser = NULL;
	Browser* _tmp0_;
	gint result = 0;
#line 31 "../src/eZalo.vala"
	gtk_init ((gint*) (&args_length1), &args);
#line 33 "../src/eZalo.vala"
	_tmp0_ = browser_new ();
#line 33 "../src/eZalo.vala"
	g_object_ref_sink (_tmp0_);
#line 33 "../src/eZalo.vala"
	browser = _tmp0_;
#line 34 "../src/eZalo.vala"
	gtk_widget_show_all ((GtkWidget*) browser);
#line 36 "../src/eZalo.vala"
	gtk_main ();
#line 38 "../src/eZalo.vala"
	result = 0;
#line 38 "../src/eZalo.vala"
	_g_object_unref0 (browser);
#line 38 "../src/eZalo.vala"
	return result;
#line 163 "eZalo.c"
}

int
main (int argc,
      char ** argv)
{
#line 30 "../src/eZalo.vala"
	return browser_main (argv, argc);
#line 172 "eZalo.c"
}

static void
browser_class_init (BrowserClass * klass,
                    gpointer klass_data)
{
#line 9 "../src/eZalo.vala"
	browser_parent_class = g_type_class_peek_parent (klass);
#line 181 "eZalo.c"
}

static void
browser_instance_init (Browser * self,
                       gpointer klass)
{
}

static GType
browser_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BrowserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) browser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Browser), 0, (GInstanceInitFunc) browser_instance_init, NULL };
	GType browser_type_id;
	browser_type_id = g_type_register_static (gtk_window_get_type (), "Browser", &g_define_type_info, 0);
	return browser_type_id;
}

GType
browser_get_type (void)
{
	static volatile gsize browser_type_id__volatile = 0;
	if (g_once_init_enter (&browser_type_id__volatile)) {
		GType browser_type_id;
		browser_type_id = browser_get_type_once ();
		g_once_init_leave (&browser_type_id__volatile, browser_type_id);
	}
	return browser_type_id__volatile;
}

