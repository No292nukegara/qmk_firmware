#include "keymap_japanese.h"

//#define JP_LSFT LM(_JP_SFT, MOD_LSFT)
//#define JP_RSFT LM(_JP_SFT, MOD_RSFT)
//#define JP_SFT MO(_JP_SFT)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _US,
	_JP,
    _JP_SFT,
    _FN1
};

enum custom_keycodes {
    JP_LSFT = SAFE_RANGE,
    JP_RSFT
};