#ifndef LAST_STAND_ENGINE_RENDERABLE3D_H
#define LAST_STAND_ENGINE_RENDERABLE3D_H

class Renderable3D
{
friend class Universe;
    Renderable3D () : x_PendingDelete(false) {}

    virtual ~Renderable3D();

    virtual void Update ( float delta ) {};

    virtual void Render () {}

    void Destroy ();

    bool IsDestroyed ();

protected:
    virtual void PreDestroy ();
private:
    bool x_PendingDelete;

};

#endif //LAST_STAND_ENGINE_RENDERABLE3D_H