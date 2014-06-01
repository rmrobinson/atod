#pragma once

#include <ostream>

namespace atod
{

class bst
{
public:
    bst();
    ~bst();

    void add ( int value );

    bool contains ( int value ) const;

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

    static void internalPrint ( const node* n, int depth, std::ostream& dest );

    node* root_;
};

}

