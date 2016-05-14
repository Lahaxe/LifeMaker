/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _4c87646e_bddd_4579_92fb_5d81f15c8955
#define _4c87646e_bddd_4579_92fb_5d81f15c8955

#include <string>

namespace lifemaker
{

/**
 * @brief Element 
 */
class Element
{
public:
    /// @brief Constructor.
    Element();

    /// @brief Constructor.
    Element(int id, std::string const & name = "",
            std::string const & image = "",
            std::string const & information = "", bool discovered = false);

    /// @brief Copy Constructor.
    Element(Element const& other);

    /// @brief Destructor.
    virtual ~Element();

    /// @brief Equality test
    bool operator==(Element const & other) const;

    /// @brief Difference test
    bool operator!=(Element const & other) const;

    /**
     * @brief Return element's id.
     */
    int get_id() const;

    /**
     * @brief Return element's name.
     */
    std::string get_name() const;

    /**
     * @brief Set the element's name.
     */
    void set_name(std::string const & name);

    /**
     * @brief Return element's picture filepath.
     */
    std::string get_image() const;

    /**
     * @brief Set the element's picture filepath.
     */
    void set_image(std::string const & image);

    /**
     * @brief Return element's information.
     */
    std::string get_information() const;

    /**
     * @brief Set the element's information.
     */
    void set_information(std::string const & information);

    /**
     * @brief Return true if element is discovered, false otherwise.
     */
    bool is_discovered() const;

    /**
     * @brief Set the element's discovered flag.
     */
    void set_discovered(bool discovered);

    std::string print() const;

private:
    /// Element's id
    int _id;
    /// Element's name
    std::string _name;
    /// Element's picture filepath
    std::string _image;
    /// Element's information
    std::string _information;
    /// Flag indicating if element is discovered
    bool _discovered;

};

} // namespace lifemaker

#endif // _4c87646e_bddd_4579_92fb_5d81f15c8955
