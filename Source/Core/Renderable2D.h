#ifndef LAST_STAND_ENGINE_RENDERABLE_H
#define LAST_STAND_ENGINE_RENDERABLE_H

class Renderable2D
{
friend class Universe;
public:
    Renderable2D() : x_PendingDelete ( false ) {}

    virtual ~Renderable2D() {};

    virtual void Update ( float delta ) {};

    virtual void Render () {}

    void Destroy ();

    bool IsDestroyed ();

    int Get2DLayer ()
    {
        return x_2DLayer;
    }
protected:
    virtual void PreDestroy ();
private:
    bool x_PendingDelete;
    int x_2DLayer;
};

#endif //LAST_STAND_ENGINE_RENDERABLE_H
