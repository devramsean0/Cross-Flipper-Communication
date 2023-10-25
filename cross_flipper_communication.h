#pragma once

#include <gui/modules/text_box.h>
#include <gui/modules/widget.h>
#include <gui/modules/submenu.h>
#include <gui/modules/text_input.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

typedef struct {
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    TextBox* text_box;
    Widget* widget;
    Submenu* submenu;
    TextInput* text_input;
    float frequency;
} App;

// Scenes
typedef enum {
    AppSceneSelectMode,
    AppSceneSettings,
    AppSceneSubGHzSelectFrequency,
    AppSceneSubGhzSelectMode,
    AppSceneSubGhzChatLog,
    AppSceneSubGHzChatBox,
    AppSceneNum
} appScene;
// Views
typedef enum { AppViewTextbox, AppViewWidget, AppViewSubmenu, AppViewTextInput } appViews;

// Custom Event Enums
typedef enum {
    AppSubGHzSelectFrequency,
    AppSelectModeSubGhz,
    AppSelectModeSettings,
    AppSubGHzSelectModeChatLog,
    AppSubGHzSelectModeWriteMessage
} AppCustomEvents;