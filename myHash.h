//
// Created by Sg on 17.08.2022.
//
#include <unordered_set>
#include <string>
#pragma once
using namespace std;

struct Edge {
    int from;
    int to;
    Edge() = default;
    Edge(const Edge& name)
    {
        from = name.from;
        to = name.to;
    }
    Edge(int _from, int _to):from(_from), to(_to){};

};

template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{


    template <> struct hash<Edge>
    {
        inline size_t operator()(const Edge & a) const
        {
            size_t seed = 0;
            hash_combine(seed, a.from);
            hash_combine(seed, a.to);
            return seed;
        }
    };


}

