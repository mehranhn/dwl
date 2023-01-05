#define PATCHALWAYSCENTER 1
#define PATCHATTACHBOTTOM 1

/* appearance */
static const int sloppyfocus        = 1;  /* focus follows mouse */
static const unsigned int borderpx  = 1;  /* border pixel of windows */
static const int lockfullscreen     = 1;  /* 1 will force focus on the fullscreen window */
static const int smartborders       = 1;
static const unsigned int gappih    = 9;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 9;       /* vert inner gap between windows */
static const unsigned int gappoh    = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int monoclegaps        = 0;        /* 1 means outer gaps in monocle layout */
static const float rootcolor[]      = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]    = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]     = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]  = {0.1, 0.1, 0.1, 1.0};

static const Rule rules[] = {
	/* id                app_id           title   tags    mask   isfloating    monitor x,y,w,h               cmd */
 	/* examples:
	{ "Gimp",     NULL,       0,            1,           -1, 	0,0,500,400 },
	{ "firefox",  NULL,       1 << 8,       0,           -1, 	200,100,0,0 },
	/* x, y, width, heigh are floating only
	* When x or y == 0 the client is placed at the center of the screen,
	* when width or height == 0 the default size of the client is used*/
	{ "firefox",        "firefox",        NULL,       1 << 1,       0,           -1, 	    0,0,0,0,              {"firefox", NULL} },
	{ "librewolf",      "LibreWolf",      NULL,       1 << 1,       0,           -1,        50,50,500,500,        {"librewolf", NULL} },
	{ "chromium",       "chromium",       NULL,       1 << 1,       0,           -1,        50,50,500,500,        {"chromium", "--ozone-platform-hint=auto", NULL} },
	{ "freetube",       "FreeTube",       NULL,       1 << 1,       0,           -1,        50,50,500,500,        {NULL} },
	{ "mranger",        "Mranger",        NULL,       1 << 2,       0,           -1,        50,50,500,500,        {"footclient", "-a", "Mranger", "-T", "ranger", "-L", "ranger", NULL} },
	{ "mlf",            "Mlf",            NULL,       1 << 2,       0,           -1,        50,50,500,500,        {"footclient", "-a", "Mlf", "-T", "lf", "-L", "lf", NULL} },
	{ "mpv",            "mpv",            NULL,       1 << 2,       0,           -1,        50,50,500,500,        {NULL} },
	{ "nuclear",        "nuclear",        NULL,       1 << 2,       0,           -1,        50,50,500,500,        {"flatpak", "run", "org.js.nuclear.Nuclear", "--enable-features=UseOzonePlatform", "--ozone-platform=wayland", NULL} },
	{ "code-oss",       "code-oss",       NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"code", "--enable-features=UseOzonePlatform", "--ozone-platform=wayland", NULL} },
	{ "vscodium",       "VSCodium",       NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"vscodium", "--enable-features=UseOzonePlatform", "--ozone-platform=wayland", NULL} },
	{ "mnvim",          "Mnvim",          NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"footclient", "-a", "Mnvim", "-T", "Neovim", "-L", "tmux", "new", "-s", "nvim", "-n", "nvim", "-AD", "nvim", NULL} },
	{ "neovide",        "neovide",        NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"neovide", NULL} },
	{ "neovide-mg",     "neovide",        NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"neovide", "--multigrid", NULL} },
	{ "insomnia",       "Insomnia",       NULL,       1 << 3,       0,           -1,        50,50,500,500,        {"insomnia", "--enable-features=UseOzonePlatform", "--ozone-platform=wayland", NULL} },
	{ "virt-manager",   "Virt-manager",   NULL,       1 << 4,       0,           -1,        50,50,500,500,        {"virt-manager", NULL} },
	{ "dota2",          "dota2",          NULL,       1 << 4,       0,           -1,        50,50,500,500,        {NULL} },
	{ "wowclassic.exe", "wowclassic.exe", NULL,       1 << 4,       0,           -1,        50,50,500,500,        {NULL} },
	{ "discord",        "discord",        NULL,       1 << 5,       0,           -1,        50,50,500,500,        {NULL} },
	{ "jellyfin",       "org.jellyfin.jellyfinmediaplayer",NULL,1 << 5,0,        -1,        50,50,500,500,        {"flatpak", "run", "com.github.iwalton3.jellyfin-media-player", NULL} },
	{ "ferdium",        "ferdium",        NULL,       1 << 5,       0,           -1,        50,50,500,500,        {"ferdium", "--enable-features=UseOzonePlatform", "--ozone-platform=wayland", NULL} },
	{ "lutris",         "Lutris",         NULL,       1 << 6,       0,           -1,        50,50,500,500,        {"lutris", NULL} },
	{ "steam",          "Steam",          NULL,       1 << 6,       0,           -1,        50,50,500,500,        {NULL} },
	{ "gimp",           "Gimp",           NULL,       1 << 7,       0,           -1,        50,50,500,500,        {"gimp", NULL} },
	{ "krita",          "krita",          NULL,       1 << 7,       0,           -1,        50,50,500,500,        {"krita", NULL} },
	{ "obs",            "obs",            NULL,       1 << 7,       0,           -1,        50,50,500,500,        {"obs", NULL} },
	{ "qbittorrent",    "qBittorrent",    NULL,       1 << 8,       0,           -1,        50,50,500,500,        {"qbittorrent", NULL} },
	{ "mcmus",          "Mcmus",          NULL,       0,            1,           -1,        0,0,1820,991,         {"footclient", "-a", "Mcmus", "-T", "cmus", "-L", "cmus", NULL} },
	{ "mbtop",          "Mbtop",          NULL,       0,            1,           -1,        0,0,1820,991,         {"footclient", "-a", "Mbtop", "-T", "btop", "-L", "btop", "-p", "0", NULL} },
	{ "mpacmixer",      "Mpacmixer",      NULL,       0,            1,           -1,        1413,473,500,600,     {"footclient", "-a", "Mpacmixer", "-T", "pacmixer", "-L", "pacmixer",  NULL} },
	{ "pavucontrol",    "pavucontrol",    NULL,       0,            1,           -1,        1413,473,500,600,     {"pavucontrol", "-t", "4", NULL} },
};

