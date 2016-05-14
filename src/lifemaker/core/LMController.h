/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef LMCONTROLLER_H_
#define LMCONTROLLER_H_

#include "lifemaker/core/Exception.h"
#include "lifemaker/objects/Dictionary.h"
#include "lifemaker/objects/Relations.h"

namespace lifemaker
{

class LMController
{
public:
    static LMController & get_instance();

    static void delete_instance();

    virtual ~LMController();

    Dictionary::Pointer get_dictionary() const;

    Relations::Pointer get_relations() const;

    bool merge_elements(Relation * relation) const;

private:
    LMController();

    static LMController * _instance;

    Dictionary::Pointer _dictionary;

    Relations::Pointer _relations;

};

} // namespace lifemaker

#endif // LMCONTROLLER_H_
