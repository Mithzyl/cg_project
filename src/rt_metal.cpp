//
// Created by Mith on 2023/3/5.
//

#include "rt_metal.h"

namespace rt{
    bool lambertian::scatter(const rt::Ray& ray_in, const HitRecord& rec, glm::vec3& attenuation, rt::Ray& scattered)
    const {
        glm::vec3 scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (near_zero(scatter_direction))
            scatter_direction = rec.normal;

        scattered = Ray(rec.p, scatter_direction);
        attenuation = albedo;

        return true;
    };

    bool metal::scatter(const rt::Ray& ray_in, const HitRecord& rec, glm::vec3& attenuation, rt::Ray& scattered) const
    {
        glm::vec3 reflected = reflect(unit_vector(ray_in.direction()), rec.normal);
        scattered = Ray(rec.p, reflected);
        attenuation = albedo;

        return (glm::dot(scattered.direction(), rec.normal) > 0);
    }
}
