#include <iostream>
#include <list>

struct vec3
{
    float x;
    float y;
    float z;
};

struct AudioLoader
{
    AudioLoader(){};
};



struct CubeRenderer
{
    CubeRenderer(){};
    unsigned int RequestVAO();
};
class BatchBank
{
public:
    BatchBank(){};
    ~BatchBank(){};
    AudioLoader aud_loader;
    CubeRenderer cubeRenderer;
};

class Component
        {
        public:
            Component();
            virtual ~Component(){};
        };

class Object
{
    public:
    Object()= default;
    Component* hookComponent(Component* toHook);
    void unhookComponent(Component* unhook);
    virtual ~Object()= default;
    std::list<Component> m_compnents;
};

class DynamicMove : public Component
{
public:
    DynamicMove(){};
    ~DynamicMove(){};
    vec3 position;
    void moveBy(vec3 tomove){};
    void setPosition(vec3 newPos){};
    vec3 getPosition(){};
};

class Hitbox : public Component
{
public:
    Hitbox(){};
    ~Hitbox(){};
    bool collision(Hitbox& otherHitbox);
    bool collision(vec3 otherPoint);
};

class SimpleAudio : public Component
{
public:
    SimpleAudio* initAudio(BatchBank* t){ return this;};
    SimpleAudio(){};
    ~SimpleAudio(){};
    void setBuffer(){};
    void play();
    void stop();
};

class Player : public Object
{
public:
    Player(BatchBank* t){

        aud.initAudio(t);
    };
    ~Player(){};

    SimpleAudio aud;
    DynamicMove move;
    Hitbox box;
};


int main() {
    BatchBank bank;
    Player g(&bank);
    Player f(&bank);
    g.box.collision(f.box);


    return 0;
}
