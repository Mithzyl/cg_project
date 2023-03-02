#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/component_wise.hpp>

namespace rt {

struct HitRecord {
    float t;
    glm::vec3 p;
    glm::vec3 normal;

    // front-face tracking
    bool front_face;

    // dot result should be less than 0 if the normal points outward;
    inline void set_face_normal(const Ray &r, const glm::vec3 &outward_normal){
        front_face = glm::dot(r.direction(), outward_normal);
        normal = front_face ? outward_normal :-outward_normal;
    }

};

class Hitable {
public:
    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const = 0;
};

} // namespace rt
