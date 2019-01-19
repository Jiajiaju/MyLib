#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <stdio.h>
#include <cmath>

#define EPSILON 0.00001

class Vector2D{
private:
public:
    float x = 0.0;
    float y = 0.0;
    
    Vector2D():x(0.0), y(0.0){}
    Vector2D(float xx, float yy):x(xx), y(yy){}
    Vector2D(const Vector2D& vector2D):x(vector2D.x), y(vector2D.y) {}
    ~Vector2D(){}

    Vector2D& operator=(const Vector2D& vector2D){
        x = vector2D.x;
        y = vector2D.y;
        return *this;
    }
    
    inline void zero(){
        x = 0.0;
        y = 0.0;
    }
    inline bool isZero() const {
        return std::abs(x - 0.0) < EPSILON && std::abs(y - 0.0) < EPSILON;
    }
    
    inline float length() const {
        return std::sqrt((x * x) + (y * y));
    }
    inline float lengthSq() const {
        return (x * x) + (y * y);
    }
    
    inline void normalize(){
        float selfLength = this->length();
        x = x / selfLength;
        y = y / selfLength;
    }
    
    inline Vector2D perp() const {
        return Vector2D(y, -x);
    }
    
    inline void truncate(float maxLength){
        float ratio = std::sqrt((maxLength * maxLength) / (x * x + y * y));
        if (ratio < 1){
            x *= ratio;
            y *= ratio;
        }
    }
    
    inline float distance(const Vector2D& vector2D) const {
        return std::sqrt((x - vector2D.x) * (x - vector2D.x) + (y - vector2D.y) * (y - vector2D.y));
    }
    inline float distanceSq(const Vector2D& vector2D) const {
        return (x - vector2D.x) * (x - vector2D.x) + (y - vector2D.y) * (y - vector2D.y);
    }
    
    inline float angle(const Vector2D& vector2D) const {
//        float angle1 = std::atan2(y, x);
//        float angle2 = std::atan2(vector2D.y, vector2D.x);
//        return angle1 - angle2;
        float sin = x * vector2D.y - vector2D.x * y;
        float cos = x * vector2D.x + y * vector2D.y;
        return std::atan2(sin, cos);
    }
    
    inline Vector2D getReverse() const {
        Vector2D result = Vector2D(-x, -y);
        return result;
    }
    
    inline const Vector2D& operator+=(const Vector2D& vector2D){
        x += vector2D.x;
        y += vector2D.y;
        return *this;
    }
    inline const Vector2D& operator-=(const Vector2D& vector2D){
        x -= vector2D.x;
        y -= vector2D.y;
        return *this;
    }
    inline const Vector2D& operator*=(float number){
        x *= number;
        y *= number;
        return *this;
    }
    inline const Vector2D& operator/=(float number){
        x /= number;
        y /= number;
        return *this;
    }
    inline bool operator==(const Vector2D& vector2D) const {
        return (std::abs(x - vector2D.x) < EPSILON) && (std::abs(y - vector2D.y) < EPSILON);
    }
    inline bool operator!=(const Vector2D& vector2D) const {
        return (std::abs(x - vector2D.x) >= EPSILON) || (std::abs(y - vector2D.y) >= EPSILON);
    }
    
    inline Vector2D operator+(const Vector2D& vector2D) const {
        Vector2D result = Vector2D(x + vector2D.x, y + vector2D.y);
        return result;
    }
    inline Vector2D operator-(const Vector2D& vector2D) const {
        Vector2D result = Vector2D(x - vector2D.x, y - vector2D.y);
        return result;
    }
    inline float operator*(const Vector2D& vector2D) const {
        return x * vector2D.x + y * vector2D.y;
    }
    inline Vector2D operator*(float number) const {
        Vector2D result = Vector2D(x * number, y * number);
        return result;
    }
    inline Vector2D operator/(float number) const {
        Vector2D result = Vector2D(x / number, y / number);
        return result;
    }
    
};

#endif /* Vector2D_hpp */
