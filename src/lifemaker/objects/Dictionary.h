/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _0057e650_6898_4409_9617_b48ec787f8ff
#define _0057e650_6898_4409_9617_b48ec787f8ff

#include <map>
#include <memory>

#include "Element.h"

namespace lifemaker
{

/**
 * @brief Dictionary 
 */
class Dictionary
{
public:
    typedef Dictionary Self;
    typedef std::shared_ptr<Self> Pointer;
    typedef std::shared_ptr<Self const> ConstPointer;

    /// @brief Create pointer to new instance of Dictionary
    static Pointer New();

    /// @brief Destructor.
    virtual ~Dictionary();

    /**
     * @brief Return Dictionary's elements.
     */
    std::map<int, Element> const & get_elements() const;

    bool contains_element(int element_id) const;

    void insert_element(Element const & element);

    Element const & get_element(int element_id);

    void initialize();

private:
    /// @brief Constructor.
    Dictionary();

    Dictionary(Self const & other); // Purposely not implemented
    Self const & operator=(Self const & other); // Purposely not implemented

    /// List of elements
    std::map<int, Element> _elements;

};

} // namespace lifemaker

#endif // _0057e650_6898_4409_9617_b48ec787f8ff
