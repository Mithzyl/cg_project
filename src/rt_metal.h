//
// Created by Mith on 2023/3/3.
//
#pragma once
#ifndef RT_VIEWER_RT_METAL_H
#define RT_VIEWER_RT_METAL_H

#include "rt_hitable.h"
#include "rt_ray.h"
#include "rt_raytracing.h"

namespace rt {
    //struct HitRecord;

    class material{
    public:
        virtual bool scatter(const rt::Ray& ray_in, const HitRecord& rec, glm::vec3& attenuation, rt::Ray& scattered) const = 0;

    };

    class lambertian : public material{
    public:
        lambertian(const glm::vec3& a) : albedo(a){}

        bool scatter(const rt::Ray& ray_in, const HitRecord& rec, glm::vec3& attenuation, rt::Ray& scattered) const;

    public:
        glm::vec3 albedo;
    };

    class metal: public material{
    public:
        glm::vec3 albedo;

    public:
        metal(const glm::vec3& a) : albedo(a) {}

        bool scatter(const rt::Ray& ray_in, const HitRecord& rec, glm::vec3& attenuation, rt::Ray& scattered) const;
    };
}

#endif //RT_VIEWER_RT_METAL_H
