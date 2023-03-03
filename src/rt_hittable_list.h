//
// Created by Mith on 2023/3/3.
//

#ifndef RT_VIEWER_RT_HITTABLE_LIST_H
#define RT_VIEWER_RT_HITTABLE_LIST_H

#include "rt_hitable.h"
#include "rt_ray.h"
#include <vector>
#include <memory>

using std::shared_ptr;
using std::make_shared;

namespace rt {
    class rt_hittable_list : public rt::Hitable {
    public :
        std::vector<shared_ptr<Hitable>> objects;

        rt_hittable_list(){}
        rt_hittable_list(shared_ptr<Hitable> object) {add(object);}

        void clear(){objects.clear();}
        void add(shared_ptr<rt::Hitable> object) {objects.push_back(object);}

        virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec);
    };

    bool rt_hittable_list::hit(const Ray &r, float t_min, float t_max, HitRecord &rec){
        HitRecord temp_rec;
        bool hit_anything = false;
        auto closest_so_far = t_max;

        for(const auto &object : objects){
            if(object->hit(r, t_min, t_max, rec)){
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
}


#endif //RT_VIEWER_RT_HITTABLE_LIST_H
