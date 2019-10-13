// https://www.geeksforgeeks.org/builder-design-pattern/

#include<bits/stdc++.h>
using namespace std;

//product
class Plane
{
        string _plane;
        string _body;
        string _engine;
    public:
        Plane(string planeType) : _plane(planeType){}

        void setBody(string bodyType){ _body = bodyType; }

        void setEngine(string engineType){ _engine = engineType; }

        string getBody(){ return _body; }

        string getEngine(){ return _engine; }

        void show(){ cout<< "Plane Type: "   <<_plane << endl
    		             << "Body Type: "    <<_body << endl
    		             << "Engine Type: "  <<_engine << endl << endl; }
};

// Builder
class PlaneBuilder
{
    protected:
        Plane *plane;
    public:
        virtual void buildType() = 0;
        virtual void buildBody() = 0;
        virtual void buildEngine() = 0;

        Plane* getPlane(){ return plane; }
        
};

// Concreate Builder
class PropellerBuilder: public PlaneBuilder
{
    public:
        void buildType()
        { plane = new Plane("Propeller Builder"); }

        void buildBody()
        { plane->setBody("Propeller Body"); }

        void buildEngine()
        { plane->setEngine("Propeller engine"); }
};

// Concreate Builder
class JetBuilder: public PlaneBuilder
{
    public:
        void buildType()
        { plane = new Plane("Jet Builder"); }

        void buildBody()
        { plane->setBody("Jet Body"); }

        void buildEngine()
        { plane->setEngine("Jet engine"); }
};

// Director
class Director
{
        PlaneBuilder *builder;
    public:
        Plane *createPlane(PlaneBuilder *builder)
        {
            builder->buildType();
            builder->buildBody();
            builder->buildEngine();
            return builder->getPlane();
        }
};


int main()
{
    Director dir;
    PropellerBuilder propellerBuilder;
    JetBuilder jetBuilder;

    Plane *pro = dir.createPlane(&propellerBuilder);
    Plane *jet = dir.createPlane(&jetBuilder);

    pro->show();
    jet->show();

    delete pro;
    delete jet;
}