static ToggleProc toggleprocs[] = {
	/* id               autosatrt   signal       notification ID  notification title     notification icon    cmd           not my real location                      0 */
	{ "gammastep",      1,          SIGTERM,     "8001",          "Blue Light Filter",   "eye-solid",         {"gammastep", "-l", "36.51212:51.1251775", "-r", NULL}, 0},
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* pointer constraints */
static const int allow_constrain      = 1;

/* tagging */
static const TagData tags[] = {
	/* symbol   layout             mfact     nmaster */
    { "",      &layouts[0],       0.55f,    1, },
    { "",      &layouts[2],       0.55f,    1, },
    { "",      &layouts[0],       0.55f,    1, },
    { "",      &layouts[2],       0.55f,    1, },
    { "",      &layouts[0],       0.55f,    1, },
    { "",      &layouts[2],       0.55f,    1, },
    { "",      &layouts[0],       0.75f,    1, },
    { "",      &layouts[0],       0.55f,    1, },
    { "",      &layouts[0],       0.55f,    1, },
};

/* monitors
 * The order in which monitors are defined determines their position.
 * Non-configured monitors are always added to the left. */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect x y resx resy rate adaptive custom*/
	/* example of a HiDPI laptop monitor at 120Hz:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, 0, 0, 0, 0, 120.000, 1, 0},
	*/
	/* defaults */
	{ NULL,       0.55, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL, 0, 0, 0, 0, 60.0, 0, 0},
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.model = "pc104",
	.layout = "us,ir,us",
	.variant = "colemak,,",
	.options = "caps:backspace,grp:alt_shift_toggle",
};

static const struct xkb_rule_names xkb_rules_gamemod = {
	.model = "pc104",
	.layout = "us",
	.variant = "colemak",
	.options = "caps:backspace",
};

static const int repeat_rate = 25;
static const int repeat_delay = 300;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE       
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS       
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER 
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* Autostart */
static const char *const autostart[] = {
	"swayidle", NULL,
	"lf", "-server", NULL,
	"dbus-update-activation-environment", "--systemd", "WAYLAND_DISPLAY", "XDG_CURRENT_DESKTOP", NULL,
	"systemctl", "--user", "import-environment", "WAYLAND_DISPLAY", "XDG_CURRENT_DESKTOP", NULL,
	"/usr/lib/xdg-desktop-portal", "-r", NULL,
	"dunst", "~/.config/dunst/dunstrc", NULL,
	"swaybg", "-i", "/usr/share/backgrounds/wallpapers/wallpaper_7.jpg", "-m", "fill", "-o", "*", NULL,
	"udiskie", NULL,
	// "kdeconnect-cli", "--refresh", NULL,
	// "lxqt-policykit-agent", NULL,
	"/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL,
	"foot", "--server", NULL,
	// "nm-applet", NULL,
	// "blueman-applet", NULL,
	// "asusctl", "profile", "-P", "Quiet", NULL,
	"import-gsettings", NULL,
	NULL /* terminate */
};

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, KEY,            tag,             {.ui = 1 << TAG} }
	// { MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	// { MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,KEY,toggletag,  {.ui = 1 << TAG} }
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "footclient", NULL };
// static const char *menucmd[] = { "bemenu-run", NULL };

