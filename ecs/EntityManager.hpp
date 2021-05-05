#pragma once

#include "Signature.hpp"

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

template<typename ...ComponentList>
struct Entity {
    using ID = std::size_t;
    ID entityId;

    std::bitset<TypeList<ComponentList...>::size> bitset;
    bool isAlive{true};
};

template<typename ...ComponentList>
class EntityBuilder;

template<typename ...ComponentList>
class EntityManager {
private:
    using vtype = std::tuple<std::vector<ComponentList>...>;
    vtype $components;
    std::vector<Entity<ComponentList...>> $entities;

public:
    EntityManager()
    {
        std::apply([](auto&&... args) {((args.resize(1000)), ...);}, $components);
    }

    EntityBuilder<ComponentList...> createEntity()
    {
        return EntityBuilder<ComponentList...>(*this);
    }

    // std::tuple<std::vector<ComponentList>...> getComponents() const
    // {
    //     return $components;
    // }

    template<int N, typename T>
    struct VectorOfType: SameType<T,
       typename std::tuple_element<N, vtype>::type::value_type>
    { };

    template <int N, class T, class Tuple,
             bool Match = false> // this =false is only for clarity
    struct MatchingField
    {
        static std::vector<T>& get(Tuple& tp)
        {
            // The "non-matching" version
            return MatchingField<N+1, T, Tuple,
                   VectorOfType<N+1, T>::value>::get(tp);
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

    template <typename T>
    std::vector<T>& getComponent()
    {
        return MatchingField<0, T, vtype,
               VectorOfType<0, T>::value>::get($components);
    }

    // template <typename Component>
    // std::vector<Component> getComponent()
    // {
    //     return std::get<IndexOf<Component, ComponentList...>::value>($components);
    // }

    std::vector<Entity<ComponentList...>> &getEntities()
    {
        return $entities;
    }
};

template<typename ...ComponentList>
class EntityBuilder {
private:
    Entity<ComponentList...> $entity;
    EntityManager<ComponentList...> &$manager;

public:
    EntityBuilder(EntityManager<ComponentList...> &manager) : $manager(manager)
    {
        $entity.entityId = $manager.getEntities().size();
    }

    template<typename Component, typename ...Ts>
    EntityBuilder<ComponentList...> &addComponent(Ts&&... args)
    {
        auto t = Component(std::forward<Ts>(args)...);

        $entity.bitset[IndexOf<Component, TypeList<ComponentList...>>::value] = true;
        $manager.template getComponent<Component>()[$entity.entityId] = t;
        return *this;
    }

    void build()
    {
        $manager.getEntities().push_back($entity);
    }

    Entity<ComponentList...> &getEntity()
    {
        return $entity;
    }
};
