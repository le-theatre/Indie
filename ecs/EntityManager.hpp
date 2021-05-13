#pragma once

#include "Signature.hpp"

namespace Ecs {

template <class T1, class T2>
struct SameType
{
    static const bool value = false;
};

template<class T>
struct SameType<T, T>
{
    static const bool value = true;
};

template<typename ComponentList>
struct Entity {
    using ID = std::size_t;
    ID entityId;

    std::bitset<ComponentList::size> bitset;
    bool isAlive{true};
};

template<typename ComponentList>
class EntityBuilder;

template<typename ComponentList>
class EntityManager {
public:
    using VType = typename ComponentList::Tuple;

    std::vector<VType> $components;
    std::vector<Entity<ComponentList>> $entities;

public:
    EntityManager()
    {
        $components.resize(16000);
    }

    EntityBuilder<ComponentList> createEntity()
    {
        return EntityBuilder<ComponentList>(*this);
    }

    void pushEntity(Entity<ComponentList> entity, const VType &entityComponents)
    {
        entity.entityId = $entities.size();
        $components[entity.entityId] = entityComponents;
        $entities.push_back(entity);
    }

    template<int N, typename T>
    struct VectorOfType: SameType<T, typename std::tuple_element<N, VType>::type::value_type>
    { };

    template <int N, class T, class Tuple, bool Match = false>
    struct MatchingField
    {
        static std::vector<T>& get(Tuple& tp)
        {
            return MatchingField<N+1, T, Tuple, VectorOfType<N+1, T>::value>::get(tp);
        }
    };

    template <int N, class T, class Tuple>
    struct MatchingField<N, T, Tuple, true>
    {
        static std::vector<T>& get(Tuple& tp)
        {
            return std::get<N>(tp);
        }
    };

    template<typename T>
    T &getEntityComponent(std::size_t entityid)
    {
        return std::get<IndexOf<T, ComponentList>::value>($components[entityid]);
    }

    std::vector<Entity<ComponentList>> &getEntities()
    {
        return $entities;
    }
};

template<typename ComponentList>
class EntityBuilder {
private:
    using VType = typename ComponentList::Tuple;

    Entity<ComponentList> $entity;
    EntityManager<ComponentList> &$manager;
    VType $entityComponents;

public:
    EntityBuilder(EntityManager<ComponentList> &manager) : $manager(manager) {}

    template<typename Component, typename ...Ts>
    EntityBuilder<ComponentList> &addComponent(Ts&&... args)
    {
        auto t = Component(std::forward<Ts>(args)...);

        $entity.bitset[IndexOf<Component, ComponentList>::value] = true;
        std::get<IndexOf<Component, ComponentList>::value>($entityComponents) = t;
        return *this;
    }

    void build()
    {
        $manager.pushEntity($entity, $entityComponents);
    }

    Entity<ComponentList> &getEntity()
    {
        return $entity;
    }
};

}
