#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>

class Vector2
{
    public:
        Vector2();
        Vector2(const Vector2&);
        Vector2(float, float);
        void Set(float, float);
        float Length();
        float LengthSq();
        void Normalize();

        virtual ~Vector2();

        float x;
        float y;

    protected:
};

#endif // VECTOR2_H