#include "keys.h"
static const Key keys[] = {
	/* modifier                                          key                          function                argument */
	// { WLR_MODIFIER_ALT,                                  Key_space,                   spawnnotgamemode,       {.v = menucmd} },
	{ MODKEY,                                            Key_q,                       spawn,                  {.v = termcmd} },
	{ MODKEY,                                            Key_j,                       focusstack,             {.i = +1} },
	{ MODKEY,                                            Key_k,                       focusstack,             {.i = -1} },
	{ MODKEY,                                            Key_a,                       focusstack,             {.i = +1} },
	{ MODKEY,                                            Key_s,                       focusstack,             {.i = -1} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_j,                       pushdown,               {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_k,                       pushup,                 {0} },
	{ MODKEY,                                            Key_h,                       setmfact,               {.f = -0.05} },
	{ MODKEY,                                            Key_l,                       setmfact,               {.f = +0.05} },
	{ MODKEY,                                            Key_d,                       incnmaster,             {.i = +1} },
	{ MODKEY,                                            Key_f,                       incnmaster,             {.i = -1} },
	{ MODKEY,                                            Key_Return,                  zoom,                   {0} },
	{ MODKEY,                                            Key_Tab,                     view,                   {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_c,                       killclient,             {0} },
	{ MODKEY,                                            Key_t,                       setlayout,              {.v = &layouts[0]} },
	// { MODKEY,                                            Key_f,                       setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                                            Key_r,                       setlayout,              {.v = &layouts[2]} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_f,                       togglefloating,         {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_a,                       togglefloating,         {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_e,                       togglefullscreen,       {0} },
	// { MODKEY,                                            Key_0,                       view,                   {.ui = ~0} },
	// { MODKEY|WLR_MODIFIER_SHIFT,                         Key_0,                       tag,                    {.ui = ~0} },
	// { MODKEY,                                            Key_comma,                   focusmon,               {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                                            Key_w,                       focusmon,               {.i = WLR_DIRECTION_RIGHT} },
	// { MODKEY|WLR_MODIFIER_SHIFT,                         Key_comma,                   tagmon,                 {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT,                         Key_w,                       tagmon,                 {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT|WLR_MODIFIER_CTRL,       Key_backslash,               togglegamemod,          {0} },
	TAGKEYS(                                             Key_1,                       0),
	TAGKEYS(                                             Key_2,                       1),
	TAGKEYS(                                             Key_3,                       2),
	TAGKEYS(                                             Key_4,                       3),
	TAGKEYS(                                             Key_5,                       4),
	TAGKEYS(                                             Key_6,                       5),
	TAGKEYS(                                             Key_7,                       6),
	TAGKEYS(                                             Key_8,                       7),
	TAGKEYS(                                             Key_9,                       8),
	{ MODKEY|WLR_MODIFIER_SHIFT|WLR_MODIFIER_CTRL,       Key_q,                       quit,                   {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,                Key_BackSpace,               quit,                   {0} },
#define CHVT(KEY,n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT, KEY, chvt, {.ui = (n)} }
	CHVT(Key_F1, 1), CHVT(Key_F2,  2),  CHVT(Key_F3,  3),  CHVT(Key_F4,  4),
	CHVT(Key_F5, 5), CHVT(Key_F6,  6),  CHVT(Key_F7,  7),  CHVT(Key_F8,  8),
	CHVT(Key_F9, 9), CHVT(Key_F10, 10), CHVT(Key_F11, 11), CHVT(Key_F12, 12),
    /* window rules */
    { MODKEY,                       Key_b,                     spawnorfocus,             {.v = "librewolf"} },
    { MODKEY|WLR_MODIFIER_SHIFT,    Key_b,                     spawnorfocus,             {.v = "chromium"} },
    { MODKEY,                       Key_e,                     spawnorfocus,             {.v = "mlf"} },
    { MODKEY,                       Key_c,                     spawnorfocus,             {.v = "mnvim"} },
    { MODKEY,                       Key_v,                     spawnorfocus,             {.v = "mcmus"} },
    { MODKEY|WLR_MODIFIER_SHIFT,    Key_v,                     spawnorfocus,             {.v = "mpv"} },
    { MODKEY|WLR_MODIFIER_SHIFT,    Key_m,                     spawnorfocus,             {.v = "nuclear"} },
    { MODKEY|WLR_MODIFIER_SHIFT,    Key_p,                     spawnorfocus,             {.v = "mbtop"} },
    { MODKEY|WLR_MODIFIER_SHIFT,    Key_o,                     spawnorfocus,             {.v = "pavucontrol"} },
	/* toggleprocs */
	{ MODKEY|WLR_MODIFIER_SHIFT,    Key_bracketright,          toggleproccmd,            {.v = "gammastep"} },
	/* general tasks */
	{ MODKEY|WLR_MODIFIER_ALT,      Key_space,                 spawnnotgamemode,         {.v = (char *[]){"mcontrol", "menu_y", NULL}} },
	{ WLR_MODIFIER_CTRL,            Key_space,                 spawnnotgamemode,         {.v = (char *[]){"mcontrol", "menu_path", NULL}} },
	{ WLR_MODIFIER_ALT,             Key_space,                 spawnnotgamemode,         {.v = (char *[]){"mcontrol", "menu_desktop", NULL}} },
	{ MODKEY|WLR_MODIFIER_SHIFT,    Key_q,                     spawn,                    {.v = (char *[]){"mcontrol", "menu_shutdown", NULL}} },
	{ MODKEY|WLR_MODIFIER_SHIFT,    Key_l,                     spawn,                    {.v = (char *[]){"mcontrol", "ylock", NULL}} },
	// { MODKEY|ShiftMask,             21, /* equal */            spawn,                    {.v = (char *[]){"mcontrol", "xlock_enable", NULL}} },
	// { MODKEY|ShiftMask,             20, /* minus */            spawn,                    {.v = (char *[]){"mcontrol", "xlock_disable", NULL}} },
	{ MODKEY|WLR_MODIFIER_SHIFT,    Key_slash,                 spawn,                    {.v = (char *[]){"mcontrol", "do_not_disturbe", NULL}} },
	{ 0,                            Key_XF86AudioLowerVolume,  spawn,                    {.v = (char *[]){"mcontrol", "pa_vol_add", "-0.05", "1.0", NULL}} },
	{ 0,                            Key_XF86AudioRaiseVolume,  spawn,                    {.v = (char *[]){"mcontrol", "pa_vol_add", "+0.05", "1.0", NULL}} },
	{ 0,                            Key_XF86AudioMute,         spawn,                    {.v = (char *[]){"mcontrol", "pa_vol_toggle", NULL}} },
	{ MODKEY,                       Key_XF86AudioLowerVolume,  spawn,                    {.v = (char *[]){"mcontrol", "pa_mic_add", "-0.05", "1.0", NULL}} },
	{ MODKEY,                       Key_XF86AudioRaiseVolume,  spawn,                    {.v = (char *[]){"mcontrol", "pa_mic_add", "+0.05", "1.0", NULL}} },
	{ MODKEY,                       Key_XF86AudioMute,         spawn,                    {.v = (char *[]){"mcontrol", "pa_mic_toggle", NULL}} },
	{ MODKEY,                       Key_F1,                    spawn,                    {.v = (char *[]){"mcontrol", "pa_mic_toggle", NULL}} },
	{ MODKEY|WLR_MODIFIER_SHIFT,    Key_s,                     spawn,                    {.v = (char *[]){"mcontrol", "yscreenshot_clipboard_selection", NULL}} },
	{ MODKEY|WLR_MODIFIER_SHIFT|WLR_MODIFIER_CTRL, Key_s,      spawn,                    {.v = (char *[]){"mcontrol", "yscreenshot_file_selection", NULL}} },
	{ 0,                            Key_Print,                 spawn,                    {.v = (char *[]){"mcontrol", "yscreenshot_clipboard", NULL}} },
	{ WLR_MODIFIER_SHIFT,           Key_Print,                 spawn,                    {.v = (char *[]){"mcontrol", "yscreenshot_file", NULL}} },
	{ 0,                            Key_XF86AudioPrev,         spawn,                    {.v = (char *[]){"mcontrol", "player_prev", NULL}} },
	{ 0,                            Key_XF86AudioPlay,         spawn,                    {.v = (char *[]){"mcontrol", "player_play_pause", NULL}} },
	{ 0,                            Key_XF86AudioNext,         spawn,                    {.v = (char *[]){"mcontrol", "player_next", NULL}} },
	{ WLR_MODIFIER_SHIFT,           Key_XF86AudioPrev,         spawn,                    {.v = (char *[]){"mcontrol", "player_prev_selective", NULL}} },
	{ WLR_MODIFIER_SHIFT,           Key_XF86AudioPlay,         spawn,                    {.v = (char *[]){"mcontrol", "player_play_pause_selective", NULL}} },
	{ WLR_MODIFIER_SHIFT,           Key_XF86AudioNext,         spawn,                    {.v = (char *[]){"mcontrol", "player_next_selective", NULL}} },
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
