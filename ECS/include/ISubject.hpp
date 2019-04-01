#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include <list>

#include "IEvent.hpp"
#include "IObserver.hpp"

namespace ecs
{
    class ISubject
    {
        public:
            void AddObserver(IObserver* observer)
            {
                observers_.push_back(observer);
            }

            void RemoveObserver(IObserver* observer)
            {
                for(auto it = observers_.begin(); it != observers_.end(); it++)
                {
                    if(*it == observer)
                    {
                        observers_.erase(it);
                    }
                }
            }

            void RemoveAllObservers()
            {
                observers_.clear();
            }

            void Notify(IEvent* event)
            {
                for(auto obs = observers_.begin(); obs != observers_.end(); obs++)
                {
                    (*obs)->OnNotify(event);
                }
            }

        private:
            std::list<IObserver*> observers_;
    };
}

#endif // I_SUBJECT_HPP
