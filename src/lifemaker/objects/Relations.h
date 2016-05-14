/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _975c1ff7_f655_4b9b_86a7_b015cf7da096
#define _975c1ff7_f655_4b9b_86a7_b015cf7da096

#include <memory>
#include <vector>

#include "Relation.h"

namespace lifemaker
{

/**
 * @brief Relations 
 */
class Relations
{
public:
    typedef Relations Self;
    typedef std::shared_ptr<Self> Pointer;
    typedef std::shared_ptr<Self const> ConstPointer;

    /// @brief Create pointer to new instance of Relations
    static Pointer New();

    /// @brief Destructor.
    virtual ~Relations();

    /**
     * @brief Return Relations's elements.
     */
    std::vector<Relation> const & get_relations() const;

    bool contains_relation(int relation_id) const;

    bool contains_relation(Relation const & relation) const;

    void insert_relation(Relation const & relation);

    void initialize();

    Relation * get_relation_from_parents(std::vector<int> const & parents) const;

private:
    /// @brief Constructor.
    Relations();

    Relations(Self const & other); // Purposely not implemented
    Self const & operator=(Self const & other); // Purposely not implemented

    /// List of elements
    std::vector<Relation> _relations;

};

} // namespace lifemaker

#endif // _975c1ff7_f655_4b9b_86a7_b015cf7da096
