#include "dwm.h"
#include "X11/XF86keysym.h"

/* Settings */
static const unsigned int borderpx              = 2;
static const unsigned int snap                  = 0;
static const int showbar                        = 1;
static const unsigned int systraypinning        = 0;
static const unsigned int systrayonleft         = 0;
static const unsigned int systrayspacing        = 2;
static const int systraypinningfailfirst        = 1; 
static const int showsystray                    = 1;
static const int topbar                         = 1;
static const unsigned int gappx                 = 14; 

static const char mainFont[] = "LiterationMono Nerd Font Mono:size=14";

static const char *fonts[] 	= { mainFont, "JoyPixels:size=14" };
static const float mfact        = 0.55f;
static const int nmaster        = 1;
static const int resizehints    = 1;
static const int lockfullscreen = 1;
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const char normBg[] = "#282c34";
static const char normFg[] = "#abb2bf";
static const char focBg[] = "#c678dd";
static const char focFg[] = "#ffffff";

static const char *colors[][3] = {
	{ normFg, normBg, "#282c34"},
	{ focFg, focBg, "#c678dd"},
};
static const Rule rules[] = { 
	{ "b", "ru", "h", 0, 0, 0},
};
static const Layout layouts[] = {
	{ "[T]",      tile },
	{ "[M]",      monocle },
        { "[F]",      NULL },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define ZSH(cmd) { .v = (const char *[]){"/bin/zsh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", mainFont, "-nb", normBg, "-nf", normFg, "-sb", focBg, "-sf", focFg, NULL };

#define TAGKEY(id) \
        TAGKEYS(XK_##id+1, id) 

static Key keys[] = {
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd} },
	{ MODKEY,                       XK_Return, spawn,          ZSH("$TERMINAL") },
	{ MODKEY,                       XK_e,	   spawn,          ZSH("$FILEMAN") },
	{ MODKEY,                       XK_w,      spawn,          ZSH("$BROWSER") },
        { 0,                            XK_Print,  spawn,          ZSH("~/sh/ssclipboard.sh")},
        { 0,                       XF86XK_AudioRaiseVolume,  spawn, ZSH("pamixer -i 2")},
        { 0,                       XF86XK_AudioLowerVolume,  spawn, ZSH("pamixer -d 2")},
        { 0,                       XF86XK_AudioMute,  spawn, ZSH("pamixer -t")},

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_c,      quit,           {.i=23} },
        TAGKEY(0)
        TAGKEY(1)
        TAGKEY(2)
        TAGKEY(3)
        TAGKEY(4)
        TAGKEY(5)
        TAGKEY(6)
        TAGKEY(7)
};

static Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
