#ifndef LAST_STAND_ENGINE_RENDERABLE_H
#define LAST_STAND_ENGINE_RENDERABLE_H

class Renderable
{
friend class Universe;
public:
    Renderable (GraphicType type) : x_PendingDelete ( false ) {}

    virtual ~Renderable () {};

    virtual void Update ( float delta ) {};

    virtual void Render () {}

    void Destroy ();

    bool IsDestroyed ();

    int GetLayer ();

    enum GraphicType
    {
        LS_3D,
        LS_2D,
    };
protected:
    virtual void PreDestroy ();
private:
    GraphicType x_GraphicType;
    bool x_PendingDelete;
    int x_2DLayer;
};

#endif //LAST_STAND_ENGINE_RENDERABLE_H
