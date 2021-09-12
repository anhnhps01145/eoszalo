/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: 2021 HuynhAnh <anhnhps01145@gmail.com>
 */
using GLib;
using Gtk;
using WebKit;

public class Browser : Window {
private const string URL = "https://chat.zalo.me";

public Browser() {
    set_default_size (1024, 870);
    this.title = "eOS Zalo Unofficial";
    this.add(this.create_web_window());
    this.destroy.connect(Gtk.main_quit);
}

private ScrolledWindow create_web_window() {
    var view = new WebView();
    view.load_uri(Browser.URL);

    var scrolled_window = new ScrolledWindow(null, null);
    scrolled_window.set_policy(PolicyType.AUTOMATIC, PolicyType.AUTOMATIC);
    scrolled_window.add(view);

    return scrolled_window;
}

public static int main(string[] args) {
    Gtk.init(ref args);

    var browser = new Browser();
    browser.show_all();

    Gtk.main();

    return 0;
}
}
