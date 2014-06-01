#include "avl.hpp"

using namespace atod;

avl::avl() : root_ ( nullptr )
{
}

avl::~avl()
{
}

void avl::add ( int value )
{
    if ( isEmpty() )
    {
        root_ = new node ( value );
        return;
    }

    internalAdd ( root_, value );
}

void avl::internalAdd ( node* & n, int value )
{
    if ( n == nullptr )
    {
        n = new node ( value );
        return;
    }

    if ( value < n->value_ )
    {
        internalAdd ( n->left_, value );

        if ( height ( n->left_ ) - height ( n->right_ ) == 2 )
        {
            if ( value < n->left_->value_ )
            {
                node* promoted = n->left_;
                n->left_ = promoted->right_;

                promoted->right_ = n;
                n = promoted;
            }
            else
            {
                node* childL = n->left_;
                node* grandChildR = childL->right_;

                childL->right_ = grandChildR->left_;
                n->left_ = grandChildR->right_;
                grandChildR->left_ = childL;
                grandChildR->right_ = n;
                n = grandChildR;
            }
        }

    }
    else if ( value > n->value_ )
    {
        internalAdd ( n->right_, value );

        if ( height ( n->right_ ) - height ( n->left_ ) == 2 )
        {
            if ( value > n->right_->value_ )
            {
                node* promoted = n->right_;
                n->right_ = promoted->left_;

                promoted->left_ = n;
                n = promoted;
            }
            else
            {
                node* childR = n->right_;
                node* grandChildL = childR->left_;

                childR->left_ = grandChildL->right_;
                n->right_ = grandChildL->left_;
                grandChildL->left_ = n;
                grandChildL->right_ = childR;
                n = grandChildL;
            }
        }
    }

    // else the values are the same; don't add it again
}

size_t avl::height ( node* n )
{
    if ( n == nullptr )
        return 0;

    size_t left = height ( n->left_ );
    size_t right = height ( n->right_ );

    if ( left > right )
        return left + 1;
    else
        return right + 1;
}

bool avl::contains ( int value ) const
{
    node* curr = root_;

    while ( curr != nullptr )
    {
        if ( value < curr->value_ )
            curr = curr->left_;
        else if ( value > curr->value_ )
            curr = curr->right_;
        else
            return true;
    }

    return false;
}

void avl::print ( std::ostream& dest ) const
{
    internalPrint ( dest, root_, 0 );
}

void avl::internalPrint ( std::ostream& dest, const node* n, size_t depth )
{
    if ( n == nullptr )
        return;

    for ( size_t i = 0; i < depth; ++i )
        dest << " ";

    dest << n->value_ << std::endl;

    internalPrint ( dest, n->left_, depth + 1 );
    internalPrint ( dest, n->right_, depth + 1 );
}

avl::node::node ( int value ) : value_ ( value ),  left_ ( nullptr ), right_ ( nullptr )
{
}

avl::node::~node()
{
    if ( left_ != nullptr )
        delete left_;
    if ( right_ != nullptr )
        delete right_;
}

