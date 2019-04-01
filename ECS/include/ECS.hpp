#ifndef ECS_HPP
#define ECS_HPP

#include <memory>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

#include "EventHandler.hpp"

#include "Component.hpp"
#include "Entity.hpp"
#include "Event.hpp"
#include "IObserver.hpp"
#include "ISubject.hpp"
#include "System.hpp"

namespace ecs
{
    class ECS
    {
        public:
            ECS() 
                : componentmanager_(new ComponentManager),
                    entitymanager_(new EntityManager),
                    systemmanager_(new SystemManager),
                    eventhandler_(new EventHandler)
            {
            }

            static ECS* Get()
            {
                static ECS instance;
                return &instance;
            }

            inline ComponentManager* GetComponentManager() 
            { 
                return componentmanager_.get(); 
            }
            
            inline EntityManager* GetEntityManager() 
            { 
                return entitymanager_.get(); 
            }
            
            inline SystemManager* GetSystemManager() 
            { 
                return systemmanager_.get(); 
            }

            inline EventHandler* GetEventHandler()
            {
                return eventhandler_.get();
            }

            template<typename T, typename... ARGS>
            void SendEvent(ARGS... args)
            {
                eventhandler_->Send<T>(std::forward<ARGS>(args)...);
            }

        private:
            std::unique_ptr<ComponentManager> componentmanager_;
            std::unique_ptr<EntityManager> entitymanager_;
            std::unique_ptr<SystemManager> systemmanager_;
            std::unique_ptr<EventHandler> eventhandler_;
    };
}

#endif // ECS_HPP

