/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _9506254a_dfd3_4358_9bf8_cca1ed479d2b
#define _9506254a_dfd3_4358_9bf8_cca1ed479d2b

#include <string>
#include <vector>

namespace lifemaker
{

/**
 * @brief Relation 
 */
class Relation
{
public:
    /// @brief Constructor.
    Relation();

    /// @brief Constructor.
    Relation(int id, std::vector<int> const & parents = {},
             std::vector<int> const & children = {});

    /// @brief Copy Constructor.
    Relation(Relation const& other);

    /// @brief Destructor.
    virtual ~Relation();

    /// @brief Equality test
    bool operator==(Relation const & other) const;

    /// @brief Difference test
    bool operator!=(Relation const & other) const;

    /**
     * @brief Return Relation's id.
     */
    int get_id() const;

    /**
     * @brief Return Relation's parents.
     */
    std::vector<int> const & get_parents() const;

    /**
     * @brief Set the Relation's parents.
     */
    void set_parents(std::vector<int> const & parents);

    /**
     * @brief Return Relation's children.
     */
    std::vector<int> const & get_children() const;

    /**
     * @brief Set the Relation's children.
     */
    void set_children(std::vector<int> const & children);

    std::string print() const;

private:
    /// Relation's id
    int _id;
    /// Relation's parents
    std::vector<int> _parents;
    /// Relation's children
    std::vector<int> _children;

};

} // namespace lifemaker

#endif // _9506254a_dfd3_4358_9bf8_cca1ed479d2b
