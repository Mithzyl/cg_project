#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace rt {

struct RTContext {
    int width = 500;
    int height = 500;
    std::vector<glm::vec4> image;
    bool freeze = false;
    int current_frame = 0;
    int current_line = 0;
    int max_frames = 1000;
    int max_bounces = 10;  // minimum requirement because of cpu limit
    float epsilon = 2e-4f;
    glm::mat4 view = glm::mat4(1.0f);
    glm::vec3 ground_color = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 sky_color = glm::vec3(0.5f, 0.7f, 1.0f);
    bool show_normals = false;
    // Add more settings and parameters here
    // ...
};

void setupScene(RTContext &rtx, const char *mesh_filename);
void updateImage(RTContext &rtx);
void resetImage(RTContext &rtx);
void resetAccumulation(RTContext &rtx);

inline static float random() {return float(drand48());}
inline static float random(float min, float max){return min + (max-min) * float(drand48());}

inline static glm::vec3 random_vec3() {return glm::vec3(random(), random(), random());}
inline static glm::vec3 random_vec3(float min, float max){return glm::vec3(random(min, max), random(min, max), random(min, max));}

inline static glm::vec3 unit_vector(glm::vec3 vector){return vector / glm::length(vector);}

glm::vec3 random_in_unit_sphere();
glm::vec3 random_unit_vector();

bool near_zero(glm::vec3 v);

glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n);

}  // namespace rt
