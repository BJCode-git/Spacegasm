#ifndef PHYSICS_H
#define PHYSICS_H

#include <EntityProcessingSystem.h>

namespace System
{
    class Physics : public artemis::EntityProcessingSystem
    {
        public:
            Physics();
            virtual ~Physics();
        protected:
        private:
    };
}


#endif // PHYSICS_H
