#pragma once

#include "defines.h"
#include "hashmap.h"
#include "lua.h"
#include "raylib.h"

#define API_METHODS_ANIMATION                                                  \
    X(L_AnimationGetElapsed, get_elapsed)                                      \
    X(L_AddAnimation, add)                                                     \
    X(L_AnimationGetVal, get_val)                                              \
    X(L_AnimationSetVal, set_val)                                              \
    X(L_AnimationSetFinished, set_finished)                                    \
    X(L_AnimationLoad, load)

#define API_METHODS_PROCS                                                      \
    X(L_AddProcedure, add)                                                     \
    X(L_CallProcedure, call)

#define API_METHODS_RENDERER                                                   \
    X(L_DrawLinedPoly, draw_lined_poly)                                        \
    X(L_DrawCenteredText, draw_centered_text)

#define API_METHODS_PARAMS                                                     \
    X(L_AddParameter, add)                                                     \
    X(L_GetParameter, get)                                                     \
    X(L_SetParameter, set)

#define API_METHODS                                                            \
    X(L_GetMusicTimePlayed, get_music_time_played)                             \
    X(L_OnUpdate, on_update)                                                   \
    X(L_OnRender, on_render)                                                   \
    X(L_PreUpdate, pre_update)                                                 \
    X(L_PreRender, pre_render)                                                 \
    X(L_SetBgColor, set_bg_color)                                              \
    X(L_GetBgColor, get_bg_color)                                              \
    X(L_GetScreenSize, get_screen_size)                                        \
    X(L_GetSamples, get_samples)                                               \
    X(L_SmoothSignal, smooth_signal)                                           \
    X(L_BindShader, bind_shader)                                               \
    X(L_UnbindShader, unbind_shader)

#define ApiErrorFunction(L, name, error) ApiError(L, "{" #name "}" error)

typedef I32 ApiCallback;

typedef struct ApiInterface {
    struct {
        Color bg_color;
    } opt;
} ApiInterface;

typedef struct ApiShader {
    char vertex[256];
    char fragment[256];

    Shader shader;
} ApiShader;

#define MAX_API_CALLBACKS 256
typedef struct ApiData {
    lua_State   *lua;
    ApiInterface data;

    ApiCallback pre_update[MAX_API_CALLBACKS];
    U32         pre_update_count;

    ApiCallback on_update[MAX_API_CALLBACKS];
    U32         on_update_count;

    ApiCallback pre_render[MAX_API_CALLBACKS];
    U32         pre_render_count;

    ApiCallback on_render[MAX_API_CALLBACKS];
    U32         on_render_count;

    HM_Hashmap *shaders;
} ApiData;

void
ApiInitialise(const char *api_fp, void *state, ApiData *api);
void
ApiPreUpdate(ApiData *api, void *state);
void
ApiUpdate(ApiData *api, void *state);
void
ApiPreRender(ApiData *api, void *state);
void
ApiRender(ApiData *api, void *state);
void
ApiDestroy(ApiData *api);
void
ApiError(lua_State *L, const char *msg);
