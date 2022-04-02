/* Settings */
static const unsigned int borderpx              = 4;
static const unsigned int snap                  = 32;
static const int showbar                        = 1;
static const unsigned int systraypinning        = 0;
static const unsigned int systrayonleft         = 0;
static const unsigned int systrayspacing        = 2;
static const int systraypinningfailfirst        = 1; 
static const int showsystray                    = 1;
static const int topbar                         = 1;
static const unsigned int gappx                 = 14; 
static const char *fonts[]                      = { "Hurmit Nerd Font Mono:size=12" };
static const float mfact        = 0.55f;
static const int nmaster        = 1;
static const int resizehints    = 0;
static const int lockfullscreen = 0;
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };
static const char *colors[][3] = {
	/*                  fg         bg        border */
	[SchemeNorm] = { "#ebdbb2", "#282828", "#ffffff"},
	[SchemeSel]  = { "#ebdbb2", "#b16286", "#ff0000"},
};
static const Rule rules[] = { 
	{ "b", "r", "uh", 0, 0, 0},
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
static const char *sscmd[]      = { "flameshot", "gui", 0 };

static char rofimon[2] = "0";
static char *rofiruncmd[] = { "rofi", "-m", rofimon, "-show", "run", 0 };
static char *rofidruncmd[]= { "rofi", "-m", rofimon, "-show", "drun", 0 };

#define TAGKEY(id) \
        TAGKEYS(XK_##id+1, id) 

static Key keys[] = {
        { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = rofiruncmd} },
        { MODKEY,                       XK_p,      spawn,          {.v = rofidruncmd} },
	{ MODKEY,                       XK_Return, spawn,          ZSH("$TERMINAL") },
	{ MODKEY,                       XK_e,	   spawn,          ZSH("$FILEMAN") },
	{ MODKEY,                       XK_w,      spawn,           ZSH("$BROWSER") },
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
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_c,      quit,           {.i=23} },
        { 0,                            XK_Print,  spawn,          {.v = sscmd} },
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
