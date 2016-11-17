#pragma once

#include <ostream>

namespace atod
{

class avl
{
public:
    avl();
    ~avl();

    void add ( int value );

    bool contains ( int value ) const;

    inline bool isEmpty() const
    {
        if ( root_ == nullptr )
            return true;

        return false;
    }

    void print ( std::ostream& dest ) const;

private:
    class node
    {
    public:
        node ( int value );
        ~node();

        int value_;

        node* left_;
        node* right_;
    };

    static void internalAdd ( node*& node, int value );
    static void internalPrint ( std::ostream& dest, const node* n, size_t depth );

    static size_t height ( node* n );

    node* root_;
};

}

