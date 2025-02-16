#define PATCHALWAYSCENTER 1
#define PATCHATTACHBOTTOM 1

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartborders              = 1;
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static const int monoclegaps               = 0;  /* 1 means outer gaps in monocle layout */
static const unsigned int borderpx         = 1;  /* border pixel of windows */
static const unsigned int gappih           = 10; /* horiz inner gap between windows */
static const unsigned int gappiv           = 10; /* vert inner gap between windows */
static const unsigned int gappoh           = 10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 10; /* vert outer gap between windows and screen edge */
static const float bordercolor[]           = COLOR(0x444444ff);
static const float focuscolor[]            = COLOR(0x005577ff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
static const char *cursortheme             = NULL; /* theme from /usr/share/cursors/xorg-x11 */
static const unsigned int cursorsize       = 24;
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0}; /* You can also use glsl colors */

/* pointer constraints */
static const int allow_constrain      = 1;

/* logging */
static int log_level = WLR_ERROR;

static const Rule rules[] = {
	/* id         app_id     title       tags mask     isfloating   monitor x  y  width heigh t*/
	/* examples:
	{ "Gimp",     NULL,       0,            1,           -1, 	0, 	 0,   500, 400 },
	{ "firefox",  NULL,       1 << 8,       0,           -1, 	200, 100, 0,   0 },
	*/
	/* x, y, width, heigh are floating only
	* When x or y == 0 the client is placed at the center of the screen,
	* when width or height == 0 the default size of the client is used*/
	{ "firefox", "firefox",  NULL,       1 << 8,       0,           -1, 	200, 100, 0,   0,     {"firefox", NULL} },
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
	{ "[D]",      deck },
};

/* tagging */
static const TagData tags[] = {
	/* symbol   layout             mfact     nmaster */
	{ &layouts[0],       0.55f,    1, },
	{ &layouts[2],       0.55f,    1, },
	{ &layouts[0],       0.55f,    1, },
	{ &layouts[2],       0.55f,    1, },
	{ &layouts[0],       0.55f,    1, },
	{ &layouts[2],       0.55f,    1, },
	{ &layouts[0],       0.75f,    1, },
	{ &layouts[0],       0.55f,    1, },
	{ &layouts[0],       0.55f,    1, },
	{ &layouts[0],       0.55f,    1, },
};

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT LENGTH(tags)

static const unsigned int swipe_min_threshold = 0;

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL   -1,  -1},
	*/
	/* defaults */
	{ NULL,       0.55, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1, -1},
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
};

