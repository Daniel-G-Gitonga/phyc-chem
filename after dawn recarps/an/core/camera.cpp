#include "camera.h"

glm::mat4 blue::Camera::setUpCamera(GLFWwindow* window){
    camera = glm::lookAt(
        camera_pos,
        camera_front + camera_pos,
        world_up
    );
    return camera;
}

void blue::FollowCamera::updateFollowCamera(GLFWwindow* window){
/*(
collect initial cursor pos; initially pos x and y = 300 and 300 or wherever the center is
calculate the cursor offset in x y direction, xoffset = xpos_final - xpos_initial : : yOffset = yoffset_initial - yOffset_final
re define the cursor position with the new cursor positions
add the yaw and pitch to the the offset.(pitch = y)(yaw = x)from center
calculate the directions
)*/
glfwGetCursorPos(window, &x_pos_c, &y_pos_c);

if(first_c){
    x_pos_c = (300.0);
    y_pos_c = (300.0); //c = cursor
    first_c = false;
}


float sensitivity = 0.1f;
x_offset = static_cast<float>(x_pos_n) - static_cast<float>(x_pos_c);
y_offset = static_cast<float>(y_pos_c) - static_cast<float>(y_pos_n);//n = new cursor position
x_pos_n = x_pos_c;
y_pos_n = y_pos_c;

yaw += sensitivity * x_offset;
pitch += sensitivity * y_offset;

glm::vec3 direction;

direction.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
direction.y = glm::sin(glm::radians(pitch));
direction.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));

camera_front = glm::normalize(direction);
}