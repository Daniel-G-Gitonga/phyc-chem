#include "Application.h"
#include "chemical_lab.h"
int main(){

    AppSetup* app_settings = new AppSetup();
    app_settings->width = 800;
    app_settings->height = 800;
    app_settings->title = "test app ";


    Application* App = new Application(app_settings);
   
    App->pushLayer<AppLayer>();
    App->pushLayer<OverLayLayer>();
    App->run();

    delete app_settings;
    delete App;
    return 1;
}