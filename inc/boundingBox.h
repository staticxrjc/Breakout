#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <vector2.h>
#include <memory>

class BoundingBox {
private:
    Vector2 _topLeft, _topRight, _bottomRight, _bottomLeft;

public:
    BoundingBox();
    /**
     * @define Bounding Box
     * @param tl Top Left
     * @param tr Top Right
     * @param br Bottom Right
     * @param bl Bottom Left
     */
    BoundingBox(const Vector2&,const Vector2& tr,const Vector2& br, const Vector2& bl);
    ~BoundingBox();

    /**
     * @define Updates Bounding Box
     * @param tl Top Left
     * @param tr Top Right
     * @param br Bottom Right
     * @param bl Bottom Left
     */
    void update(const Vector2&,const Vector2& tr,const Vector2& br, const Vector2& bl);

    Vector2 getTopLeft();
    Vector2 getTopRight();
    Vector2 getBottomLeft();
    Vector2 getBottomRight();
};

#endif //BOUNDINGBOX_H
