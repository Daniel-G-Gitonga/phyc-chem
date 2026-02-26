#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Lab{
public:
virtual void onUpdate(float ts) = 0;
virtual void onRender() = 0;
virtual void onEvents() = 0;

virtual ~Lab();

};

class AppLayer:public Lab{
public:
AppLayer();
~AppLayer();

void onUpdate(float ts);
void onRender();
void onEvents();


std::unique_ptr<Shader> obj_shader = std::make_unique<Shader>();
};
class OverLayLayer: public Lab{
    public:
OverLayLayer();
~OverLayLayer();

void onUpdate(float ts);
void onRender();
void onEvents();


std::unique_ptr<Shader> obj_shader = std::make_unique<Shader>();
};

/*
pass path shders and textures etc
setup pipeline for rendering
-------------------------------
layer system: on update && on render && on events(later add on)
construct
destruct

onUpdate
onRender
onEvs

transition
suspend
--------------------------------

in application<different layers can be rendered and loaded on action of active ones...>
stored in stack with size of derived class (new keyword utilized.)
pass to application using template to call the various functions for all active layers

core layers:: AppLayer && MenuLayer && OverlayLAyer
*/

