#include "../cross_flipper_communication.h";
#include <gui/modules/submenu.h>

void app_scene_select_mode_on_enter(void* context) {
    App* app = context;
    Submenu* submenu = app->submenu;
    submenu_reset(submenu);
    submenu_set_header(submenu, "Select Mode");
    submenu_add_item(submenu, "SubGHz", AppSelectModeSubGhz, app_callbacks_select_mode_menu, app);
    submenu_add_item(
        submenu, "Settings", AppSelectModeSettings, app_callbacks_select_mode_menu, app);
    view_dispatcher_switch_to_view(app->view_dispatcher, AppViewSubmenu);
}
bool app_scene_select_mode_on_event(void* context, SceneManagerEvent event) {
    App* app = context;
    bool consumed = false;
    if(event.type == SceneManagerEventTypeCustom) {
        consumed = true;
        switch(event.event) {
        case AppSelectModeSubGhz:
            scene_manager_next_scene(app->scene_manager, AppSceneSubGHzSelectFrequency);
            break;
        case AppSelectModeSettings:
            scene_manager_next_scene(app->scene_manager, AppSceneSettings);
            break;
        }
    }
    return consumed;
};
void app_scene_select_mode_on_exit(void* context) {
    App* app = (App*)context;
    Submenu* submenu = app->submenu;
    submenu_reset(submenu);
};