static const struct xkb_rule_names xkb_rules_gamemod = {
	.options = NULL,
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

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
/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT

#define TAGKEYS(KEY,TAG) \
	{ 0,       MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ 0,       MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, KEY,            tag,             {.ui = 1 << TAG} }, \
	{ 0,       MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,KEY,toggletag,  {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "foot", NULL };
static const char *menucmd[] = { "bemenu-run", NULL };

#include "keys.h"
static const Key keys[] = {
	/* repeat  modifier                   key          function        argument */
	{ 0,       MODKEY,                    Key_p,       spawnnotgamemode,{.v = menucmd} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_Return,  spawn,          {.v = termcmd} },
	{ 0,       MODKEY,                    Key_j,       focusstack,     {.i = +1} },
	{ 0,       MODKEY,                    Key_k,       focusstack,     {.i = -1} },
	{ 0,       MODKEY,                    Key_i,       incnmaster,     {.i = +1} },
	{ 0,       MODKEY,                    Key_d,       incnmaster,     {.i = -1} },
	{ 0,       MODKEY,                    Key_h,       setmfact,       {.f = -0.05} },
	{ 0,       MODKEY,                    Key_l,       setmfact,       {.f = +0.05} },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO,  Key_h,       incgaps,        {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO,  Key_l,       incgaps,        {.i = -1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO|WLR_MODIFIER_SHIFT,   Key_h,      incogaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO|WLR_MODIFIER_SHIFT,   Key_l,      incogaps,      {.i = -1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO|WLR_MODIFIER_CTRL,    Key_h,      incigaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO|WLR_MODIFIER_CTRL,    Key_l,      incigaps,      {.i = -1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO,  Key_0,       togglegaps,     {0} },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO|WLR_MODIFIER_SHIFT,   Key_parenright,defaultgaps,{0} },
	{ 0,       MODKEY,                    Key_o,       incihgaps,      {.i = -1 } },
	{ 0,       MODKEY,                    Key_y,       incihgaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_CTRL,  Key_y,       incivgaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_CTRL,  Key_o,       incivgaps,      {.i = -1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO,  Key_y,       incohgaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_LOGO,  Key_o,       incohgaps,      {.i = -1 } },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_y,       incovgaps,      {.i = +1 } },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_o,       incovgaps,      {.i = -1 } },
	{ 0,       MODKEY,                    Key_Return,  zoom,           {0} },
	{ 0,       MODKEY,                    Key_Tab,     view,           {0} },
	{ 0,       MODKEY,                    Key_a,       shiftview,      { .i = -1 } },
	{ 0,       MODKEY,                    Key_semicolon, shiftview,    { .i = 1 } },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_c,       killclient,     {0} },
	{ 0,       MODKEY,                    Key_t,       setlayout,      {.v = &layouts[0]} },
	{ 0,       MODKEY,                    Key_f,       setlayout,      {.v = &layouts[1]} },
	{ 0,       MODKEY,                    Key_m,       setlayout,      {.v = &layouts[2]} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_d,       setlayout,      {.v = &layouts[3]} },
	{ 0,       MODKEY,                    Key_space,   setlayout,      {0} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_space,   togglefloating, {0} },
	{ 0,       MODKEY,                    Key_e,       togglefullscreen, {0} },
	{ 0,       MODKEY,                    Key_0,       view,           {.ui = ~0} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_0,       tag,            {.ui = ~0} },
	{ 0,       MODKEY,                    Key_comma,   focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ 0,       MODKEY,                    Key_period,  focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_comma,   tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_period,  tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT|WLR_MODIFIER_CTRL,Key_backslash,togglegamemod,{0} },
	TAGKEYS(                     Key_1,                       0),
	TAGKEYS(                     Key_2,                       1),
	TAGKEYS(                     Key_3,                       2),
	TAGKEYS(                     Key_4,                       3),
	TAGKEYS(                     Key_5,                       4),
	TAGKEYS(                     Key_6,                       5),
	TAGKEYS(                     Key_7,                       6),
	TAGKEYS(                     Key_8,                       7),
	TAGKEYS(                     Key_9,                       8),
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_q,       quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ 0, WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,Key_BackSpace, quit, {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(KEY,n) { 0, WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT, KEY, chvt, {.ui = (n)} }
	CHVT(Key_F1, 1), CHVT(Key_F2,  2),  CHVT(Key_F3,  3),  CHVT(Key_F4,  4),
	CHVT(Key_F5, 5), CHVT(Key_F6,  6),  CHVT(Key_F7,  7),  CHVT(Key_F8,  8),
	CHVT(Key_F9, 9), CHVT(Key_F10, 10), CHVT(Key_F11, 11), CHVT(Key_F12, 12),
	/* window rules */
	{ 0,       MODKEY,                    Key_b,       spawnorfocus,   {.v = "firefox"} },

	/* toggle procs */
	{ 0,       MODKEY|WLR_MODIFIER_SHIFT, Key_bracketright,toggleproccmd,{.v = "gammastep"} },
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

static const Gesture gestures[] = {
	// { SWIPE_LEFT,  shiftviewvisible, {.i = 1 } },
	// { SWIPE_RIGHT, shiftviewvisible, {.i = -1} },
	{ SWIPE_3_UP,    focusstack,       {.i = 1 } },
	{ SWIPE_3_DOWN,  focusstack,       {.i = -1} },
};
