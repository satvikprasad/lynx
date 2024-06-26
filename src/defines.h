#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef int64_t I64;
typedef int32_t I32;
typedef int16_t I16;
typedef int8_t  I8;

typedef uint64_t U64;
typedef uint32_t U32;
typedef uint16_t U16;
typedef uint8_t  U8;

typedef uint32_t B32;
typedef bool     B8;

typedef float  F32;
typedef double F64;

#define ARRAY_LEN(a) sizeof((a)) / sizeof((a)[0])
#define SAMPLE_COUNT (1 << 15)
#define RENDER_FPS 60
#define LOG_MUL 1.06f
#define START_FREQ 1.0f

#define API_URI "https://lynx-backend-satvikprasad.koyeb.app/api/v1"

#if defined(_WIN32)
// To avoid conflicting windows.h symbols with raylib, some flags are defined
// WARNING: Those flags avoid inclusion of some Win32 headers that could be
// required by user at some point and won't be included...
//-------------------------------------------------------------------------------------

// If defined, the following flags inhibit definition of the indicated items.
#define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#define NOVIRTUALKEYCODES // VK_*
#define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
#define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#define NOSYSMETRICS      // SM_*
#define NOMENUS           // MF_*
#define NOICONS           // IDI_*
#define NOKEYSTATES       // MK_*
#define NOSYSCOMMANDS     // SC_*
#define NORASTEROPS       // Binary and Tertiary raster ops
#define NOSHOWWINDOW      // SW_*
#define OEMRESOURCE       // OEM Resource values
#define NOATOM            // Atom Manager routines
#define NOCLIPBOARD       // Clipboard routines
#define NOCOLOR           // Screen colors
#define NOCTLMGR          // Control and Dialog routines
#define NODRAWTEXT        // DrawText() and DT_*
#define NOGDI             // All GDI defines and routines
#define NOKERNEL          // All KERNEL defines and routines
#define NOUSER            // All USER defines and routines
// #define NONLS             // All NLS defines and routines
#define NOMB         // MB_* and MessageBox()
#define NOMEMMGR     // GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE   // typedef METAFILEPICT
#define NOMINMAX     // Macros min(a,b) and max(a,b)
#define NOMSG        // typedef MSG and associated routines
#define NOOPENFILE   // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL     // SB_* and scrolling routines
#define NOSERVICE    // All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND      // Sound driver routines
#define NOTEXTMETRIC // typedef TEXTMETRIC and associated routines
#define NOWH         // SetWindowsHook and WH_*
#define NOWINOFFSETS // GWL_*, GCL_*, associated routines
#define NOCOMM       // COMM driver routines
#define NOKANJI      // Kanji support stuff.
#define NOHELP       // Help engine interface.
#define NOPROFILER   // Profiler interface.
#define NODEFERWINDOWPOS // DeferWindowPos routines
#define NOMCX            // Modem Configuration Extensions
#define MMNOSOUND

// Type required before windows.h inclusion
typedef struct tagMSG *LPMSG;

#include <windows.h>
#include <winsock.h>

// Type required by some unused function...
typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

#include <mmreg.h>
#include <mmsystem.h>
#include <objbase.h>

// Some required types defined for MSVC/TinyC compiler
#if defined(_MSC_VER) || defined(__TINYC__)
#include "propidl.h"
#endif
#endif
